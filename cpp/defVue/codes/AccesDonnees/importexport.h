#ifndef IMPORTEXPORT_H
#define IMPORTEXPORT_H

#include<QIODevice>
#include<QTreeWidget>
#include<QDomDocument>
#include<QMessageBox>
#include <QHash>
#include <QTextStream>
#include"Model/graphecolore.h"
#include"Vue/xmltree.h"

class ImportExport
{
public:
    ImportExport(InterfaceGraph* graph, XMLTree* tree);

    /**
     * \fn bool ouvrir(QIODevice *device);
     * \brief Ouverture d'un fichier pour construire le graphe et l'arbre
     *
     * \param device, pointeur sur fichier devant être lu
     */
    bool ouvrir(QIODevice *device, QDomDocument* domDocument);
    /**
     * \fn bool enregistrer(QIODevice *device)
     * \brief Enregistrement du graphe et de l'arbre sous forme de document XML
     *
     * \param device, pointeur sur fichier dans lequel sera enregistré le document
     */
    static bool enregistrer(QIODevice *device, QDomDocument* domDocument);

private:
    void parseGraphe(Graphe* graphe,
                     const QDomElement &element,
                     QTreeWidgetItem *parentItem);
    void parseGraphe(GrapheColore* graphe,
                     const QDomElement &element,
                     QTreeWidgetItem *parentItem);

    InterfaceGraph* graphe;
    XMLTree* arbre;
};

#endif // IMPORTEXPORT_H
