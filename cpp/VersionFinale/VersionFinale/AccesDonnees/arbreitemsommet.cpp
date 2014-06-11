#include "arbreitemsommet.h"

ArbreItemSommet::ArbreItemSommet(Sommet *som, QTreeWidgetItem *parent) : QTreeWidgetItem(parent)
{
    sommet=som;
    som->addObserver(this);
}

ArbreItemSommet::ArbreItemSommet(Sommet* som, QTreeWidget* parent) : QTreeWidgetItem(parent)
{
    sommet=som;
    som->addObserver(this);
}

void ArbreItemSommet::setSommet(void* som)
{
    sommet=(Sommet*)som;
}

void ArbreItemSommet::update()
{
    setText(0,sommet->getNom());
}
