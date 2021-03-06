#ifndef MAILLAGER2_H
#define MAILLAGER2_H

#include "maillage.h"
#include "elementfinir2.h"

class MaillageR2 : public Maillage
{
public:
    //		GeometrieR2 *domaine;
    SommetR2 **listePointsMaillage;
    SommetR2 **listePointsMaillageBord;
    SommetR2 **listePointsMaillageInterieur;
    ElementFiniR2 **listeElemFin;

    MaillageR2();
    MaillageR2(int nbPM,int nbPMB,int nbPMI,int nbEl,SommetR2 **l,SommetR2 **lB,SommetR2 **lI,ElementFiniR2 **e);
    void 	afficher();
    void 	setListePointsMaillage(SommetR2 **l);
    void 	setListeElemFin(ElementFiniR2 **l);
    ElementFiniR2 *getElementFini(int i);
};

#endif // MAILLAGER2_H
