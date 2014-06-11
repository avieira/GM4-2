/*!
  * \class XMLTree
  * \brief Spécialisation d'un QTreeWidget de Qt pour l'affichage des sommets et des arêtes sous la forme d'un arbre
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date avril 2014
  *
  * Spécialisation d'un QTreeWidget de Qt pour l'affichage des sommets et des arêtes sous la forme d'un arbre.
  * Les éléments sont égalements spécialisés et héritent de QTreeWigdetItem. La plupart sont observales pour être mis à jour
  *
  * \see ArbreItemArete
  * \see ArbreItemSommet
*/

#ifndef XMLTREE_H
#define XMLTREE_H

#include<QTreeWidget>
#include<QDomDocument>
#include<QHash>
#include<QHeaderView>
#include"interfacegraph.h"
#include"AccesDonnees/arbreitemsommet.h"
#include"AccesDonnees/arbreitemarete.h"

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
    void ajouterSommet(Sommet*);
    /**
     * \fn void ajouterArc(SommetColore*)
     * \brief Ajout d'un arc dans le document ainsi que dans l'arbre
     *
     * \param Pointeur vers une arête
     */
    void ajouterArc(Arete*);

    /**
     * \fn ArbreItemSommet* createItem(Sommet *element, QTreeWidgetItem *parentItem=0)
     * \brief Crée un pointeur sur ArbreItemSommet à partir d'élément et de parentItem. L'élément créé sera ainsi fils de parentItem et lié au pointeur sur Sommet
     *
     * \param Pointeur vers un sommet
     * \param Pointeur vers un élément de l'arbre servant de père
     * \return Pointeur sur l'élément fils nouvellement créé
     */
    ArbreItemSommet* createItem(Sommet *element,
                                QTreeWidgetItem *parentItem=0);
    /**
     * \fn ArbreItemArete* createItem(Arete *element, QTreeWidgetItem *parentItem=0)
     * \brief Crée un pointeur sur ArbreItemArete à partir d'élément et de parentItem. L'élément créé sera ainsi fils de parentItem et lié au pointeur sur Arete
     *
     * \param Pointeur vers une arête
     * \param Pointeur vers un élément de l'arbre servant de père
     * \return Pointeur sur l'élément fils nouvellement créé
     */
    ArbreItemArete* createItem(Arete *element,
                                QTreeWidgetItem *parentItem=0);

private:
    InterfaceGraph* graphe;
};


#endif // XMLTREE_H
