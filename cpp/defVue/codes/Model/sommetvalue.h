#ifndef SOMMETVALUE_H
#define SOMMETVALUE_H

#include "sommet.h"
//#include "sommetvaluecolore.h"

class SommetValue : public Sommet
{
public:
    //SommetValue();
    SommetValue(Sommet*);
    int getValeur();
    void setValeur(int);
    //SommetValueColore* sommetToColore();

private:
    int valeur;
};

#endif // SOMMETVALUE_H
