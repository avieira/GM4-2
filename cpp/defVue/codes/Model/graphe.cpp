#include "graphe.h"

Graphe::Graphe()
{
    listeSommets=vector<Sommet*>();
    listeArcs=vector<Arete*>();
}

void Graphe::setListeSommets(vector<Sommet*> liste)
{
    listeSommets=liste;
}

void Graphe::setListeArcs(vector<Arete*> liste)
{
    listeArcs=liste;
}

vector<Sommet*> Graphe::getListeSommets()
{
    return listeSommets;
}

vector<Arete*> Graphe::getListeArcs()
{
    return listeArcs;
}

void Graphe::ajouterSommet(Sommet* sommet)
{
    listeSommets.push_back(sommet);
}

void Graphe::ajouterArc(Arete* arc)
{
    listeArcs.push_back(arc);
}

Sommet* Graphe::trouverSommet(string id)
{
    vector<Sommet*> liste=getListeSommets();

    int i=0;
    bool trouve=false;
    while(i<liste.size() && !trouve){
        if(liste[i]->getId()==id)
            trouve=true;
        i++;
    }
    if(trouve)
        return liste[i-1];
    else
        return NULL;

}
