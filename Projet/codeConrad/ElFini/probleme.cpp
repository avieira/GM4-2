#include "probleme.h"

Probleme::Probleme(Carre *c,FormBilinR2P1 *fB,FormLinR2P1 *fL)
{
    geometrie=c;
    a=fB;
    L=fL;
}

void Probleme::genererMaillage(float h)
{
    maillage = geometrie->mailler(h);
    dimensionNeum=maillage->nombrePointsMaillage;
    dimensionDirHom=maillage->nombrePointsMaillageInterieur;
}

void Probleme::calculerMatrices()
{
    float valElemRef1[3][3],valElemRef2[3][3],valElemRefL1[3],valElemRefL2[3];
    ElementFiniR2 *elFini;
    int indRi,indRj;

    //Initialisation de la matrice de rigidité et du second membre
    matriceRigiditeNeum = new float*[dimensionNeum];
    secondMembreNeum = new float[dimensionNeum];
    for(int i=0;i<dimensionNeum;i++)
    {
        matriceRigiditeNeum[i] = new float[dimensionNeum];
        secondMembreNeum[i]=0;
        for(int j=0;j<dimensionNeum;j++)
            matriceRigiditeNeum[i][j]=0;
    }
    matriceRigiditeDirHom =new float*[dimensionDirHom];
    secondMembreDirHom = new float[dimensionDirHom];
    for(int i=0;i<dimensionDirHom;i++)
    {
        matriceRigiditeDirHom[i] = new float[dimensionDirHom];
    }

    //Initialisation des valeurs pour les éléments de références : pair et impair;
    elFini = maillage->getElementFini(1);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            valElemRef1[i][j]=a->calc(elFini,i,j);
            valElemRefL1[i]=L->calc(elFini,i); //On peut se permettre de calculer le second membre juste pour un élément de référence car le f étant constant, il n'intervient pas dans l'integrale car ne depend pas de la position, il faudrait sinon faire un changement de variable
        }
    elFini = maillage->getElementFini(2);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            valElemRef2[i][j]=a->calc(elFini,i,j);
            valElemRefL2[i]=L->calc(elFini,i); //On peut se permettre de calculer le second membre juste pour un élément de référence car le f étant constant, il n'intervient pas dans l'integrale car ne depend pas de la position, il faudrait sinon faire un changement de variable
        }

    //Boucle sur les elements finis du maillage;
    for(int k=0;k<maillage->nombreElemFin;k++)
    {
        elFini=maillage->getElementFini(k+1);
        for(int i=0;i<3;i++)
        {
            indRi=elFini->getDomaine()->getSommet(i+1)->getNumero();
            for(int j=0;j<3;j++)
            {
                indRj=elFini->getDomaine()->getSommet(j+1)->getNumero();
                if(elFini->numero % 2 == 0 )
                    matriceRigiditeNeum[indRi-1][indRj-1]+=valElemRef2[i][j];
                else
                    matriceRigiditeNeum[indRi-1][indRj-1]+=valElemRef1[i][j];
            }
            if(elFini->numero % 2 == 0 )
                secondMembreNeum[indRi-1]+=valElemRefL2[i];
            else
                secondMembreNeum[indRi-1]+=valElemRefL1[i];
        }
    }

    //Matrice pour des conditions de Dirichlet Homogene
    for(int i=0;i<dimensionDirHom;i++)
    {
        for(int j=0;j<dimensionDirHom;j++)
            matriceRigiditeDirHom[i][j]=matriceRigiditeNeum[maillage->listePointsMaillageInterieur[i]->getNumero()-1][maillage->listePointsMaillageInterieur[j]->getNumero()-1];
        secondMembreDirHom[i]=secondMembreNeum[maillage->listePointsMaillageInterieur[i]->getNumero()-1];
    }
}

void Probleme::resoudreProbleme()
{
//		 	composantesNeum=FonctionsMath::resol_ConjGrad(matriceRigiditeNeum,secondMembreNeum,dimensionNeum);
    composantesDirHom=FonctionsMath::resol_ConjGrad(matriceRigiditeDirHom,secondMembreDirHom,dimensionDirHom);
}

