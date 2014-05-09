#include<iostream>
#include "elementfinir2.h"
#include "maillager2.h"
#include "triangle.h"
#include "carre.h"

using namespace std;

int main()
{
    //TESTS SUR LES POINTS
    cout<<"//TESTS SUR LES POINTS//\n";
    SommetR2 *p1 = new SommetR2(1,0,0);
    p1->afficher();

    //TESTS SUR LES TRIANGLES
    cout<<"//TESTS SUR LES TRIANGLES//\n";
    SommetR2 *p2 = new SommetR2(2,1,0);
    SommetR2 *p3 = new SommetR2(3,0,1);
    Triangle *t1= new Triangle(p1,p2,p3);
    cout<<t1->dimension<<"\n";
    t1->afficher();
    p1=p3;
    t1->afficher();
    t1->setSommet(1,p3);
    t1->afficher();
    p2->setAbscisse(23);
    p2->setOrdonnee(23);
    t1->afficher();

    //TESTS SUR LES ELEMENTS FINIS
    cout<<"//TESTS SUR LES ELEMENTS FINIS//\n";
    ElementFiniR2 *e1= new ElementFiniR2(1,t1);
    e1->afficher();

    //TESTS SUR LES MAILLAGES
    cout<<"//TESTS SUR LES ELEMENTS MAILLAGES//\n";
    t1->setSommet(1,p2);
    ElementFiniR2 *e2= new ElementFiniR2(2,t1);
    e2->afficher();
    t1->setSommet(1,p3);
    e2->afficher();
    ElementFiniR2 *e3= new ElementFiniR2(3,t1);
    MaillageR2* m1= new MaillageR2();
    ElementFiniR2 **l = new ElementFiniR2*[3];
    l[0]=e1;
    l[1]=e2;
    l[2]=e3;
    m1->setListeElemFin(l);
    m1->setNombreElemFin(3);
    m1->afficher();
    p3->setAbscisse(234);
    m1->afficher();
    p2=p3;
    m1->afficher();

    //TESTS GENERATION MAILLAGE
    cout<<"//TESTS SUR LA GENERATION DE MAILLAGE//\n";
    SommetR2 *s1 = new SommetR2(1,0,0);
    SommetR2 *s2 = new SommetR2(2,1,0);
    SommetR2 *s3 = new SommetR2(3,1,1);
    SommetR2 *s4 = new SommetR2(4,0,1);
    Carre	 *c  = new Carre(100,s1,s2,s3,s4);
    delete m1;
    m1 = c->mailler(1);
    m1->afficher();

    return 0;
};

