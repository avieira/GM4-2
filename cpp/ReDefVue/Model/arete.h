#ifndef ARETE_H
#define ARETE_H

#include "sommet.h"

class Arete
{
public:
    Arete(Sommet*, Sommet*);
    Sommet *getDepart();
    Sommet *getArrivee();
    void setDepart(Sommet*);
    void setArrivee(Sommet*);


protected:
    Sommet *depart;
    Sommet *arrivee;
};

#endif // ARETE_H
