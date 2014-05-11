#ifndef GRAPHE_H
#define GRAPHE_H

#include<vector>
#include"arete.h"

using namespace std;

class Graphe
{
public:
    Graphe(vector<Sommet*> lSommets = vector<Sommet*>() ,vector<Arete*> lArcs = vector<Arete*>() );
    ~Graphe();
    void setListeSommets(vector<Sommet*>);
    void setListeArcs(vector<Arete*>);
    vector<Sommet*> getListeSommets();
    vector<Arete*> getListeArcs();
    void ajouterSommet(Sommet*);
    void ajouterArc(Arete*);
    vector<Sommet*>  obtenirListeAdj(Sommet*);

    void supprSommet(Sommet*);

    friend ostream& operator<<( ostream &flux, Graphe& graph );

protected:
    vector<Sommet*> listeSommets;
    vector<Arete*> listeArcs;
};

#endif // GRAPHE_H
