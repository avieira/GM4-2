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

    sommetForElmt.insert(sommet,&elmt);

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

    sommetForElmt.insert(sommet,&elmt);

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

    //arcForElmt.insert(arc,&elmt);

    return &elmt;
}

QDomElement* DocumentXML::changerNom(Sommet* sommet)
{
    QDomElement* domSommet=sommetForElmt[sommet];

    domSommet->setAttribute("id",graphe->obtenirId(sommet));
    //Hé, coco, tu changes pas aussi le nom pour l'arc par hasard ?
    //TODO

    return domSommet;
}

QDomElement* DocumentXML::changerForme(Sommet* sommet)
{
    QDomElement* domSommet=sommetForElmt[sommet];

    QDomElement ancienDomForme=domSommet->firstChildElement("Forme");
    QDomElement newDomForme=createElement(QString("Forme"));
    newDomForme.setNodeValue(graphe->obtenirForme(sommet));

    if(ancienDomForme.isNull())
        domSommet->appendChild(newDomForme);
    else
        replaceChild(newDomForme, ancienDomForme);

    return &newDomForme;
}
