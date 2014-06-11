#include "sommetcolore.h"

SommetColore::SommetColore(bool m, string col):Sommet(m)
{
    couleur=col;


    //On crée la table de correspondance entre un entier et les couleurs
    tableCouleur.push_back("#B9121B");
    tableCouleur.push_back("#677E52");
    tableCouleur.push_back("#046380");
    tableCouleur.push_back("#EEEEC6");
    tableCouleur.push_back("#ABC8E2");
    tableCouleur.push_back("#8FCF3C");
    tableCouleur.push_back("#FFB6B8");
    tableCouleur.push_back("#FF5B2B");
    tableCouleur.push_back("#729179");
    tableCouleur.push_back("#F4FF3A");
    tableCouleur.push_back("#BDB55A");
    tableCouleur.push_back("#495CFF");
    tableCouleur.push_back("#853894");
    tableCouleur.push_back("#05966D");
    tableCouleur.push_back("#FF9300");
    tableCouleur.push_back("#77ABD6");
    tableCouleur.push_back("#FFD9DF");
    tableCouleur.push_back("#2B2E2A");
    tableCouleur.push_back("#4EA9A0");
}


SommetColore::SommetColore(Sommet* sommet, string col) : Sommet(sommet->isMarque())
{
    setId(sommet->getId());
    setForme(sommet->getForme());
    setNom(sommet->getNom());

    //Pose des problèmes :
    //for(std::vector<Observer*>::iterator it=sommet->listeObserver.begin();it!=sommet->listeObserver.end();it++)
        //addObserver(*it);

    couleur=col;

    //On crée la table de correspondance entre un entier et les couleurs
    tableCouleur.push_back("#B9121B");
    tableCouleur.push_back("#677E52");
    tableCouleur.push_back("#046380");
    tableCouleur.push_back("#EEEEC6");
    tableCouleur.push_back("#ABC8E2");
    tableCouleur.push_back("#8FCF3C");
    tableCouleur.push_back("#FFB6B8");
    tableCouleur.push_back("#FF5B2B");
    tableCouleur.push_back("#729179");
    tableCouleur.push_back("#F4FF3A");
    tableCouleur.push_back("#BDB55A");
    tableCouleur.push_back("#495CFF");
    tableCouleur.push_back("#853894");
    tableCouleur.push_back("#05966D");
    tableCouleur.push_back("#FF9300");
    tableCouleur.push_back("#77ABD6");
    tableCouleur.push_back("#FFD9DF");
    tableCouleur.push_back("#2B2E2A");
    tableCouleur.push_back("#4EA9A0");
}

string SommetColore::getCouleur()
{
    return couleur;
}

vector<string> SommetColore::getTableCouleur()
{
    return tableCouleur;
}

string SommetColore::getCouleurDansTable(int ind)
{
    if(ind<tableCouleur.size())
	return tableCouleur[ind];
    else
	return "#FFFFFF";
}

void SommetColore::setCouleur(string codeRGB)
{
    couleur=codeRGB;
    notify();
}

void SommetColore::setCouleur(int numeroCouleur)
{
    couleur=getCouleurDansTable(numeroCouleur);
    notify();
}

void SommetColore::setTableCouleur(vector<string> table)
{
    tableCouleur=table;
}

void* SommetColore::sommetToColore(){
    return this;
}

void operator<<( ostream &flux, SommetColore& som )
{
    flux<<"Sommet n° ";
    flux<<som.getId();
    flux<<" : "<<som.getCouleur();
    flux<<endl;
}
