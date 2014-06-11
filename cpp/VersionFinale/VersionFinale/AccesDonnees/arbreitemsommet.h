/*!
  * \class ArbreItemSommet
  * \brief Spécialisation de la classe QTreeWidget, pour le pattern Observer
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see XMLTree
  * \see Observer
  * \see QTreeWidgetItem
  * \see Sommet
  *
  * Elément contenu dans l'arbre XMLTree, qui devront être modifiées en fonction des modifications dans le model.
  * Sert ici pour les sommets
  */

#ifndef ARBREITEMSOMMET_H
#define ARBREITEMSOMMET_H

#include <QTreeWidget>
#include "Model/sommetcolore.h"
#include "Obs/Observer.hpp"

class ArbreItemSommet : public QTreeWidgetItem, public Observer
{
public:
    /**
    * \fn ArbreItemSommet(Sommet* sommet, QTreeWidgetItem* parent=0)
    * \brief Constructeur de la classe. Pense à rajouter l'élément à la liste d'observateur du sommet.
    * \param sommet : pointeur vers un sommet associé à cet élément
    * \param parent : Objet parent dans l'arbre
    */
    ArbreItemSommet(Sommet* sommet, QTreeWidgetItem* parent=0);
    /**
    * \fn ArbreItemSommet(Sommet* sommet, QTreeWidget* parent=0)
    * \brief Constructeur de la classe. Pense à rajouter l'élément à la liste d'observateur du sommet.
    * \param sommet : pointeur vers un sommet associé à cet élément
    * \param parent : Objet parent dans l'arbre
    */
    ArbreItemSommet(Sommet* sommet, QTreeWidget* parent=0);
    /**
     * \fn virtual void update()
     * \brief Redéfinition de la méthode d'Observer. Met à jour les informations affichées.
     */
    virtual void update();
    /**
     * \fn virtual void setSommet(void* sommet)
     * \brief Change le sommet en mémoire. Utile en cas de modification du sommet que l'élément doit surveiller.
     * \param sommet Sommet à surveiller
     * \warning Elément en entrée sera castée en sommet !
     */
    virtual void setSommet(void *);

private:
    Sommet* sommet;
};

#endif // ARBREITEMSOMMET_H
