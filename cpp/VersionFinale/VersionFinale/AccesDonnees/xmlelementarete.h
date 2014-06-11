/*!
  * \class XMLElementArete
  * \brief Spécialisation de la classe QDomElement, pour le pattern Observer
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see DocumentXML
  * \see Observer
  * \see QDomElement
  * \see Arete
  *
  * Elément contenu dans le document XML, qui devront être modifiées en fonction des modifications dans le model.
  * Sert ici pour les arêtes
  */

#ifndef XMLELEMENTARETE_H
#define XMLELEMENTARETE_H

#include <QDomDocument>
#include "Obs/Observer.hpp"
#include "Model/arete.h"

class XMLElementArete : public QDomElement, public Observer
{
public:
    /**
    * \fn XMLElementArete(Arete* arete, QDomElement elmt=QDomElement())
    * \brief Constructeur de la classe. Pense à rajouter l'élément à la liste d'observateur de l'arête.
    * \param arete : pointeur vers une arête associé à cet élément
    * \param elmt : Objet copié pour la construction d'un QDomElement
    */
    XMLElementArete(Arete* arete, QDomElement elmt=QDomElement());
    /**
     * \fn virtual void update()
     * \brief Redéfinition de la méthode d'Observer. Met à jour les informations affichées.
     */
    virtual void update();
    /**
     * \fn virtual void setArete(void*)
     * \brief Change l'arête en mémoire. Utile en cas de modification de l'arête que l'élément doit surveiller.
     * \param Arête à surveiller
     * \warning Elément en entrée sera castée en arête !
     */
    virtual void setArete(void *);

private:
    Arete* arc;
};

#endif // XMLELEMENTARETE_H