void Probleme::calculerSolutionPoints()
{
    int nbPoints,compt;
    float pas,**matPoints,**matRef;
    RestFctBaseR2P1 *l1,f;

    nbPoints=maillage->nombrePointsMaillage-maillage->nombrePointsMaillageInterieur;
    nbPoints=nbPoints/2+1;
    pas=maillage->getElementFini(1)->getDomaine()->getSommet(2)->getAbscisse()/2;
    matPoints= new float*[nbPoints];
    matRef= new float*[3];
    for(int i=0;i<nbPoints;i++)
    {
        matPoints[i]=new float[nbPoints];
        for(int j=0;j<nbPoints;j++)
        matPoints[i][j]=0;
    }
    for(int i=0;i<3;i++)
        matRef[i]=new float[3];

    //matrice de valeurs pour une fonction de base
    l1=(RestFctBaseR2P1 *) maillage->getElementFini(1)->getListeFonctions();
    matRef[0][0]=0;
    f=l1[1];
    matRef[0][1]=f.calc(pas,0);
    matRef[0][2]=f.calc(pas,pas);
    f=l1[2];
    matRef[1][0]=f.calc(0,pas);
    matRef[2][0]=f.calc(pas,pas);
    matRef[1][1]=1;
    f=l1[0];
    matRef[1][2]=f.calc(0,pas);
    matRef[2][1]=f.calc(pas,0);
    matRef[2][2]=0;

    //calcul de la matrice de valeurs
    for(int i=2;i<(nbPoints-1);i=i+2)
        for(int j=2;(j<nbPoints-1);j=j+2)
        {
            compt=(j-2)/2*((nbPoints-1)/2-1)+(i-2)/2; //on utilise nbPointsInt et j=y , i=x
            matPoints[i-1][j]+=matRef[0][1]*composantesDirHom[compt];
            matPoints[i-1][j+1]+=matRef[0][2]*composantesDirHom[compt];
            matPoints[i][j-1]+=matRef[1][0]*composantesDirHom[compt];
            matPoints[i][j]+=matRef[1][1]*composantesDirHom[compt];
            matPoints[i][j+1]+=matRef[1][2]*composantesDirHom[compt];
            matPoints[i+1][j-1]+=matRef[2][0]*composantesDirHom[compt];
            matPoints[i+1][j]+=matRef[2][1]*composantesDirHom[compt];
        }

    //ecriture du fichier pour gnuplot
    ofstream fichier("res");
    for(int i=0;i<nbPoints;i++)
    {
        for(int j=0;j<nbPoints;j++)
            fichier<<i*pas<<" "<<j*pas<<" "<<matPoints[i][j]<<" \n";
        fichier<<"\n";
    }
    fichier.close();


}

void Probleme::afficherSolution()
{
    cout<<"COMPOSANTES DIRICHLET HOMOGENE\n";
    cout<<"-------------------------\n";
    for(int i=0;i<dimensionDirHom;i++)
    {
        cout<<composantesDirHom[i];
        cout<<"\n";
    }
    cout<<"\n";

}

void Probleme::afficherMaillage()
{
    maillage->afficher();
}

void Probleme::afficherMatrices()
{
    cout<<"\n";
    cout<<"MATRICE RIGIDITE NEUMANN\n";
    cout<<"-------------------------\n";
    for(int i=0;i<dimensionNeum;i++)
    {
        for(int j=0;j<dimensionNeum;j++)
            cout<<matriceRigiditeNeum[i][j]<<"      ";
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"SECOND MEMBRE NEUMANN\n";
    cout<<"-------------------------\n";
    for(int i=0;i<dimensionNeum;i++)
    {
        cout<<secondMembreNeum[i];
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"MATRICE RIGIDITE DIRICHLET HOMOGENE\n";
    cout<<"-------------------------\n";
    for(int i=0;i<dimensionDirHom;i++)
    {
        for(int j=0;j<dimensionDirHom;j++)
            cout<<matriceRigiditeDirHom[i][j]<<"      ";
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"SECOND MEMBRE DIRICHLET HOMOGENE\n";
    cout<<"-------------------------\n";
    for(int i=0;i<dimensionDirHom;i++)
    {
        cout<<secondMembreDirHom[i];
        cout<<"\n";
    }
    cout<<"\n";
}
