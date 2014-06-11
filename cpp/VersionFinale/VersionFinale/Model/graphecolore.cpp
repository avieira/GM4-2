#include "graphecolore.h"
#include"solution.h"


GrapheColore::GrapheColore():Graphe()
{
}

GrapheColore::~GrapheColore()
{
    /*int i;
    for(i=0;i<listeSommets.size();i++)
        delete listeSommets[i];

    for(i=0;i<listeArcs.size();i++)
        delete listeArcs[i];*/
}

void GrapheColore::setListeSommets(vector<SommetColore*> liste)
{
    listeSommets=liste;
}

vector<SommetColore*> GrapheColore::getListeSommets()
{
    return listeSommets;
}

void GrapheColore::ajouterSommet(SommetColore* sommet)
{
    listeSommets.push_back(sommet);
}

vector<SommetColore*>  GrapheColore::obtenirListeAdj(SommetColore * s)
{
    vector<SommetColore *> lAdj = vector<SommetColore*>();
    for(int i=0;i<listeArcs.size();i++)
    {
        if((listeArcs[i]->getDepart()->getId()) == (s->getId()) )
            lAdj.push_back((SommetColore*)listeArcs[i]->getArrivee());
        else if((listeArcs[i]->getArrivee()->getId()) == (s->getId()) )
            lAdj.push_back((SommetColore*)listeArcs[i]->getDepart());
    }

    return lAdj;
}

void GrapheColore::supprSommet(SommetColore* som)
{
    vector<SommetColore*>::iterator it=find(listeSommets.begin(), listeSommets.end(),som);

    vector<SommetColore*>::iterator itSuiv=listeSommets.erase(it);
    //delete (*it);

    //On reaffecte les id suivants
    int nvId;
    nvId=distance(listeSommets.begin(),itSuiv)-1;
    (*(itSuiv))->setId(nvId); //On affecte la position dans le vector
    while(itSuiv!=listeSommets.end())
    {
        itSuiv++;
        nvId=distance(listeSommets.begin(),itSuiv)-1;
        (*(itSuiv))->setId(nvId); //On affecte la position dans le vector
    }
}

// On a défini une relation d'ordre sur les "étiquettes" des sommets. Cette fonction sert à calculer laquelle des deux étiquettes L1, L2 est max.
int GrapheColore::comparerEtiquettes(set<int> L1, set<int> L2)
{
    int i, l, l1, l2, resultat;
    bool trouve;

    set<int>::iterator iter1 = L1.end();
    set<int>::iterator iter2 = L2.end();

    l1 = L1.size();
    l2 = L2.size();

    // Pour éviter le dépassement de capacité, on a besoin de connaître la longueur minimale des deux étiquettes.
    if (l2>l1)
    {
        l = l1;
    }
    else
    {
        l = l2;
    }

    // On compare deux à deux les deux éléments maximaux de chaque étiquette.
    i = 0;
    trouve = false;
    while((i<l) && (!trouve))
    {
        if (*iter1 > *iter2)
        {
            trouve = true;
            resultat = 1;
        }
        else if (*iter2 > *iter1)
        {
            trouve = true;
            resultat = 2;
        }
        else
        {
            iter1--;
            iter2--;
        }
        i++;
    }
    return resultat;
}

vector<int> GrapheColore::lexBFS()
{
    int n = listeSommets.size();
    set<int> L[n];
    vector<int> theta = vector<int>(n);
    vector<SommetColore*> voisins;
    int i, j, sup, nbVoisins, incr, k;
    SommetColore* s;

    for(k=0;k<n;k++)
        listeSommets[k]->setMarque(false);

    s = listeSommets[0];
    for(i=0; i<n-1; i++)
    {
        voisins = obtenirListeAdj(s);
        nbVoisins = voisins.size();
        theta[s->getId()] = i;

        s->setMarque(true);
        // Mise à jour des étiquettes des sommets voisins

        for (j=0; j<nbVoisins; j++)
            L[voisins[j]->getId()].insert(i);

        // Recherche du sommet d'étiquette maximale. Le maximum est forcément parmi les voisins !
        incr=0;
        while(voisins[incr]->isMarque()){
            incr++;
        }
        s = voisins[incr];

        for (j=incr+1; j<nbVoisins; j++)
        {
            if(!(voisins[j]->isMarque()))
            {
                sup = comparerEtiquettes(L[s->getId()], L[voisins[j]->getId()]);
                if((sup==2))
                    s = voisins[j];
            }
        }
    }

    //On s'occupe du dernier sommet manquant :
    theta[s->getId()] = n-1;

    return inverser(theta);
}

// Nécessaire car COLOR s'applique sur l'ordre inverse calculé
vector<int> GrapheColore::inverser(vector<int> ordre)
{
    int i, n, temp;

    n = listeSommets.size();
    for(i=0; i<(n/2); i++)
    {
        temp = ordre[i];
        ordre[i] = ordre[(n-1)-i];
        ordre[(n-1)-i] = temp;
    }
    return ordre;
}

