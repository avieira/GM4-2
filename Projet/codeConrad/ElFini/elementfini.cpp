#include "elementfini.h"

ElementFini::ElementFini()
{
}

Geometrie* ElementFini::getDomaine()
{
    return domaine;
}

void ElementFini::setListeFonctions(RestFctBase *l)
{
    listeFonctions=l;
}

RestFctBase* ElementFini::getListeFonctions()
{
    return listeFonctions;
}
