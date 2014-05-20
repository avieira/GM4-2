#ifndef INTERFACEGRAPH_H
#define INTERFACEGRAPH_H

#include <QString>
#include <QStringList>
#include <QHash>
#include <cstdlib>
#include <string>
#include <QDomDocument>
#include <QTreeWidget>
#include"Model/graphecolore.h"


using namespace std;

class InterfaceGraph
{
public:
    InterfaceGraph();
    InterfaceGraph(bool m);

    void* getGraph();
    QStringList getListeForme();
    void setColore(bool coloration);
    bool isColore();

    QString obtenirId(Sommet*);
    Sommet* obtenirSommet(QString);
    QString obtenirForme(Sommet*);
    QTreeWidgetItem* obtenirTreeItem(Sommet*);
    QDomElement* obtenirDomElmt(Sommet*);
    QDomElement* obtenirDomElmt(Arete*);
    QDomElement* obtenirFormDomElmt(Sommet*);

    bool contains(QString);

    bool modifierId(Sommet* sommet, QString nvId);
    bool modifierForme(Sommet* sommet, QString nvlleForme);
    bool modifierTreeItem(Sommet* sommet, QTreeWidgetItem* nvlItem);
    bool modifierElement(Sommet* sommet, QDomElement* nvlElmt);
    bool modifierElement(Arete* arc, QDomElement* nvlElmt);

    void insertSommet(Sommet*sommet, QString id, QString forme="ellipse");
    void insertSommet(Sommet* sommet, QTreeWidgetItem* item);
    void insertSommet(Sommet* sommet, QDomElement* item);

    void grapheToColore();

private:
    Graphe grapheNormal;
    GrapheColore grapheColore;
    bool colore;

    //ID<->Sommet
    QHash<const Sommet*, QString> stringForSommet;
    QHash<QString, Sommet*> sommetForString;
    QHash<const Sommet*,QString> tableForme;

    //XMLTree<->Sommet/Arc TODO
    QHash<const Sommet*, QTreeWidgetItem*> sommetForItem;
    QHash<const Arete*, QTreeWidgetItem*> arcForItem;

    //QDomElement<->Sommet TODO
    QHash<const Sommet*, QDomElement*> sommetForElmt;
    QHash<const Sommet*, QDomElement*> formeSommet;

    //QDomElement<->Arc TODO
    QHash<const Arete*, QDomElement*> areteForElmt;

    QStringList listeFormes;
};

#endif // INTERFACEGRAPH_H
