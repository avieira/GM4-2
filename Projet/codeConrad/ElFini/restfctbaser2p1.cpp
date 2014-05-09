#include "restfctbaser2p1.h"

RestFctBaseR2P1::RestFctBaseR2P1()
{
}

float RestFctBaseR2P1::getParam(int i)
{
    return param[i-1];
}

void RestFctBaseR2P1::setParam(int i,float p)
{
    param[i-1]=p;
}

float RestFctBaseR2P1::calc(float x,float y)
{
    return param[0]*x+param[1]*y+param[2];
}
