#include "maillager2.h"

MaillageR2::MaillageR2()
{
}

MaillageR2::MaillageR2(int nbPM,int nbEl,SommetR2 **l,ElementFiniR2 **e)
{
    nombrePointsMaillage=nbPM;
    nombreElemFin=nbEl;
    listePointsMaillage=l;
    listeElemFin=e;
}

void MaillageR2::afficher()
{
    int i;
    for(i=0;i<nombrePointsMaillage;i++)
        listePointsMaillage[i]->afficher();
    for(i=0;i<nombreElemFin;i++)
        listeElemFin[i]->afficher();
}

void MaillageR2::setListePointsMaillage(SommetR2 **l)
{
    listePointsMaillage=l;
}

void MaillageR2::setListeElemFin(ElementFiniR2 **l)
{
    listeElemFin=l;
}
