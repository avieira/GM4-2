/*!
  * \class ImplemGraphviz
  * \brief Implémentation du programme Graphviz dans un widget affichant un svg
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \warning Nécessite la bibliothèque Graphviz : http://www.graphviz.org/Download.php
  * \version 1.0
  * \date avril 2014
  * \bug Non thread safe, l'accumulation d'update ne fonctionne pas. Impossible d'utiliser l'observer sur cette classe dans l'état.
  *
  * Cette classe se charge de dessiner le graphe en mémoire et de l'afficher dans l'interface graphique. Chaque mise à jour du modèle entraine une mise à jour de la vue.
  *
  * \see Observer
  * \see QSvgWidget
  */


#ifndef ImplemGraphviz_H
#define ImplemGraphviz_H

#include<QGraphicsView>
#include<QHash>
#include <QSvgWidget>
#include<QDebug>
#include<vector>
#include <iostream>

#include "graphviz/gvc.h"

#include"Model/graphe.h"
//#include"Model/grapheoriente.h"
#include"Model/graphecolore.h"
#include"interfacegraph.h"
#include"Obs/Observer.hpp"

using namespace std;

class ImplemGraphviz : public QSvgWidget, public Observer
{
public:
/**
 * \fn ImplemGraphviz(QWidget *parent = 0, Graphe *graphe=new Graphe())
 * \brief Constructeur de classe pour graphe non orienté
 *
 * \param parent pointeur sur widget défini par Qt, peut être NULL.
 * \param graph pointeur sur un Graphe.
 */
    ImplemGraphviz(InterfaceGraph* graph, QWidget *parent = 0);
/**
 * \fn drawGraph()
 * \brief Dessine le graph et actualise la vue avec celui-ci.
 */
    void drawGraph();

    /**
     * \fn virtual void update()
     * \brief Met à jour le dessin. Ne fait qu'appeler la méthode drawGraph()
     * \see drawGraph()
     */
    virtual void update();

private:
    QString lienSVG;
    Agraph_t* G;
    QHash<Sommet*, Agnode_t*> tableNodes;
    QHash<Arete*, Agedge_t*> tableEdges;
    InterfaceGraph* graphe;

    /**
     * \fn void creerListeNodes(Graphe *graphe)
     * \brief Crée la liste des sommets utile à GraphViz pour générer le dessin d'un graphe.
     * \param graphe : pointeur sur un graphe non coloré où sont définis arêtes et sommets
     */
    void creerListeNodes(Graphe *graphe);
    /**
     * \fn void creerListeNodes(GrapheColore *graphe);
     * \brief Crée la liste des sommets utile à GraphViz pour générer le dessin d'un graphe.
     * \param graphe : pointeur sur un graphe coloré où sont définis arêtes et sommets
     */
    void creerListeNodes(GrapheColore *graphe);
    /**
     * \fn void creerListeEdges(Graphe* graphe)
     * \brief Crée la liste des arêtes utile à GraphViz pour générer le dessin d'un graphe
     * \param graphe : pointeur sur un graphe où sont définis arêtes et sommets
     */
    void creerListeEdges(Graphe* graphe);
};

#endif // ImplemGraphviz_H
