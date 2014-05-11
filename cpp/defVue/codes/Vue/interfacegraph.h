#ifndef INTERFACEGRAPH_H
#define INTERFACEGRAPH_H

#include <QString>
#include <QStringList>
#include <QHash>
#include"Model/graphecolore.h"

class InterfaceGraph
{
public:
    InterfaceGraph();

    void* getGraph();
    QStringList getListeForme();
    void setColore(bool coloration);
    bool isColore();

    QString obtenirId(Sommet*);
    Sommet* obtenirSommet(QString);
    QString obtenirForme(Sommet*);

    bool contains(QString);

    bool modifierId(Sommet* sommet, QString nvId);
    bool modifierForme(Sommet* sommet, QString nvlleForme);

    void insertSommet(Sommet*sommet, QString id, QString forme="ellipse");
    void grapheToColore();

private:
    Graphe grapheNormal;
    GrapheColore grapheColore;
    bool colore;

    QHash<Sommet*, QString> stringForSommet;
    QHash<QString, Sommet*> sommetForString;
    QHash<Sommet*,QString> tableForme;

    QStringList listeFormes;
};

#endif // INTERFACEGRAPH_H
