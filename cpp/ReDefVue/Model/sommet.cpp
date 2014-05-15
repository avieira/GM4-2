#include "sommet.h"
#include "sommetcolore.h"

int Sommet::nombreSommets=0;

Sommet::Sommet(bool m)
{
    //Les id doivent impérativement commencer à 0 !!
    id=nombreSommets;
    marque=m;
    
    nombreSommets++;
}

Sommet::~Sommet()
{
    nombreSommets--;
}

int Sommet::getId() const
{
    return id;
}

void Sommet::setId(int nvId){
    id=nvId;
}

/*void Sommet::setForme(string shape){
    forme=shape;
}*/

void Sommet::setMarque(bool b){
    marque=b;
}

/*string Sommet::getForme(){
    return forme;
}*/

int Sommet::getNombreSommets()
{
    return nombreSommets;
}


bool Sommet::isMarque(){
    return marque;
}

void *Sommet::sommetToColore(){
    SommetColore* nvSom=new SommetColore(this);
    return nvSom;
}

ostream& operator<<( ostream &flux, const Sommet& som )
{
    const int numero=som.getId();
    flux<<"Sommet n° ";
    flux<<numero;
    flux<<endl;

}
