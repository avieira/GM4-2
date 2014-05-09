#ifndef ELEMENTFINI_H
#define ELEMENTFINI_H

#include "geometrie.h"
#include "restfctbase.h"

//Il est identifie par son numero, il possede un domaine, et pour chaque point du domaine est associee la restriction d'une fonction de base au domaine. Il y a aussi des conditions au bord
class ElementFini
{
public:
    int	numero;
    Geometrie *domaine;
    RestFctBase *listeFonctions; //VECTOR
    //      		conditionsAuBord=[]

    ElementFini();
    Geometrie *getDomaine();
    void setListeFonctions(RestFctBase *l);
    RestFctBase *getListeFonctions();
};


#endif // ELEMENTFINI_H
