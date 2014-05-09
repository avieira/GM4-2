#ifndef MAILLAGE_H
#define MAILLAGE_H

//Un maillage est constitue d'un ensemble de points, d'un ensemble d'element finis et de fonctions de base sur le maillage

#include "elementfini.h"

class Maillage
{
public:
    int nombrePointsMaillage,nombreElemFin;
    //		Geometrie *domaine; //C est la geometrie qui genere le maillage?

    Sommet **listePointsMaillage;
    ElementFini **listeElemFin;

    //       	listeFonctionsBase=[]
    //			Maillage(Geometrie *dom)
    //			{
    //				domaine=dom;
    //			};

    Maillage();
    ElementFini *getElementFini(int i);
    Sommet *getPointMaillage(int i);
    void setNombrePointsMaillage(int n);
    void setNombreElemFin(int n);
    void setListePointsMaillage(Sommet **l);
    void setListeElemFin(ElementFini **l);
};


#endif // MAILLAGE_H
