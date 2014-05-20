#include "graphe.h"

Graphe::Graphe(vector<Sommet*> lSommets,vector<Arete*> lArcs)
{
    listeSommets=lSommets;
    listeArcs=lArcs;
}

Graphe::~Graphe()
{
    int i;
    for(i=0;i<listeSommets.size();i++)
        delete listeSommets[i];

    for(i=0;i<listeArcs.size();i++)
        delete listeArcs[i];
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

vector<Sommet*>  Graphe::obtenirListeAdj(Sommet * s)
{
	vector<Sommet *> lAdj = vector<Sommet*>();
	for(int i=0;i<listeArcs.size();i++)
	{
		if((listeArcs[i]->getDepart()->getId()) == (s->getId()) )
			lAdj.push_back(listeArcs[i]->getArrivee());
		else if((listeArcs[i]->getArrivee()->getId()) == (s->getId()) )
			lAdj.push_back(listeArcs[i]->getDepart());
	}

	return lAdj;
}

void Graphe::supprSommet(Sommet* som)
{
	vector<Sommet*>::iterator it=getListeSommets().begin();
	while(*it!=som)
		it++;

	vector<Sommet*>::iterator itSuiv=it+1;
    delete *it;
    getListeSommets().erase(it);
	
    //On reaffecte les id suivants
    int nvId;
    do
    {
        nvId=distance(getListeSommets().begin(),itSuiv)-1;
        (*(itSuiv))->setId(nvId); //On affecte la position dans le vector
    }
    while(itSuiv!=getListeSommets().end());
}

ostream& operator<<( ostream &flux, Graphe& graph ){
    flux<<"Sommets existant : "<<"\n";
    for(int i=0;i<graph.getListeSommets().size();i++)
        flux<<*(graph.getListeSommets().at(i));
}
