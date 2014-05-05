/*!
  * \class XMlTree
  * \brief Classe servant à afficher différentes informations relatives aux graphes sous forme d'arbre. Sert également à l'importation et à l'exportation.
  * \author Alexandre Vieira
  * \version 1.0
  * \date avril 2014
  * \bug None
  * \warning None
  *
  * Cette classe définit différentes méthodes pour afficher sommets et arcs contenus en mémoire sous forme d'arbre. Il sert églament à traiter les documents XML de façon claire.
  * La structure des documents XML pouvant clairement être vu sous forme d'arbre, l'importation/exportation du graphe sous cette forme de document se fait ici en même temps que l'affichage. Cela permet également de simplifier les changements au niveau du document XML lorsqu'ils arrivent au niveau du modèle.
  * 
  */

#ifndef XMLTREE_H
#define XMLTREE_H

#include <QDomDocument>
#include <QHash>
#include <QIcon>
#include <QTreeWidget>

#include "Model/sommetcolore.h"
#include "Model/sommetvalue.h"
#include "Model/graphe.h"


class XMLTree : public QTreeWidget
{
    Q_OBJECT

public:
/**
 * \fn XMLTree(QWidget *parent = 0, Graphe *graph=new Graphe())
 * \brief Constructeur de la classe
 *
 * \param parent, pointeur sur widget défini par Qt, peut être NULL.
 * \param graph, pointeur sur un Graphe.
 */
    XMLTree(QWidget *parent = 0, Graphe *graph=new Graphe());

/**
 * \fn bool ouvrir(QIODevice *device);
 * \brief Ouverture d'un fichier pour construire le graphe et l'arbre
 *
 * \param device, pointeur sur fichier devant être lu
 */
    bool ouvrir(QIODevice *device);
/**
 * \fn bool enregistrer(QIODevice *device)
 * \brief Enregistrement du graphe et de l'arbre sous forme de document XML
 *
 * \param device, pointeur sur fichier dans lequel sera enregistré le document
 */
    bool enregistrer(QIODevice *device);
/**
 * \fn void ajouterSommet(Sommet*)
 * \brief Ajout du sommet dans le document ainsi que dans l'arbre
 *
 * \param Pointeur vers un sommet
 */
    void ajouterSommet(Sommet*);
/**
 * \fn void ajouterSommet(SommetColore*)
 * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet coloré)
 *
 * \param Pointeur vers un sommet
 */
    void ajouterSommet(SommetColore*);
/**
 * \fn void ajouterSommet(SommetColore*)
 * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet valué)
 *
 * \param Pointeur vers un sommet
 */
    void ajouterSommet(SommetValue*);
/*
 * \fn void ajouterSommet(SommetValueColore*)
 * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet coloré et valué)
 *
 * \param Pointeur vers un sommet
 */
    /*void ajouterSommet(SommetValueColore*);*/
/**
 * \fn void ajouterArc(SommetColore*)
 * \brief Ajout d'un arc dans le document ainsi que dans l'arbre
 *
 * \param Pointeur vers une arête
 */
    void ajouterArc(Arete*);

private slots:
    void updateDomElement(QTreeWidgetItem *item, int column);

private:
    void parseGraphe(const QDomElement &element,
                            QTreeWidgetItem *parentItem = 0);
    void parseElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem,
                            Sommet* sommet);
    void parseElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem,
                            Arete* arc);
    QTreeWidgetItem *createItem(const QDomElement &element,
                                QTreeWidgetItem *parentItem = 0);
    QDomDocument domDocument;
    QHash<QTreeWidgetItem *, QDomElement> domElementForItem;

    Graphe* graphe;
};

#endif // XMLTREE_H
