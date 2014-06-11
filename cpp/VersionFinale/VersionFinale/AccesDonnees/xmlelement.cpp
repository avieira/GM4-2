#include "xmlelement.h"

XMLElement::XMLElement(Sommet* som, bool couleur) : QDomDocument()
{
    sommet=som;
    colore=couleur;
}

void XMLElementSommet::update()
{
    //On réaffecte l'ID :
    setAttribute(QString("id"),sommet->getNom());

    //De même avec la forme :
    QDomElement ancienDomForme=firstChildElement("Forme");
    QDomElement newDomForme=createElement(QString("Forme"));
    newDomForme.setNodeValue(sommet->getForme());

    if(ancienDomForme.isNull())
        domSommet->appendChild(newDomForme);
    else
        replaceChild(newDomForme, ancienDomForme);

    //Si c'est coloré, on s'en occupe :
    if(colore){
        SommetColore* sommetColore=(SommetColore*) sommet;
        QDomElement ancienDomCouleur=firstChildElement("Couleur");
        QDomElement newDomCouleur=createElement(QString("Couleur"));
        newDomForme.setNodeValue(QString(sommetColore->getCouleur()));
        if(ancienDomCouleur.isNull())
            domSommet->appendChild(newDomCouleur);
        else
            replaceChild(newDomCouleur, ancienDomCouleur);

    }
}
