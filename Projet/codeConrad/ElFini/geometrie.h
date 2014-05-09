#ifndef GEOMETRIE_H
#define GEOMETRIE_H

#include "sommet.h"

//C'est ce qu'on maille, mais c'est aussi ce qui constitue le support des elements finis
class Geometrie
{
public:
    int dimension;
    int nombreSommets;
    Sommet **listeSommets; //VECTOR

    Geometrie();
    void setSommet(int i, Sommet *s);
    Sommet *getSommet(int i);
};

#endif // GEOMETRIE_H
