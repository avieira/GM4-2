#include "xmltree.h"

XMLTree::XMLTree(InterfaceGraph* graph, QWidget *parent):QTreeWidget(parent)
{
    QStringList labels;
    labels << tr("Liste de sommets") << tr("Valeur de l'arguement");

    //header()->setSectionResizeMode(QHeaderView::Stretch);
    setHeaderLabels(labels);

    graphe=graph;
}

void XMLTree::ajouterSommet(Sommet* sommet, QDomElement* elmt){
    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(sommet,parentItem);

    QString title = elmt->attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(*elmt, childItem, sommet);
}

void XMLTree::ajouterSommet(SommetColore* sommet, QDomElement* elmt)
{
    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    QTreeWidgetItem *childItem = createItem(elmt,parentItem);

    QString title = elmt->attribute("id");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    parseElement(*elmt, childItem, sommet);
}

void XMLTree::ajouterArc(Arete* arc, QDomElement* elmt){
    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(1);
    QTreeWidgetItem *childItem = createItem(elmt, parentItem);

    QString title = elmt->tagName();

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
    arcChildItemD->setText(0, QObject::tr("Départ : "));
    arcChildItemD->setText(1, elmt->attribute("Depart"));

    QTreeWidgetItem *arcChildItemG = new QTreeWidgetItem(childItem);
    arcChildItemG->setText(0,QObject::tr("Arrivée : "));
    arcChildItemG->setText(1,elmt->attribute("Arrivee"));

    parseElement(*elmt, childItem, arc);
}

void XMLTree::parseElement(const QDomElement &element,
                           QTreeWidgetItem *parentItem,
                           Sommet *sommet)
{
    QDomElement child = element.firstChildElement();

    while (!child.isNull()) {
        //On ajoute ça au sommet
        if (child.tagName()=="Valeur"){
            /*
            QTreeWidgetItem *childItem = createItem(*sommet, parentItem);

            QString title = child.text();

            childItem->setFlags(parentItem->flags() | Qt::ItemIsSelectable);
            childItem->setText(0, child.tagName()+tr(" : "));
            childItem->setText(1, title);

            SommetValue* sommetValue=(SommetValue*)sommet->sommetToValue();
            sommet=sommetValue;
            sommetColore->setValeur(element.tagName("Valeur"));*/
        } else if (child.tagName()=="Forme"){
            graphe->modifierForme(sommet,element.nodeValue());
        } else if ((child.tagName()=="Couleur")){
            //GROSSE ASTUCE : je veux récupérer le sommet coloré qui correspond à mon sommet précédent. Normalement, en construisant mon graphe coloré,
            //mes sommets gardent le même ID ! Donc, j'utilise ça pour récupérer le bon sommet à colorer :

            //Je récupère l'ID
            QString idSom=graphe->obtenirId(sommet);

            //Je colore le graphe si besoin
            if(!(graphe->isColore()))
                graphe->grapheToColore();

            //Je récupère mon sommet coloré
            SommetColore* sommetColore=(SommetColore*)graphe->obtenirSommet(idSom);

            //Je lui fixe sa couleur !
            QString nvCouleur = QString("#")+child.text();
            sommetColore->setCouleur(nvCouleur.toStdString());
        }

        child = child.nextSiblingElement();
    }
}

void XMLTree::parseElement(const QDomElement &element,
                           QTreeWidgetItem *parentItem,
                           Arete *arc)
{
    QDomElement child = element.firstChildElement();

    while (!child.isNull()) {
        QTreeWidgetItem *childItem = createItem(arc, parentItem);

        QString title = child.text();

        childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
        childItem->setText(0, child.tagName()+tr(" : "));
        childItem->setText(1, title);

        //On ajoute ça à l'arc
        if (element.tagName()=="Valeur"){
            //arc->setValeur(element.tagName().toInt())
        } else if (element.tagName()=="Couleur"){
            //arc->setCouleur(element.tagName().toStdString())
        }

        child = child.nextSiblingElement();
    }
}


QTreeWidgetItem* XMLTree::createItem(const Sommet &element,
                                     QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item;
    if (parentItem) {
        item = new QTreeWidgetItem(parentItem);
    } else {
        item = new QTreeWidgetItem(this);
    }
    sommetForItem.insert(&element, item);

    //TODO : relier sommet->Item pour implémentation Observeur
    return item;
}

QTreeWidgetItem* XMLTree::createItem(const Arete &element,
                                     QTreeWidgetItem *parentItem)
{
    QTreeWidgetItem *item;
    if (parentItem) {
        item = new QTreeWidgetItem(parentItem);
    } else {
        item = new QTreeWidgetItem(this);
    }
    arcForItem.insert(&element, item);

    //TODO : relier arete->Item pour implémentation Observeur
    return item;
}

void XMLTree::changerNom(const Sommet* sommet, QString nvNom)
{
    QTreeWidgetItem* itemSommet=sommetForItem[sommet];
    itemSommet->setText(0,nvNom);
}
