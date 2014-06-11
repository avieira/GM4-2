/*!
  * \class InterfaceGraph
  * \brief Pont entre l'interface graphique et le graphe dans le modèle
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet

  * \version 1.0
  * \date mai 2014
  *
  * Classe servant à faire le lien entre le graphe réellement utilisé et l'interface graphique. Cela simplifie ainsi l'obtention du bon graphe, la coloration et
  * toute autre modification à faire à ce niveau.
  *
  * \see Graphe
  * \see GrapheColore
  */


#ifndef INTERFACEGRAPH_H
#define INTERFACEGRAPH_H

#include <QString>
#include <QStringList>
#include <cstdlib>
#include <string>
#include"Model/graphecolore.h"

class InterfaceGraph
{
public:
    /**
     * \fn InterfaceGraph
     * \brief Constructeur par défaut
     */
    InterfaceGraph();

    /**
     * \fn void* getGraph()
     * \brief Renvoie un pointeur sur le graphe en cours. A caster en fonction du résultat de isColore()
     * \return Pointeur sur le graphe en cours
     * \warning Caster le résultat !
     * \see isColore()
     */
    void* getGraph();
    /**
     * \fn QStringList getListeForme()
     * \brief Retourne la liste des formes définies pour ce programme pour les sommets
     * \return Liste des formes définies.
     */
    QStringList getListeForme();
    /**
     * \fn void setColore(bool coloration)
     * \brief Remettre le fait que le graphe soit colore à vrai ou faux
     * \param coloration : true si le graphe doit être coloré, false sinon
     */
    void setColore(bool coloration);
    /**
     * \fn bool isColore()
     * \brief Retourne un booléen si le graphe est coloré ou non
     * \return true si le graph est coloré, false sinon
     */
    bool isColore();

    /**
     * \fn grapheToColore()
     * \brief Transforme le graphe en cours en un graphe coloré
     */
    void grapheToColore();
    /**
     * \fn void colorerGraphD()
     * \brief Appelle la méthode de coloration directe sur le graphe, en le transformant au préalable si besoin.
     */
    void colorerGraphD();
    /**
     * \fn bool colorerGraphH()
     * \brief Appelle la méthode de coloration heuristique sur le graphe, en le transformant au préalable si besoin.
     * \return bool false si la coloration a échoué, true sinon
     */
    bool colorerGraphH();

    /**
     * \fn bool contains(QString id)
     * \brief Retourne un booléen donnant le fait que le graphe contienne un sommet avec le nom id ou non.
     * \param id : identifiant à retrouver
     * \return true si le graphe a un sommet nommé id, false sinon.
     */
    bool contains(QString id);

private:
    Graphe grapheNormal;
    GrapheColore grapheColore;
    bool colore;
    QStringList listeFormes;
};

#endif // INTERFACEGRAPH_H
