#ifndef FORMLINR2P1_H
#define FORMLINR2P1_H

#include"restfctbaser2p1.h"
#include"triangle.h"
#include "elementfinir2.h"


class FormLinR2P1
{
public:
    FormLinR2P1();
    float 	calc(ElementFiniR2 *e,int if1);
};

#endif // FORMLINR2P1_H
