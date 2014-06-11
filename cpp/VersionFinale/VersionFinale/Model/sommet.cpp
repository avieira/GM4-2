#include "sommet.h"
#include "sommetcolore.h"

int Sommet::nombreSommets=0;

Sommet::Sommet(bool m)
{
    //Les id doivent impérativement commencer à 0 !!
    id=nombreSommets;
    marque=m;
    
    nombreSommets++;

    ostringstream oOStrStream;
    oOStrStream << id;

    string sid("id"+oOStrStream.str());
    nom=QString(sid.c_str());
}

Sommet::~Sommet()
{
    nombreSommets--;
}

int Sommet::getId()
{
    return id;
}

void Sommet::setId(int nvId){
    id=nvId;
}

void Sommet::setMarque(bool b){
    marque=b;
}

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

void operator<<( ostream &flux, Sommet& som )
{
    flux<<"Sommet n° ";
    flux<<som.getId();
    flux<<endl;
}

bool operator== (Sommet som1, Sommet som2){
    return som1.getId()==som2.getId();
}

void Sommet::setForme(QString nvlleForme)
{
    forme=nvlleForme;
    notify();
}

QString Sommet::getForme()
{
    return forme;
}

void Sommet::setNom(QString nvNom)
{
    nom=nvNom;
    notify();
}

QString Sommet::getNom()
{
    return nom;
}
