#include "arete.h"

Arete::Arete(Sommet *dep, Sommet *arr)
{
    depart=dep;
    arrivee=arr;
}

Sommet *Arete::getDepart()
{
    return depart;
}

Sommet *Arete::getArrivee()
{
    return arrivee;
}

void Arete::setDepart(Sommet* dep)
{
    depart=dep;
}

void Arete::setArrivee(Sommet* arr)
{
    arrivee=arr;
}