void GrapheColore::colorerSommets(vector<int> couleurs)
{
    SommetColore* sommet;
    int couleur;
    for(int i=0;i<couleurs.size();i++){
        sommet=getListeSommets()[i];
        couleur=couleurs[i];
        sommet->setCouleur(couleur);
    }
}

void GrapheColore::colorerDirect()
{
    vector<int> ordre, couleur;
    int i, j, k, n, laCouleur, nbVoisins;
    vector<SommetColore*> voisins;
    bool mauvaiseCouleur = false;

    n = listeSommets.size();
    couleur = vector<int>(n);

    ordre = lexBFS();

    // Initialisation
    for(i=0; i<n; i++)
        couleur[i] = 0;
    j=0;
    while (ordre[j] != 0)
        j++;
    couleur[j] = 1;

    // Boucle Principale
    for(i=1; i<n; i++)
    {
        // On trouve le sommet de priorité maximale
        j=0;
        while (ordre[j] != i)
            j++;
        // On colore avec la plus basse couleur telle qu'il n'y ait aucune contradiction.
        vector<SommetColore*> listeSommets=getListeSommets();
        SommetColore* somColo=listeSommets[j];
        voisins = obtenirListeAdj(somColo);
        nbVoisins = voisins.size();
        laCouleur = 1;
        do
        {
            k=0;
            mauvaiseCouleur = false;
            while((k<nbVoisins) && (!mauvaiseCouleur))
            {
                if (couleur[voisins[k]->getId()] == laCouleur)
                {
                    mauvaiseCouleur = true;
                    laCouleur++;
                }
                k++;
            }
        }
        while(mauvaiseCouleur);
        couleur[j] = laCouleur;
    }

    colorerSommets(couleur);
    //On remet le fait qu'il soient marqués à false
    for(std::vector<SommetColore*>::iterator it=listeSommets.begin();it!=listeSommets.end();it++)
        (*it)->setMarque(false);
}

bool GrapheColore::colorerH()
{
    int k, coutSolution;
    bool colore;

    k = 2;
    colore = false;
    while((k < listeSommets.size()) && (!colore))
    {
        coutSolution = appelerH(k);
        if(coutSolution == 0)
            colore = true;
        k++;
    }
    return colore;
}

void operator<<( ostream &flux, GrapheColore& graph ){
    flux<<"Sommets existant : "<<"\n";
    for(int i=0;i<graph.getListeSommets().size();i++)
        flux<<*(graph.getListeSommets().at(i));
}

SommetColore* GrapheColore::obtenirSommet(QString id)
{
    std::vector<SommetColore*>::iterator it=listeSommets.begin();
    bool trouve=false;
    SommetColore* result=*it;

    while((it!=listeSommets.end()) && !trouve){
        if((*it)->getNom()==id){
            result=*it;
            trouve=true;
        }
        it++;
    }

    return result;
}

bool GrapheColore::contains(QString id)
{
    std::vector<SommetColore*>::iterator it=listeSommets.begin();
    bool trouve=false;

    while((it!=listeSommets.end()) && !trouve){
        if((*it)->getNom()==id)
            trouve=true;
        it++;
    }

    return trouve;
}

int GrapheColore::appelerH(int k)
{
    // Initialisation des constantes "arbitraires"
    int i, n, nbSol, nbIter;
    int rep = 100;
    int maxIter = 1000;
    vector<int> couleur;
    vector<SommetColore*> sommetsModifiables;
    deque<Solution*> tabou;
    Solution* sol, *nouvelleSol, *meilleureSol;
    bool interrupt;

    n = listeSommets.size();
    couleur = vector<int>(n);

    // Generation (aleatoire) de la solution initiale
    srand (time(NULL));
    for(i=0; i<n; i++)
        couleur[i] = (rand() % k) + 1;
    sol = new Solution(k, couleur, this);
    sol->setCout(sol->calculerCout());

    // Boucle Principale de la methode iterative
    nbIter = 0;
    while((sol->getCout() > 0)) //&& (nbIter < maxIter))
    {
        // Initialisation pour la generation des solutions
        interrupt = false;
        sommetsModifiables = sol->calculerSommetsModifiables();
        do
            meilleureSol = sol->genererSolVoisine(sommetsModifiables);
        while(meilleureSol->appartientA(&tabou));


        // Boucle pour la generation des solutions proches
        nbSol = 1;
        do
        {
            nouvelleSol = sol->genererSolVoisine(sommetsModifiables);
            if((nouvelleSol->getCout() < meilleureSol->getCout()) && !(nouvelleSol->appartientA(&tabou)))
                meilleureSol = nouvelleSol;
            if(nouvelleSol->getCout() < sol->getCout())
            {
                interrupt = true;
                meilleureSol = nouvelleSol;
            }
            nbSol++;
        }
        while(!interrupt);
        //while((nbSol < rep) && (!interrupt));

        if(!interrupt)
            tabou.push_front(meilleureSol);
        sol = meilleureSol;
        nbIter++;
    }
    colorerSommets(sol->getCouleurs());

    return sol->getCout();
}
