#include "maillager2.h"

MaillageR2::MaillageR2()
{
}

MaillageR2::MaillageR2(int nbPM,int nbPMB,int nbPMI,int nbEl,SommetR2 **l,SommetR2 **lB,SommetR2 **lI,ElementFiniR2 **e)
{
    nombrePointsMaillage=nbPM;
    nombrePointsMaillageBord=nbPMB;
    nombrePointsMaillageInterieur=nbPMI;
    nombreElemFin=nbEl;
    listePointsMaillage=l;
    listePointsMaillageBord=lB;
    listePointsMaillageInterieur=lI;
    listeElemFin=e;
}

void 	MaillageR2::afficher()
{
    int 	i;
    cout<<"SOMMETS\n";
    for(i=0;i<nombrePointsMaillage;i++)
        listePointsMaillage[i]->afficher();
    cout<<"SOMMETS BORDS\n";
    for(i=0;i<nombrePointsMaillageBord;i++)
        listePointsMaillageBord[i]->afficher();
    cout<<"SOMMETS INTERIEUR\n";
    for(i=0;i<nombrePointsMaillageInterieur;i++)
        listePointsMaillageInterieur[i]->afficher();
    cout<<"ELEMENTS FINIS\n";
    for(i=0;i<nombreElemFin;i++)
        listeElemFin[i]->afficher();
}

void 	MaillageR2::setListePointsMaillage(SommetR2 **l)
{
    listePointsMaillage=l;
}

void 	MaillageR2::setListeElemFin(ElementFiniR2 **l)
{
    listeElemFin=l;
}

ElementFiniR2 *MaillageR2::getElementFini(int i)
{
    return listeElemFin[i-1];
}
