#include "graphe.h"
#include <algorithm>

Graphe::Graphe(vector<Sommet*> lSommets,vector<Arete*> lArcs)
{
    listeSommets=lSommets;
    listeArcs=lArcs;
}

Graphe::~Graphe()
{
    /*int i;
    for(i=0;i<listeSommets.size();i++)
        delete listeSommets[i];

    for(i=0;i<listeArcs.size();i++)
        delete listeArcs[i];*/
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
    vector<Sommet*>::iterator it=find(listeSommets.begin(), listeSommets.end(),som);

    vector<Sommet*>::iterator itSuiv=listeSommets.erase(it);
    //delete som;

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

void Graphe::notifyArete(Sommet *som)
{
    for(std::vector<Arete*>::iterator it=listeArcs.begin(); it!=listeArcs.end(); it++){
        if((som==(*it)->getDepart())||(som==(*it)->getArrivee()))
            (*it)->notify();
    }
}

void operator<<( ostream &flux, Graphe& graph ){
    flux<<"Sommets existant : "<<"\n";
    for(int i=0;i<graph.getListeSommets().size();i++)
        flux<<*(graph.getListeSommets().at(i));
}

Sommet* Graphe::obtenirSommet(QString id)
{
    std::vector<Sommet*>::iterator it=listeSommets.begin();
    bool trouve=false;
    Sommet* result=*it;

    while((it!=listeSommets.end()) && !trouve){
        if((*it)->getNom()==id){
            result=*it;
            trouve=true;
        }
        it++;
    }

    return result;
}

bool Graphe::contains(QString id)
{
    std::vector<Sommet*>::iterator it=listeSommets.begin();
    bool trouve=false;

    while((it!=listeSommets.end()) && !trouve){
        if((*it)->getNom()==id)
            trouve=true;
        it++;
    }

    return trouve;
}
