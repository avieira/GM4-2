/*!
  * \class ImplemGraphviz
  * \brief Implémentation du programme Graphviz dans un widget affichant un svg
  * \author Alexandre Vieira
  * \version 1.0
  * \date avril 2014
  * \bug to define
  * \warning to define
  *
  * Cette classe se charge de dessiner le graphe en mémoire et de l'afficher dans l'interface graphique. Chaque mise à jour du modèle entraine une mise à jour de la vue. 
  * Seul le contructeur est ici accessible. 
  */


#ifndef ImplemGraphviz_H
#define ImplemGraphviz_H

#include<QGraphicsView>
#include<QHash>
#include <QSvgWidget>
#include<vector>

#include "graphviz/gvc.h"

#include"Model/graphe.h"
#include"Model/grapheoriente.h"
#include"Model/graphecolore.h"


class ImplemGraphviz : public QSvgWidget
{
public:
/**
 * \fn ImplemGraphviz(QWidget *parent = 0, Graphe *graphe=new Graphe())
 * \brief Constructeur de classe pour graphe non orienté
 *
 * \param parent, pointeur sur widget défini par Qt, peut être NULL.
 * \param graph, pointeur sur un Graphe.
 */
    ImplemGraphviz(QWidget *parent = 0, Graphe *graphe=new Graphe());
/**
 * \fn ImplemGraphviz(QWidget *parent = 0, GrapheOriente *graphe=new GrapheOriente())
 * \brief Constructeur de classe pour graphe orienté
 *
 * \param parent, pointeur sur widget défini par Qt, peut être NULL.
 * \param graph, pointeur sur une instance de GrapheOriente.
 */
    ImplemGraphviz(QWidget *parent = 0, GrapheOriente *graphe=new GrapheOriente());
/**
 * \fn drawGraph()
 * \brief Dessine le graph et actualise la vue avec celui-ci.
 */
    void drawGraph();

private:
    Graphe* graphe;
    QString lienSVG;
    Agraph_t* G;
    QHash<Sommet*, Agnode_t*> tableNodes;
    QHash<Arete*, Agedge_t*> tableEdges;

    void creerListeNodes(Graphe *graphe);
    void creerListeNodes(GrapheColore *graphe);
    void creerListeEdges();
};

#endif // ImplemGraphviz_H
