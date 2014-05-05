#ifndef GRAPHE_H
#define GRAPHE_H

#include<vector>
#include"Model/arete.h"

class Graphe
{
public:
    Graphe();
    void setListeSommets(vector<Sommet*>);
    void setListeArcs(vector<Arete*>);
    vector<Sommet*> getListeSommets();
    vector<Arete*> getListeArcs();
    void ajouterSommet(Sommet*);
    void ajouterArc(Arete*);

    Sommet* trouverSommet(string);

private:
    vector<Sommet*> listeSommets;
    vector<Arete*> listeArcs;
};

#endif // GRAPHE_H
