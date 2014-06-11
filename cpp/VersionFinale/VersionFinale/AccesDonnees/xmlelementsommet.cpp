#include "xmlelementsommet.h"

XMLElementSommet::XMLElementSommet(Sommet* som, QDomElement &domElmt, InterfaceGraph* graphe) : QDomElement(domElmt)
{
    sommet=som;
    graph=graphe;

    //Ajout à la liste des observeurs du sommet
    sommet->addObserver(this);
}

void XMLElementSommet::setSommet(void* som)
{
    sommet=(Sommet*)som;
}

void XMLElementSommet::update()
{
    //On réaffecte l'ID :
    setAttribute(QString("id"),sommet->getNom());

    //De même avec la forme :
    QDomElement ancienDomForme=firstChildElement("Forme");
    QDomElement newDomForme=ownerDocument().createElement(QString("Forme"));
    newDomForme.setNodeValue(sommet->getForme());

    if(ancienDomForme.isNull())
        appendChild(newDomForme);
    else
        replaceChild(newDomForme, ancienDomForme);

    //Si c'est coloré, on s'en occupe :
    if(graph->isColore()){
        SommetColore* sommetColore=(SommetColore*) sommet;
        QDomElement ancienDomCouleur=firstChildElement("Couleur");
        QDomElement newDomCouleur=ownerDocument().createElement(QString("Couleur"));
        newDomForme.setNodeValue(QString(sommetColore->getCouleur().c_str()));
        if(ancienDomCouleur.isNull())
            appendChild(newDomCouleur);
        else
            replaceChild(newDomCouleur, ancienDomCouleur);

    }
}
