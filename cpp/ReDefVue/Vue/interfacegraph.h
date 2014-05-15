#ifndef INTERFACEGRAPH_H
#define INTERFACEGRAPH_H

#include <QString>
#include <QStringList>
#include <QHash>
#include <QDebug>
#include <cstdlib>
#include <string>
#include"Model/graphecolore.h"

using namespace std;

class InterfaceGraph
{
public:
    InterfaceGraph();

    void* getGraph();
    QStringList getListeForme();
    void setColore(bool coloration);
    bool isColore();

    QString obtenirId(const Sommet*);
    QString obtenirId(const SommetColore*); //TODO
    const Sommet* obtenirSommet(QString);
    QString obtenirForme(Sommet*);
    QString obtenirForme(SommetColore*); //TODO

    bool contains(QString);

    bool modifierId(Sommet* sommet, QString nvId);
    bool modifierId(SommetColore* sommet, QString nvId); //TODO

    bool modifierForme(const Sommet* sommet, QString nvlleForme);
    bool modifierForme(const SommetColore* sommet, QString nvlleForme); //TODO


    void insertSommet(const Sommet*sommet, QString id, QString forme="ellipse");
    void insertSommet(const SommetColore* sommet, QString id, QString forme="ellipse");    //TODO
    void grapheToColore();

private:
    Graphe grapheNormal;
    GrapheColore grapheColore;
    bool colore;

    QHash<QString, const Sommet*> sommetForStringNormal;
    QHash<const Sommet*, QString> stringForSommetColore;

    QHash<QString, const SommetColore*> sommetForStringNormal;
    QHash<const SommetColore*, QString> stringForSommetColore;

    QHash<const Sommet*,QString> tableFormeNormal;
    QHash<const SommetColore*,QString> tableFormeColore;

    QStringList listeFormes;
};

#endif // INTERFACEGRAPH_H
