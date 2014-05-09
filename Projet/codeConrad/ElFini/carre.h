#ifndef CARRE_H
#define CARRE_H

#include "maillager2.h"

class Carre : public GeometrieR2
        //p1:bas gauche,p2:bas droite,p3:haut droite,p4:haut gauche
{
public:
    float	cote;
    Carre(int larg,SommetR2 *p1,SommetR2 *p2,SommetR2 *p3,SommetR2 *p4);
    MaillageR2 *mailler(float h);
};

#endif // CARRE_H
