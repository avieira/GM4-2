#include "formlinr2p1.h"

FormLinR2P1::FormLinR2P1()
{
}

float FormLinR2P1::calc(ElementFiniR2 *e,int if1)
{
    RestFctBaseR2P1 *l,f1;
    Triangle *t;
    SommetR2 *s1,*s2,*s3;

    t=(Triangle *) e->getDomaine();
    l=(RestFctBaseR2P1 *) e->getListeFonctions();
    f1=l[if1];
    s1=t->getSommet(1);
    s2=t->getSommet(2);
    s3=t->getSommet(3);
//On a choisit f=cst=1 ici
    return  (t->aire())*(f1.calc((s1->getAbscisse()+s2->getAbscisse())/2.,
                                 (s1->getOrdonnee()+s2->getOrdonnee())/2.)
                         +f1.calc((s2->getAbscisse()+s3->getAbscisse())/2.,
                                  (s2->getOrdonnee()+s3->getOrdonnee())/2.)
                         +f1.calc((s3->getAbscisse()+s1->getAbscisse())/2.,
                                  (s3->getOrdonnee()+s1->getOrdonnee())/2.))/3.;
}
