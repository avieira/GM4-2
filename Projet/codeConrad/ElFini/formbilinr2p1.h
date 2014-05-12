#ifndef FORMBILINR2P1_H
#define FORMBILINR2P1_H

#include "formbilin.h"
#include "elementfinir2.h"

class FormBilinR2P1 : public FormBilin
{
public:
    FormBilinR2P1();
    float calc(ElementFiniR2 *e,int if1,int if2);
};


#endif // FORMBILINR2P1_H
