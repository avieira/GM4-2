#ifndef RESTFCTBASER2P1_H
#define RESTFCTBASER2P1_H

#include"restfctbaser2.h"
#include <iostream>

using namespace std;

class RestFctBaseR2P1 : public RestFctBaseR2
        //a*x+b*y+c :: a,b,c
{
public:
    float param[3];

    RestFctBaseR2P1();
    float getParam(int i);
    void setParam(int i,float p);
    float calc(float x,float y);
    void afficher();
};

#endif // RESTFCTBASER2P1_H
