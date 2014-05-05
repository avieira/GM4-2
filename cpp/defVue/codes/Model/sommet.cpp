#include "sommet.h"
#include "sommetcolore.h"

Sommet::Sommet(string nvId, string shape)
{
    id=nvId;
    forme=shape;
}


string Sommet::getId()
{
    return id;
}

void Sommet::setId(string nvId){
    id=nvId;
}

void Sommet::setForme(string shape){
    forme=shape;
}

string Sommet::getForme(){
    return forme;
}

Sommet* Sommet::sommetToColore(){
    SommetColore* nvSom=new SommetColore(this);
    return nvSom;
}
