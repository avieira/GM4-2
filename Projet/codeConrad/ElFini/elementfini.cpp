#include "elementfini.h"

ElementFini::ElementFini()
{
}

Geometrie* ElementFini::getDomaine()
{
    return domaine;
}

void ElementFini::setListeFonctions(RestFctBaseR2P1 *l)
{
    listeFonctions[0].setParam(1,l[0].getParam(1));
    listeFonctions[0].setParam(2,l[0].getParam(2));
    listeFonctions[0].setParam(3,l[0].getParam(3));
    listeFonctions[1].setParam(1,l[1].getParam(1));
    listeFonctions[1].setParam(2,l[1].getParam(2));
    listeFonctions[1].setParam(3,l[1].getParam(3));
    listeFonctions[2].setParam(1,l[2].getParam(1));
    listeFonctions[2].setParam(2,l[2].getParam(2));
    listeFonctions[2].setParam(3,l[2].getParam(3));
}

RestFctBaseR2P1 *ElementFini::getListeFonctions()
{
    return listeFonctions;
}
