/*!
  * \class XMLElementSommet
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
  * \see Sommet
  *
  * Elément contenu dans le document XML, qui devront être modifiées en fonction des modifications dans le model.
  * Sert ici pour les sommets.
  */

#ifndef XMLELEMENTSOMMET_H
#define XMLELEMENTSOMMET_H

#include <QDomDocument>
#include<QDebug>
#include "Obs/Observer.hpp"
#include "Model/sommetcolore.h"
#include "Vue/interfacegraph.h"

class XMLElementSommet : public QDomElement, public Observer
{
public:
    /**
    * \fn XMLElementSommet(Sommet *som, QDomElement &domElmt, InterfaceGraph* graph)
    * \brief Constructeur de la classe. Pense à rajouter l'élément à la liste d'observateur du sommet. Prend un graph en entrée, utile pour les méthodes.
    * \param som : pointeur vers un sommet associé à cet élément
    * \param domElmt : Objet copié pour la construction d'un QDomElement
    * \param graph : pointeur vers une InterfaceGraph
    */
    XMLElementSommet(Sommet *som, QDomElement &domElmt, InterfaceGraph* graph);
    /**
     * \fn virtual void update()
     * \brief Redéfinition de la méthode d'Observer. Met à jour les informations affichées.
     */
    virtual void update();
    /**
     * \fn virtual void setSommet(void*)
     * \brief Change le sommet en mémoire. Utile en cas de modification du sommet que l'élément doit surveiller.
     * \param Sommet à surveiller
     * \warning Elément en entrée sera castée en sommet !
     * \bug Valeurs des éléments correspondants jamais changées... :(
     */
    virtual void setSommet(void*);

private:
    Sommet* sommet;
    InterfaceGraph* graph;
};

#endif // XMLELEMENTSOMMET_H
