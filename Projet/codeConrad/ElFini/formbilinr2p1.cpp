#include "formbilinr2p1.h"
#include "restfctbaser2p1.h"
#include "triangle.h"


FormBilinR2P1::FormBilinR2P1()
{
}

float 	FormBilinR2P1::calc(ElementFiniR2 *e,int if1,int if2)
{
    RestFctBaseR2P1 *l,f1,f2;
    Triangle *t;

    t=(Triangle *) e->getDomaine();
    l=(RestFctBaseR2P1*) e->getListeFonctions();
    f1=l[if1];
    f2=l[if2];
    return  (f1.getParam(1)*f2.getParam(1)+f1.getParam(2)*f2.getParam(2))*(t->aire());
}
