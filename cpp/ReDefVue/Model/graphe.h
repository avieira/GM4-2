/*!
  * \class Graphe
  * \brief Implementation de la classe Graphe
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see Sommet
  * \see Arete
  */

/**
 * \fn  Graphe(vector<Sommet*> lSommets = vector<Sommet*>() ,vector<Arete*> lArcs = vector<Arete*>() )
 * \brief Constructeur d'un graphe
 * \param vector<Sommet*> lSommets  liste des sommets du graphe
 * \param vector<Arete*> lArcs  liste des aretes du graphe
 * \warning si on omet le parametre lSommets ce sera une liste vide
 * \warning si on omet le parametre lArcs ce sera une liste sans sommet
 */
/**
 * \fn  ~Graphe()
 * \brief Destructeur
 */
/**
 * \fn  void setListeSommets(vector<Sommet*>)
 * \brief Modifier la liste des sommets d'un graphe
 * \param vector<Sommet*> liste des nouveaux sommets du graphe
 */
/**
 * \fn  void setListeArcs(vector<Arete*>)
 * \brief Modifier la liste des aretes d'un graphe
 * \param vector<Arete*> liste des nouvelles aretes du graphe
 */
/**
 * \fn  vector<Sommet*> getListeSommets()
 * \brief Obtenir la liste des sommets du graphe
 * \return vector<Sommet*> liste des sommets du graphe
 */
/**
 * \fn  vector<Arete*> getListeArcs()
 * \brief Obtenir la liste des aretes du graphe
 * \return vector<Arete*> liste des aretes du graphe
 */
 /**
 * \fn  void ajouterSommet(Sommet*)
 * \brief Ajouter un sommet au graphe
 * \param Sommet* pointeur vers le sommet a ajouter
 */
  /**
 * \fn  void ajouterArc(Arete*)
 * \brief Ajouter une arete au graphe
 * \param Arete* pointeur vers l'arete a ajouter
 */
  /**
 * \fn  vector<Sommet*>  obtenirListeAdj(Sommet*)
 * \brief Obtenir la liste d'adjacence d'un sommet du graphe
 * \param Sommet* pointeur vers le sommet dont on veut la liste des sommets adjacents
 * \return vector<Sommet*> liste des pointeurs vers les sommets adjacents au sommet passe en parametre
 */
 /**
 * \fn  void supprSommet(Sommet*)
 * \brief Supprimer un sommet du graphe
 * \param Sommet* pointeur vers le sommet que l'on veut supprimer
 * \todo regarder si le sommet appartient au graphe ou non et gerer cela avec des exceptions
 * \todo ajouter la suppression des aretes liees au sommet qu'on supprime
 */
 /**
 * \fn  friend ostream& operator<<( ostream &flux, Graphe& graph )
 * \brief Redefinition de l'operateur de flux de sortie pour pouvoir afficher les sommets du graphe
 * \todo ajouter l'affichage des aretes du graphe
 */

#ifndef GRAPHE_H
#define GRAPHE_H

#include<vector>
#include"arete.h"

using namespace std;

class Graphe
{
public:
    Graphe(vector<Sommet *> *lSommets = new vector<Sommet*>() , vector<Arete *> *lArcs = new vector<Arete*>() );
    ~Graphe();
    void setListeSommets(vector<Sommet*>*);
    void setListeArcs(vector<Arete*>*);
    vector<Sommet*>* getListeSommets();
    vector<Arete*>* getListeArcs();
    void ajouterSommet(Sommet*);
    void ajouterArc(Arete*);
    vector<const Sommet*>  obtenirListeAdj(Sommet*);

    void supprSommet(Sommet*);

    friend ostream& operator<<( ostream &flux, Graphe& graph );

protected:
    vector<Sommet*>* listeSommets;
    vector<Arete*>* listeArcs;
};

#endif // GRAPHE_H
