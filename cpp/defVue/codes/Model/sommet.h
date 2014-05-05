#ifndef SOMMET_H
#define SOMMET_H

#include<string>

using namespace std;

class Sommet
{
public:
    Sommet(string nvId, string shape="square");

    string getId();
    void setId(string);
    void setForme(string);
    string getForme();
    Sommet* sommetToColore();


private:
    string id;
    string forme;
};

#endif // SOMMET_H
