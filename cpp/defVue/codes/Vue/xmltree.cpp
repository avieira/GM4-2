#include "xmltree.h"
#include <QtWidgets>
#include<QUrl>


XMLTree::XMLTree(QWidget *parent, Graphe *graph) : QTreeWidget(parent)
{
    QStringList labels;
    labels << tr("Liste de sommets") << tr("Valeur de l'arguement");

    header()->setSectionResizeMode(QHeaderView::Stretch);
    setHeaderLabels(labels);

    graphe=graph;
}


//Si appelé deuxième fois : ne change pas le DomDoc :(
void XMLTree::updateDomElement(QTreeWidgetItem *item, int column)
{
    QDomElement element = domElementForItem.value(item);
    if (!element.isNull()) {
        if (column == 0) {
            QString text=item->text(0);
            if(text.isEmpty()){
                QDomNode parentDom =element.parentNode();
                parentDom.removeChild(element);

                QTreeWidgetItem *parentTree=item->parent();
                parentTree->removeChild(item);
            } else{
                if (element.tagName()!="Sommet")
                    item->setText(0,element.tagName()+tr(" :"));
                else
                    item->setText(0,element.attribute(QObject::tr("id")));
            }

        } else {
            QDomNode parentDom = element.parentNode();
            QDomElement newElement;
            QDomText newText=domDocument.createTextNode(item->text(1));

            if (element.tagName()=="Valeur"){
                newElement = domDocument.createElement("Valeur");
            } else if (element.tagName()=="Forme"){
                newElement = domDocument.createElement("Forme");
            } else if (element.tagName()=="Couleur"){
                newElement = domDocument.createElement("Couleur");
            }

            newElement.appendChild(newText);
            parentDom.replaceChild(newElement, element);
        }

    }
}

QTreeWidgetItem *XMLTree::createItem(const QDomElement &element,
                                      QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item;
    if (parentItem) {
        item = new QTreeWidgetItem(parentItem);
    } else {
        item = new QTreeWidgetItem(this);
    }
    domElementForItem.insert(item, element);
    return item;
}

void XMLTree::ajouterSommet(Sommet* sommet){
    //Création de l'élément dans le document Dom
    QDomElement elmt=domDocument.createElement("Sommet");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("id"),QString(sommet->getId().c_str()));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt.attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(elmt, childItem, sommet);
}

void XMLTree::ajouterSommet(SommetColore* sommet)
{
    QDomElement elmt=domDocument.createElement("Sommet");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("id"),QString(sommet->getId().c_str()));

    QDomElement couleurElmt=domDocument.createElement("Couleur");
    elmt.appendChild(couleurElmt);
    couleurElmt.appendChild(domDocument.createTextNode(QString(sommet->getCouleur().c_str())));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt.attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(elmt, childItem, sommet);
}

/*void XMLTree::ajouterSommet(SommetValue* sommet)
{
    QDomElement elmt=domDocument.createElement("Sommet");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("id"),QString(sommet->getId().c_str()));

    QDomElement valeurElmt=domDocument.createElement("Valeur");
    elmt.appendChild(valeurElmt);
    valeurElmt.appendChild(domDocument.createTextNode(QString(sommet->getValeur())));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt.attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(elmt, childItem, sommet);
}*/

/*void XMLTree::ajouterSommet(SommetValueColore* sommet, int numId)
{
    QDomElement elmt=domDocument.createElement("Sommet");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Sommets");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("id"),QString(sommet->getId().c_str()));

    QDomElement valeurElmt=domDocument.createElement("Valeur");
    elmt.appendChild(valeurElmt);
    valeurElmt.appendChild(domDocument.createTextNode(QString(sommet->getValeur())));

    QDomElement couleurElmt=domDocument.createElement("Couleur");
    elmt.appendChild(couleurElmt);
    couleurElmt.appendChild(domDocument.createTextNode(QString(sommet->getCouleur().c_str())));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt.attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(elmt, childItem);
}*/

void XMLTree::ajouterArc(Arete* arc){
    //Création de l'élément dans le document Dom
    QDomElement elmt=domDocument.createElement("Arc");

    QDomElement listeDomSommets = domDocument.documentElement().firstChildElement("Arcs");
    listeDomSommets.appendChild(elmt);

    elmt.attribute(QString("Depart"),QString(arc->getDepart()->getId().c_str()));
    elmt.attribute(QString("Arrivee"),QString(arc->getArrivee()->getId().c_str()));

    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(1);
    QTreeWidgetItem *childItem = createItem(elmt, parentItem);

    QString title = elmt.tagName();

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
    arcChildItemD->setText(0, QObject::tr("Départ : "));
    arcChildItemD->setText(1, elmt.attribute("Depart"));

    QTreeWidgetItem *arcChildItemG = new QTreeWidgetItem(childItem);
    arcChildItemG->setText(0,QObject::tr("Arrivée : "));
    arcChildItemG->setText(1,elmt.attribute("Arrivee"));

    parseElement(elmt, childItem, arc);
}

