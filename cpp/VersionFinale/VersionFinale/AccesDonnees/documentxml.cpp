#include "documentxml.h"

DocumentXML::DocumentXML(InterfaceGraph* graph)
{
    graphe=graph;
}

void DocumentXML::ajouterSommet(Sommet* sommet, QString id){
    //Création de l'élément dans le document Dom
    QDomElement qElmt=ownerDocument().createElement("Sommet");
    XMLElementSommet *elmt=new XMLElementSommet(sommet,qElmt,graphe);
    QDomElement listeDomSommets = documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(*elmt);

    //On fixe la valeur affichée
    elmt->setAttribute(QString("id"),id);
}

void DocumentXML::ajouterSommet(SommetColore* sommet, QString id)
{
    QDomElement qElmt=ownerDocument().createElement("Sommet");
    XMLElementSommet *elmt=new XMLElementSommet(sommet,qElmt,graphe);
    QDomElement listeDomSommets = documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(*elmt);

    //On fixe la valeur affichée
    elmt->setAttribute(QString("id"),id);

    QDomElement couleurElmt=createElement("Couleur");
    elmt->appendChild(couleurElmt);
    string couleur="#"+sommet->getCouleur();
    couleurElmt.appendChild(createTextNode(QString(couleur.c_str())));
}

void DocumentXML::ajouterArc(Arete* arc){
    //Création de l'élément dans le document Dom
    XMLElementArete elmt(arc, createElement("Arc"));


    //Affichage départ et arrivée
    QDomElement listeDomSommets = documentElement().firstChildElement("Arcs");
    listeDomSommets.appendChild(elmt);

    QString depart=arc->getDepart()->getNom();
    QString arrivee=arc->getArrivee()->getNom();
    elmt.attribute(QString("Depart"),depart);
    elmt.attribute(QString("Arrivee"),arrivee);
}
