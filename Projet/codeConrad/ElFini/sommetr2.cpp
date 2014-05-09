#include "sommetr2.h"

SommetR2::SommetR2(int num, float coord1,float coord2):Sommet(num)
{
    coordonnees[0]=coord1;
    coordonnees[1]=coord2;
}

void SommetR2::translater(float x,float y)
{
    coordonnees[0]+=x;
    coordonnees[1]+=y;
}

void SommetR2::setCoordonnees(float x,float y)
{
    coordonnees[0]=x;
    coordonnees[1]=y;
}

void SommetR2::setAbscisse(float x)
{
    coordonnees[0]=x;
}

void SommetR2::setOrdonnee(float y)
{
    coordonnees[1]=y;
}

float SommetR2::getAbscisse()
{
    return coordonnees[0];
}

float SommetR2::getOrdonnee()
{
    return coordonnees[1];
}

void SommetR2::afficher()
{
    cout<<"Id:"<<numero<<",";
    cout<<"("<<coordonnees[0]<<";"<<coordonnees[1]<<")\n";
}
