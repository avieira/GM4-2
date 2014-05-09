#include "elementfinir2.h"

ElementFiniR2::ElementFiniR2(int num, GeometrieR2 *support)
{
    numero=num;
    domaine=support;
}

void ElementFiniR2::afficher()
{
    cout<<"---------------------\n";
    cout<<"Num Elem: "<<numero<<"\n";
    domaine->afficher();
    cout<<"---------------------\n";
}

GeometrieR2* ElementFiniR2::getDomaine()
{
    return domaine;
}
