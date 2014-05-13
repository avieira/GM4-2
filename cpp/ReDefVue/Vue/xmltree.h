#ifndef XMLTREE_H
#define XMLTREE_H

#include<QTreeWidget>
#include<QDomDocument>
#include<QHash>
#include<QHeaderView>
#include"Model/graphecolore.h"
#include"interfacegraph.h"

class XMLTree : public QTreeWidget
{

    Q_OBJECT

public:
    XMLTree(InterfaceGraph* graphe, QWidget *parent = 0);


    /**
     * \fn void ajouterSommet(Sommet*)
     * \brief Ajout du sommet dans le document ainsi que dans l'arbre
     *
     * \param Pointeur vers un sommet
     */
    void ajouterSommet(Sommet*, QDomElement*);
    /**
     * \fn void ajouterSommet(SommetColore*)
     * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet coloré)
     *
     * \param Pointeur vers un sommet
     */
    void ajouterSommet(SommetColore*,QDomElement*);
    /*
     * \fn void ajouterSommet(SommetColore*)
     * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet valué)
     *
     * \param Pointeur vers un sommet
     */
    //void ajouterSommet(SommetValue*);
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
    void ajouterArc(Arete*,QDomElement*);

    void changerNom(const Sommet *sommet, QString nvNom);
    void changerCouleur(const Sommet *sommet);

    QTreeWidgetItem* createItem(const Sommet &element,
                                QTreeWidgetItem *parentItem=0);
    QTreeWidgetItem* createItem(const Arete &element,
                                QTreeWidgetItem *parentItem=0);
    void parseElement(const QDomElement &element,
                      QTreeWidgetItem *parentItem,
                      Sommet *sommet);
    void parseElement(const QDomElement &element,
                      QTreeWidgetItem *parentItem,
                      Arete* arc);


private:
    QHash<const Sommet*, QTreeWidgetItem*> sommetForItem;
    QHash<const Arete*, QTreeWidgetItem*> arcForItem;
    InterfaceGraph* graphe;
};


#endif // XMLTREE_H
