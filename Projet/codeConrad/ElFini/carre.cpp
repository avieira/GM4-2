#include "carre.h"
#include "integer_part.c"
#include "triangle.h"
#include "restfctbaser2p1.h"

Carre::Carre(int larg,SommetR2 *p1,SommetR2 *p2,SommetR2 *p3,SommetR2 *p4):GeometrieR2()
{
    cote=larg;
    nombreSommets=4;
    listeSommets= new SommetR2*[nombreSommets];
    listeSommets[0]=p1;
    listeSommets[1]=p2;
    listeSommets[2]=p3;
    listeSommets[3]=p4;
}

MaillageR2* Carre::mailler(float h)
{
    //INITIALISATION
    SommetR2 	**listeSommets,*p1,*p2,*p3;
    ElementFiniR2 	**listeElemFin,*elFin;
    Triangle	*t;
    int 		comptSommet,comptElem;
    MaillageR2   	*m;
    RestFctBaseR2P1	lFonc[3];

    //CREATION DU PREMIER ELEMENT: EN BAS A GAUCHE
    lFonc[0].setParam(1,-1/h);
    lFonc[0].setParam(2,-1/h);
    lFonc[0].setParam(3,1);
    lFonc[1].setParam(1,1/h);
    lFonc[1].setParam(2,0);
    lFonc[1].setParam(3,0);
    lFonc[2].setParam(1,0);
    lFonc[2].setParam(2,1/h);
    lFonc[2].setParam(3,0);
    comptSommet=1;
    comptElem=1;
    listeSommets = new SommetR2*[integer_part((cote/h+1)*(cote/h+1))];
    listeElemFin = new ElementFiniR2*[integer_part(4*(cote/h)*(cote/h))];
    p1 = new SommetR2(comptSommet,this->getSommet(1)->getAbscisse(),this->getSommet(1)->getOrdonnee());
    comptSommet=comptSommet+1;
    listeSommets[comptSommet-2] = p1;
    p2 = new SommetR2(comptSommet,p1->getAbscisse()+h,p1->getOrdonnee());
    comptSommet=comptSommet+1;
    listeSommets[comptSommet-2] = p2;
    p3 = new SommetR2(comptSommet,p1->getAbscisse(),p1->getOrdonnee()+h);
    comptSommet=comptSommet+1;
    listeSommets[comptSommet-2] = p3;
    t = new Triangle(p1,p2,p3);
    elFin = new ElementFiniR2(comptElem,t);
    comptElem=comptElem+1;
    elFin->setListeFonctions(lFonc);
    listeElemFin[comptElem-2]=elFin;
    //CREATION DE LA PREMIERE LIGNE: EN BAS
    lFonc[0].setParam(1,0);
    lFonc[0].setParam(2,-1/h);
    lFonc[0].setParam(3,1);
    lFonc[1].setParam(1,-1/h);
    lFonc[1].setParam(2,0);
    lFonc[1].setParam(3,1);
    lFonc[2].setParam(1,1/h);
    lFonc[2].setParam(2,1/h);
    lFonc[2].setParam(3,-1);
    while(comptElem<=(2*cote/h))
    {
        if((comptElem % 2) == 0)
        {
            p1=t->getSommet(2);
            p2=t->getSommet(3);
            p3 = new SommetR2(comptSommet,p2->getAbscisse()+h,p2->getOrdonnee());
            comptSommet=comptSommet+1;
            listeSommets[comptSommet-2] = p3;
            t = new Triangle(p1,p2,p3);
            elFin = new ElementFiniR2(comptElem,t);
            comptElem=comptElem+1;
            elFin->setListeFonctions(lFonc);
            listeElemFin[comptElem-2]=elFin;
        }
        else
        {
            p1=t->getSommet(1);
            p3=t->getSommet(3);
            p2 = new SommetR2(comptSommet,p1->getAbscisse()+h,p1->getOrdonnee());
            comptSommet=comptSommet+1;
            listeSommets[comptSommet-2] = p2;
            t = new Triangle(p1,p2,p3);
            elFin = new ElementFiniR2(comptElem,t);
            comptElem=comptElem+1;
            elFin->setListeFonctions(listeElemFin[0]->getListeFonctions());
            listeElemFin[comptElem-2]=elFin;
        }
        //CREATION DES AUTRES LIGNES
    }
    cout<<2*cote/h*cote/h;
    while((comptElem) <= ((2*cote/h)*(cote/h)))
    {
        if((comptElem-1) % integer_part(2*cote/h) == 0)
        {
            elFin=listeElemFin[comptElem-integer_part(2*cote/h)];
            t=(Triangle *) elFin->getDomaine();
            p1=t->getSommet(2);
            p2=t->getSommet(3);
            p3= new SommetR2(comptSommet,p1->getAbscisse(),p1->getOrdonnee()+h);
            comptSommet++;
            listeSommets[comptSommet-2] = p3;
            t=new Triangle(p1,p2,p3);
            elFin = new ElementFiniR2(comptElem,t);
            comptElem=comptElem+1;
            listeElemFin[comptElem-2]=elFin;
        }
        else if(comptElem % 2 == 0)
        {
            p1=p2;
            p2=p3;
            p3= new SommetR2(comptSommet,p1->getAbscisse(),p1->getOrdonnee()+h);
            comptSommet++;
            listeSommets[comptSommet-2] = p3;
            t= new Triangle(p1,p2,p3);
            elFin= new ElementFiniR2(comptElem,t);
            comptElem++;
            listeElemFin[comptElem-2]=elFin;
        }
        else
        {
            elFin=listeElemFin[comptElem-integer_part(2*cote/h)];
            t=(Triangle *) elFin->getDomaine();
            p2=t->getSommet(3);
            t= new Triangle(p1,p2,p3);
            elFin= new ElementFiniR2(comptElem,t);
            comptElem++;
            listeElemFin[comptElem-2]=elFin;
        }
    }

    //CREATION ET RENVOIE DU MAILLAGE
    m = new MaillageR2(comptSommet-1,comptElem-1,listeSommets,listeElemFin);
    return m;
}
