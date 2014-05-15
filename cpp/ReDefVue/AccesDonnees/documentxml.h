#ifndef DOCUMENTXML_H
#define DOCUMENTXML_H

#include <QDomDocument>
#include<QHash>
#include "Vue/xmltree.h"


class DocumentXML : public QDomDocument
{
public:
    DocumentXML(InterfaceGraph* graph);

    /**
         * \fn void ajouterSommet(Sommet*)
         * \brief Ajout du sommet dans le document ainsi que dans l'arbre
         *
         * \param Pointeur vers un sommet
         */
    QDomElement* ajouterSommet(Sommet*, QString);
    /**
         * \fn void ajouterSommet(SommetColore*)
         * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet coloré)
         *
         * \param Pointeur vers un sommet
         */
    QDomElement* ajouterSommet(SommetColore*, QString);
    /*
         * \fn void ajouterSommet(SommetColore*)
         * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet valué)
         *
         * \param Pointeur vers un sommet
         */
    //QDomElement* ajouterSommet(SommetValue*);
    /*
         * \fn void ajouterSommet(SommetValueColore*)
         * \brief Ajout du sommet dans le document ainsi que dans l'arbre (Méthode surchargée pour coller avecun sommet coloré et valué)
         *
         * \param Pointeur vers un sommet
         */
    /*QDomElement* ajouterSommet(SommetValueColore*);*/

    /**
     * \fn void ajouterArc(SommetColore*)
     * \brief Ajout d'un arc dans le document ainsi que dans l'arbre
     *
     * \param Pointeur vers une arête
     */
    QDomElement* ajouterArc(Arete*);

    QDomElement* changerNom(Sommet* sommet);

    QDomElement* changerForme(Sommet* sommet);

private:
    QHash<Sommet*, QDomElement*> sommetForElmt;
    QHash<Sommet*, QDomElement*> formeSommet;
    InterfaceGraph* graphe;
};

#endif // DOCUMENTXML_H
