#include "sommetcolore.h"

/*SommetColore::SommetColore()
{
}*/

SommetColore::SommetColore(Sommet* sommet) : Sommet(sommet->getId(), sommet->getForme())
{

}

string SommetColore::getCouleur()
{
    return couleur;
}

void SommetColore::setCouleur(string coul)
{
    couleur=coul;
}

SommetColore* SommetColore::sommetToColore(){
    return this;
}
