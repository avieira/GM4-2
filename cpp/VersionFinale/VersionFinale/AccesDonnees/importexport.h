/*!
  * \class ImportExport
  * \brief Classe servant pour l'importation et l'exportation
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see QDomDocument
  * \see ImportExport
  *
  * Classe définissant les méthodes utiles à l'importation et l'exportation.
  */

#ifndef IMPORTEXPORT_H
#define IMPORTEXPORT_H

#include<QIODevice>
#include<QTreeWidget>
#include<QDomDocument>
#include<QMessageBox>
#include <QHash>
#include <QTextStream>
#include <QDebug>
#include"Model/graphecolore.h"
#include"Vue/xmltree.h"
#include"Vue/implemgraphviz.h"
#include"xmlelementarete.h"
#include"xmlelementsommet.h"

class ImportExport
{
public:
    /**
     * \fn ImportExport(InterfaceGraph* graph, XMLTree* tree, ImplemGraphviz *affichage);
     * \brief Constructeur de classe, réunissant les informations utiles à l'importation princpalement
     * \param graph Pointeur sur une InterfaceGraph pour sa construction
     * \param tree Pointeur sur XMLTree pour sa complétion
     * \param affichage ImplemGraphviz, affichage SVG du graphe, utile pour le patern Observer
     */
    ImportExport(InterfaceGraph* graph, XMLTree* tree, ImplemGraphviz *affichage);

    /**
     * \fn bool ouvrir(QIODevice *device, QDomDocument* domDocument);
     * \brief Ouverture d'un fichier pour construire le graphe et l'arbre
     *
     * \param device pointeur sur fichier devant être lu
     * \param domDocument pointeur sur le document où on va stocker les informations
     */
    bool ouvrir(QIODevice *device, QDomDocument* domDocument);
    /**
     * \fn bool enregistrer(QIODevice *device, QDomDocument* domDocument)
     * \brief Enregistrement du graphe et de l'arbre sous forme de document XML
     *
     * \param device pointeur sur fichier dans lequel sera enregistré le document
     * \param domDocument pointeur sur le document d'où on tire les informations
     */
    static bool enregistrer(QIODevice *device, QDomDocument* domDocument);

private:
    /**
    * \fn void parseGraphe(Graphe* graphe, QDomElement* element, QTreeWidgetItem *parentItem)
    * \brief Récupère les informations utiles dans le document et les ajoute au graphe.
    * \param graphe Pointeur sur le graphe à compléter
    * \param element Element du document d'où on tire les informations
    * \param parentItem Elément de l'arbre où on définit le sommet ou l'arc
    */
    void parseGraphe(Graphe* graphe,
                     QDomElement* element,
                     QTreeWidgetItem *parentItem);
    /**
    * \fn void parseGraphe(Graphe* graphe, QDomElement* element, QTreeWidgetItem *parentItem)
    * \brief Récupère les informations utiles dans le document et les ajoute au graphe.
    * \param graphe Pointeur sur le graphe coloré à compléter
    * \param element Element du document d'où on tire les informations
    * \param parentItem Elément de l'arbre où on définit le sommet ou l'arc
    */
    void parseGraphe(GrapheColore* graphe,
                     QDomElement *element,
                     QTreeWidgetItem *parentItem);

    /**
     * \fn parseElement(const QDomElement &element, QTreeWidgetItem *parentItem, Sommet *sommet)
     * \brief Recherche des informations complémentaires à ajouter au sommet (couleur, forme, ...)
     * \param element Elément du document dont on va fouiller les enfants
     * \param parentItem Elément de l'arbre où est défini le sommet
     * \param sommet Sommet à modifier en fonction des informations trouvées
     */
    void parseElement(const QDomElement &element,
                      QTreeWidgetItem *parentItem,
                      Sommet *sommet);
    /**
     * \fn parseElement(const QDomElement &element, QTreeWidgetItem *parentItem, Arete *arc)
     * \brief Recherche des informations complémentaires à ajouter à l'arête (valeur par exemple)
     * \param element Elément du document dont on va fouiller les enfants
     * \param parentItem Elément de l'arbre où est défini le sommet
     * \param arc Arête à modifier en fonction des informations trouvées
     */
    void parseElement(const QDomElement &element,
                      QTreeWidgetItem *parentItem,
                      Arete* arc);

    InterfaceGraph* graphe;
    XMLTree* arbre;
    ImplemGraphviz* affich;
};

#endif // IMPORTEXPORT_H
