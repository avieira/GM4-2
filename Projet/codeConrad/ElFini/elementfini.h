#ifndef ELEMENTFINI_H
#define ELEMENTFINI_H

#include "geometrie.h"
#include "restfctbaser2p1.h"

//Il est identifie par son numero, il possede un domaine, et pour chaque point du domaine est associee la restriction d'une fonction de base au domaine. Il y a aussi des conditions au bord
class ElementFini
{
public:
    int	numero;
    Geometrie *domaine;
    RestFctBaseR2P1 listeFonctions[3];

    ElementFini();
    Geometrie *getDomaine();
    void setListeFonctions(RestFctBaseR2P1 *l);
    RestFctBaseR2P1 *getListeFonctions();
};


#endif // ELEMENTFINI_H
