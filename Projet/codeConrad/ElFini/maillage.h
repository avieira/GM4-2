#ifndef MAILLAGE_H
#define MAILLAGE_H

//Un maillage est constitue d'un ensemble de points, d'un ensemble d'element finis et de fonctions de base sur le maillage

#include "elementfini.h"

class Maillage
{
public:
    int nombrePointsMaillage,nombrePointsMaillageBord,nombrePointsMaillageInterieur,nombreElemFin;
    Sommet **listePointsMaillage;
    ElementFini **listeElemFin;
    Sommet **listePointsMaillageBord;
    //       	listeFonctionsBase=[]


    Maillage();
    ElementFini ** getListeElementsFinis();
    ElementFini *getElementFini(int i);
    Sommet *getPointMaillage(int i);
    Sommet *getPointMaillageBord(int i);
    void 	setNombrePointsMaillage(int n);
    void 	setNombreElemFin(int n);
    void 	setListePointsMaillage(Sommet **l);
    void 	setListePointsMaillageBord(Sommet **l);
    void 	setListeElemFin(ElementFini **l);
};


#endif // MAILLAGE_H
