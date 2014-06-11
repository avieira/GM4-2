#include "xmltree.h"

XMLTree::XMLTree(InterfaceGraph* graph, QWidget *parent):QTreeWidget(parent)
{
    QStringList labels;
    labels << tr("Liste de sommets") << tr("Valeur de l'arguement");

    setHeaderLabels(labels);
    //header()->setSectionResizeMode(QHeaderView::Stretch);

    graphe=graph;
}

void XMLTree::ajouterSommet(Sommet* sommet){
    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(0);
    ArbreItemSommet *childItem = createItem(sommet,parentItem);

    //On affiche les infos qu'il faut
    QString title = sommet->getNom();

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);
}

void XMLTree::ajouterArc(Arete* arc){
    //Ajout à l'arbre
    QTreeWidgetItem *parentItem=topLevelItem(0)->child(1);
    QTreeWidgetItem *childItem = createItem(arc, parentItem);

    //On affiche les infos qu'il faut
    QString title = QString("Arête");

    childItem->setFlags(parentItem->flags() | Qt::ItemIsEditable);
    childItem->setText(0, title);

    QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(childItem);
    arcChildItemD->setText(0, QObject::tr("Départ : "));
    arcChildItemD->setText(1, arc->getDepart()->getNom());

    QTreeWidgetItem *arcChildItemA = new QTreeWidgetItem(childItem);
    arcChildItemA->setText(0,QObject::tr("Arrivée : "));
    arcChildItemA->setText(1,arc->getArrivee()->getNom());
}

ArbreItemSommet* XMLTree::createItem(Sommet *element,
                                     QTreeWidgetItem *parentItem)
{
    ArbreItemSommet *item;
    if (parentItem) {
        item = new ArbreItemSommet(element, parentItem);
    } else {
        item = new ArbreItemSommet(element, this);
    }

    return item;
}

ArbreItemArete *XMLTree::createItem(Arete *element,
                                     QTreeWidgetItem *parentItem)
{
    ArbreItemArete *item;
    if (parentItem) {
        item = new ArbreItemArete(element, parentItem);
    } else {
        item = new ArbreItemArete(element, this);
    }

    return item;
}
