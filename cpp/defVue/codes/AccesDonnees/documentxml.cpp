#include "documentxml.h"

DocumentXML::DocumentXML(InterfaceGraph* graph)
{
    graphe=graph;
}

QDomElement* DocumentXML::ajouterSommet(Sommet* sommet, QString id){
    //Création de l'élément dans le document Dom
    QDomElement elmt=createElement("Sommet");

    QDomElement listeDomSommets = documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.setAttribute(QString("id"),id);

    return &elmt;
}

QDomElement* DocumentXML::ajouterSommet(SommetColore* sommet, QString id)
{
    QDomElement elmt=createElement("Sommet");

    QDomElement listeDomSommets = documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.setAttribute(QString("id"),id);

    QDomElement couleurElmt=createElement("Couleur");
    elmt.appendChild(couleurElmt);
    string couleur="#"+sommet->getCouleur();
    couleurElmt.appendChild(createTextNode(QString(couleur.c_str())));

    return &elmt;
}

QDomElement* DocumentXML::ajouterArc(Arete* arc){
    //Création de l'élément dans le document Dom
    QDomElement elmt=createElement("Arc");

    QDomElement listeDomSommets = documentElement().firstChildElement("Arcs");
    listeDomSommets.appendChild(elmt);

    QString depart=graphe->obtenirId(arc->getDepart());
    QString arrivee=graphe->obtenirId(arc->getArrivee());
    elmt.attribute(QString("Depart"),depart);
    elmt.attribute(QString("Arrivee"),arrivee);

    return &elmt;
}
