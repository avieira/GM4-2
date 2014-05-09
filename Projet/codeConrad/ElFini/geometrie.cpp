#include "geometrie.h"

Geometrie::Geometrie()
{
}

void Geometrie::setSommet(int i, Sommet *s)
{
    listeSommets[i-1]=s;
}

Sommet* Geometrie::getSommet(int i)
{
    return listeSommets[i-1];
}
