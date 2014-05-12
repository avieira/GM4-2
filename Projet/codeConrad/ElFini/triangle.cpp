#include "triangle.h"

Triangle::Triangle():GeometrieR2()
{
    nombreSommets=3;
    listeSommets= new SommetR2*[nombreSommets];
}

Triangle::Triangle(SommetR2 *p1,SommetR2 *p2,SommetR2 *p3):GeometrieR2()
{
    nombreSommets=3;
    listeSommets= new SommetR2*[nombreSommets];
    listeSommets[0]=p1;
    listeSommets[1]=p2;
    listeSommets[2]=p3;
}

float Triangle::aire()
{
    float aire;

    aire=(listeSommets[1]->getAbscisse() - listeSommets[0]->getAbscisse())*(listeSommets[2]->getOrdonnee() - listeSommets[0]->getOrdonnee())
            - (listeSommets[2]->getAbscisse() - listeSommets[0]->getAbscisse())*(listeSommets[1]->getOrdonnee() - listeSommets[0]->getOrdonnee());

    if(aire<0)
        aire=(-1)*aire;
    return aire/2.;
}
