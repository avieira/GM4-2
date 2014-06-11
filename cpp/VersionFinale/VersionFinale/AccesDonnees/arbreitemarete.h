/*!
  * \class ArbreItemArete
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
  * \see Arete
  *
  * Elément contenu dans l'arbre XMLTree, qui devront être modifiées en fonction des modifications dans le model.
  * Sert ici pour les arête
  */


#ifndef ARBREITEMARETE_H
#define ARBREITEMARETE_H

#include <QTreeWidget>
#include "Model/arete.h"
#include "Obs/Observer.hpp"

class ArbreItemArete : public QTreeWidgetItem, public Observer
{
public:
    /**
    * \fn ArbreItemArete(Arete* arete, QTreeWidgetItem* parent=0)
    * \brief Constructeur de la classe. Pense à rajouter l'élément à la liste d'observateur de l'arête.
    * \param arete : pointeur vers une arête associé à cet élément
    * \param parent : Objet parent dans l'arbre
    */
    ArbreItemArete(Arete* arete, QTreeWidgetItem* parent=0);
    /**
    * \fn ArbreItemArete(Arete* arete, QTreeWidget* parent=0)
    * \brief Constructeur de la classe. Pense à rajouter l'élément à la liste d'observateur de l'arête.
    * \param arete : pointeur vers une arête associé à cet élément
    * \param parent : Objet parent dans l'arbre
    */
    ArbreItemArete(Arete* arete, QTreeWidget* parent=0);
    /**
     * \fn virtual void update()
     * \brief Redéfinition de la méthode d'Observer. Met à jour les informations affichées.
     */
    virtual void update();
    /**
     * \fn virtual void setArete(void* arete)
     * \brief Change l'arête en mémoire. Utile en cas de modification de l'arête que l'élément doit surveiller.
     * \param arete Arête à surveiller
     * \warning Elément en entrée sera castée en arête !
     */
    virtual void setArete(void*);

private:
    Arete* arc;
};

#endif // ARBREITEMARETE_H
