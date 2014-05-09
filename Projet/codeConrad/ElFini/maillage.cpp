#include "maillage.h"

Maillage::Maillage()
{
}

ElementFini* Maillage::getElementFini(int i)
{
    return listeElemFin[i-1];
}

Sommet* Maillage::getPointMaillage(int i)
{
    return listePointsMaillage[i-1];
}

void Maillage::setNombrePointsMaillage(int n)
{
    nombrePointsMaillage=n;
}

void Maillage::setNombreElemFin(int n)
{
    nombreElemFin=n;
}

void Maillage::setListePointsMaillage(Sommet **l)
{
    listePointsMaillage=l;
}

void Maillage::setListeElemFin(ElementFini **l)
{
    listeElemFin=l;
}
