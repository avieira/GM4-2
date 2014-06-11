#include "arbreitemarete.h"

ArbreItemArete::ArbreItemArete(Arete* arete, QTreeWidgetItem *parent) : QTreeWidgetItem(parent)
{
    arc=arete;
    arc->addObserver(this);
}

ArbreItemArete::ArbreItemArete(Arete* arete, QTreeWidget* parent) : QTreeWidgetItem(parent)
{
    arc=arete;
    arc->addObserver(this);
}

void ArbreItemArete::setArete(void* arete)
{
    arc=(Arete*)arete;
}

void ArbreItemArete::update()
{
    //On enlève tout
    takeChildren();

    //Et on recommence
    QTreeWidgetItem *arcChildItemD = new QTreeWidgetItem(this);
    arcChildItemD->setText(0, QObject::tr("Départ : "));
    arcChildItemD->setText(1, arc->getDepart()->getNom());

    QTreeWidgetItem *arcChildItemA = new QTreeWidgetItem(this);
    arcChildItemA->setText(0,QObject::tr("Arrivée : "));
    arcChildItemA->setText(1,arc->getArrivee()->getNom());
}
