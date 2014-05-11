#ifndef SOMMET_H
#define SOMMET_H

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Sommet
{
public:
    Sommet(bool m=false);
    ~Sommet();

    void setId(int);
    void setMarque(bool b);
    int getId();
    bool isMarque();
    int getNombreSommets();

    virtual void* sommetToColore();
    
    friend ostream& operator<<( ostream &flux, Sommet& som );

    //void setForme(string);
    //string getForme();
    //void setNom(string);
    //string getNom();

protected:
    int id;
    static int nombreSommets;
    bool marque;

    //string nom;
    //string forme;
};

#endif // SOMMET_H
