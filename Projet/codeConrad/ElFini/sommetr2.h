#ifndef SOMMETR2_H
#define SOMMETR2_H

#include"sommet.h"
#include<iostream>

using namespace std;

class SommetR2: public Sommet
{

public:
    float coordonnees[2];

    SommetR2(int num,float coord1,float coord2);
    void translater(float x,float y);
    void setCoordonnees(float x,float y);
    void setAbscisse(float x);
    void setOrdonnee(float y);
    float getAbscisse();
    float getOrdonnee();
    void afficher();
};

#endif // SOMMETR2_H
