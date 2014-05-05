#ifndef SOMMETCOLORE_H
#define SOMMETCOLORE_H

#include "sommet.h"

using namespace std;

class SommetColore : public Sommet
{
public:
    //SommetColore();
    SommetColore(Sommet*);
    string getCouleur();
    void setCouleur(string);
    SommetColore* sommetToColore();

private:
    string couleur;
};

#endif // SOMMETCOLORE_H
