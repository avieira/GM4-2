#include"solution.h"

Solution::Solution(int k, vector<int> tab, GrapheColore* g)
{
    nbCouleurs = k;
    leTableau = tab;
    graphe=g;
}

int Solution::calculerCout()
{
    int i, j, l, leCout, coutPartiel;
    vector<SommetColore*> listeSommets=graphe->getListeSommets();
    vector<SommetColore*> voisins;
    SommetColore* s;

    l = leTableau.size();
    leCout = 0;
    for(i=0; i<l; i++)
    {
        coutPartiel = 0;
        s = listeSommets[i];
        voisins = graphe->obtenirListeAdj(s);
        for(j=0; j<voisins.size(); j++)
            if(leTableau[i] == leTableau[voisins[j]->getId()])
                coutPartiel++;
        leCout += coutPartiel;
    }
    return leCout;
}

// Pour generer aléatoirement des Solutions "proches", on ne modifie que les Sommets dont la coloration n'est pas admissible. Cette fonction doit les reperer et les retourner dans un Vector
vector<SommetColore*> Solution::calculerSommetsModifiables()
{
    vector<SommetColore*> listeSommets=graphe->getListeSommets();
    vector<SommetColore*> sommetsModifiables;
    vector<SommetColore*> voisins;
    SommetColore* sommetCourant;
    int i, j, caseCourante, n, nbVoisins, laCouleur;
    bool modifiable = false;

    caseCourante = 0;
    n = leTableau.size();
    sommetsModifiables = vector<SommetColore*>(n);
    for(i=0; i<n; i++)
    {
        sommetCourant = listeSommets[i];
        voisins = graphe->obtenirListeAdj(sommetCourant);
        nbVoisins = voisins.size();
        laCouleur = leTableau[i];
        j = 0;
        while((!modifiable) && (j<nbVoisins))
        {
            if(leTableau[voisins[j]->getId()] == laCouleur)
                modifiable = true;
            j++;
        }
        if(modifiable)
        {
            sommetsModifiables[caseCourante] = sommetCourant;
            caseCourante++;
        }
    }
    sommetsModifiables.resize(caseCourante+1);

    return sommetsModifiables;
}

// Cette fonction generera aleatoirement des Solutions "proches" de s
Solution* Solution::genererSolVoisine(vector<SommetColore*> sommetsModifiables)
{
    int i, nbVoisins, ancienCout, nouveauCout, indiceModif, couleurModif, ancienneCoul, idAncienSommet;
    Solution* nouvelleSol= new Solution(nbCouleurs,leTableau,graphe);
    SommetColore* sommetModif;
    vector<SommetColore*> voisins;

    srand (time(NULL));
    // Generation aleatoire de l'indice du sommetModifiable qu'on modifiera, ainsi que sa nouvelle couleur
    indiceModif = (rand() % leTableau.size());	// Pas sûr s'il faut +1 ou pas
    idAncienSommet = sommetsModifiables[indiceModif]->getId();
    ancienneCoul = leTableau[idAncienSommet];
    do
        couleurModif = (rand() % nbCouleurs) + 1;
    while(couleurModif == ancienneCoul);

    // Finalisation de la solution generee
    nouvelleSol->setIemeCouleur(indiceModif, couleurModif);
    sommetModif = sommetsModifiables[indiceModif];
    nouvelleSol->setSommetModifie(sommetModif);

    // Correction du coût de la nouvelle solution
    voisins = graphe->obtenirListeAdj(sommetModif);
    nbVoisins = voisins.size();
    for(i=0; i<nbVoisins; i++)
    {
        if(leTableau[i] == ancienneCoul)
            ancienCout++;
        if(leTableau[i] == couleurModif)
            nouveauCout++;
    }
    cout+=(nouveauCout-ancienCout);

    return nouvelleSol;
}

// Pour verifier qu'une Solution soit presente ou non dans une file (deque) de Solutions T
bool Solution::appartientA(deque<Solution *>* T)
{
    int i, j, longueurLeTableau;
    bool difference, trouve;

    deque<Solution*>::iterator iter = T->begin();
    longueurLeTableau = (*iter)->leTableau.size();
    i = 0;
    trouve = false;
    while((!trouve) && (i<T->size()))
    {
        difference = false;
        j = 0;
        while((!difference) && (j<longueurLeTableau))
        {
            if(leTableau[j] != (*iter)->leTableau[j])
                difference = true;
            j++;
        }
        if(!difference)
            trouve = true;

        iter++;
        i++;
    }

    return trouve;
}

void Solution::setCout(int nvCout)
{
    cout=nvCout;
}

int Solution::getCout()
{
    return cout;
}

void Solution::setIemeCouleur(int indiceModif, int couleurModif)
{
    leTableau[indiceModif] = couleurModif;
}

void Solution::setSommetModifie(Sommet* sommetModif)
{
    sommetModifie = sommetModif;
}

vector<int> Solution::getCouleurs()
{
    return leTableau;
}
