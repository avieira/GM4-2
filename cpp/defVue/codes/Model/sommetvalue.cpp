#include "sommetvalue.h"

SommetValue::SommetValue(Sommet *sommet) : Sommet(sommet->getId(), sommet->getForme())
{
}

int SommetValue::getValeur()
{
    return valeur;
}

void SommetValue::setValeur(int val)
{
    valeur=val;
}
