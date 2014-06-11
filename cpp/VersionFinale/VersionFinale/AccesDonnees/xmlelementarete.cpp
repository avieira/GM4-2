#include "xmlelementarete.h"

XMLElementArete::XMLElementArete(Arete* arete, QDomElement elmt) : QDomElement(elmt)
{
    arc=arete;
    arc->addObserver(this);
    //On réaffecte l'ID du départ :
    setAttribute(QString("Depart"),arc->getDepart()->getNom());

    //De même avec l'arrivée :
    setAttribute(QString("Arrivee"),arc->getArrivee()->getNom());
}

void XMLElementArete::setArete(void* arete)
{
    arc=(Arete*)arete;
}

void XMLElementArete::update()
{
    //On réaffecte l'ID du départ :
    setAttribute(QString("Depart"),arc->getDepart()->getNom());

    //De même avec l'arrivée :
    setAttribute(QString("Arrivee"),arc->getArrivee()->getNom());
}
