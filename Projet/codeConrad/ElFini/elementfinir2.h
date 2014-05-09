#ifndef ELEMENTFINIR2_H
#define ELEMENTFINIR2_H

#include "elementfini.h"
#include "geometrier2.h"

class ElementFiniR2 : public ElementFini
{
public:
    GeometrieR2 *domaine;

    ElementFiniR2(int num, GeometrieR2 *support);

    void afficher();
    GeometrieR2 *getDomaine();
};


#endif // ELEMENTFINIR2_H
