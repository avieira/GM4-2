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

float aire()
{
    return 1.;
}
