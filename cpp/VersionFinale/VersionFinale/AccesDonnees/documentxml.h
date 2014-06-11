/*!
  * \class DocumentXML
  * \brief Spécialisation de la classe QDomDocument
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see QDomDocument
  * \see ImportExport
  *
  * Définition du document XML définissant le graphe. Sert pour l'importation et l'exportation.
  */

#ifndef DOMDOCUMENT_H
#define DOMDOCUMENT_H

#include <QDomDocument>
#include "xmlelementsommet.h"
#include "xmlelementarete.h"
#include "Vue/interfacegraph.h"

class DocumentXML : public QDomDocument
{
public:
    /**
     * \fn DocumentXML(InterfaceGraph* graph)
     * \brief Constructeur de classe
     * \param graph pointeur vers InterfaceGraph, utile pour aller rechercher les informations dans les méthodes.
     */
    DocumentXML(InterfaceGraph* graph);

    /**
     * \fn void ajouterSommet(Sommet* som, QString str)
     * \brief Ajout du sommet dans le document ainsi que dans l'arbre
     * \param som Pointeur vers un sommet
     * \param str Nom du nouveau sommet
     */
    void ajouterSommet(Sommet*, QString);
    /**
     * \fn void ajouterSommet(SommetColore* som, QString str)
     * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet coloré)
     * \param som Pointeur vers un sommet
     * \param str nom du nouveau sommet
     */
    void ajouterSommet(SommetColore*, QString);
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
     * \fn void ajouterArc(Arete*)
     * \brief Ajout d'un arc dans le document ainsi que dans l'arbre
     * \param Pointeur vers une arête
     */
    void ajouterArc(Arete*);

private:
    InterfaceGraph* graphe;
};

#endif // DOMDOCUMENT_H
