#include "geometrier2.h"

GeometrieR2::GeometrieR2()
{
    dimension=2;
} //A reprendre : voir si on peut ajouter la liste de sommets directement dans le constructeur

void GeometrieR2::afficher()
{
    for(int i=0;i<nombreSommets;i++)
        listeSommets[i]->afficher();
}

void GeometrieR2::setSommet(int i, SommetR2 *s)
{
    listeSommets[i-1]=s;
}


SommetR2* GeometrieR2::getSommet(int i)
{
    return listeSommets[i-1];
}
