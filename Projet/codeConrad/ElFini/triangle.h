#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "geometrier2.h"

class Triangle: public GeometrieR2
{
public:
    Triangle();
    Triangle(SommetR2 *p1,SommetR2 *p2,SommetR2 *p3);
    float aire();
};


#endif // TRIANGLE_H
