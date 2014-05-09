#ifndef GEOMETRIER2_H
#define GEOMETRIER2_H

#include "geometrie.h"
#include "sommetr2.h"

class GeometrieR2: public Geometrie
{
public:
    SommetR2 **listeSommets;

    GeometrieR2();
    void afficher();
    void setSommet(int i, SommetR2 *s);
    SommetR2 *getSommet(int i);
};

#endif // GEOMETRIER2_H
