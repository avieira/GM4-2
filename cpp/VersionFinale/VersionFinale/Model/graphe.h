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

#ifndef GRAPHE_H
#define GRAPHE_H

#include<vector>
#include"arete.h"

using namespace std;

class Graphe
{
public:
    /**
     * \fn  Graphe(vector<Sommet*> lSommets = vector<Sommet*>() ,vector<Arete*> lArcs = vector<Arete*>() )
     * \brief Constructeur d'un graphe
     * \param lSommets  liste des sommets du graphe
     * \param lArcs  liste des aretes du graphe
     * \warning si on omet le parametre lSommets ce sera une liste vide
     * \warning si on omet le parametre lArcs ce sera une liste sans sommet
     */
    Graphe(vector<Sommet*> lSommets = vector<Sommet*>() ,vector<Arete*> lArcs = vector<Arete*>() );
    /**
     * \fn  ~Graphe()
     * \brief Destructeur
     */
    ~Graphe();
    /**
     * \fn  void setListeSommets(vector<Sommet*> l)
     * \brief Modifier la liste des sommets d'un graphe
     * \param l liste des nouveaux sommets du graphe
     */
    void setListeSommets(vector<Sommet*>);
    /**
     * \fn  void setListeArcs(vector<Arete*> l)
     * \brief Modifier la liste des aretes d'un graphe
     * \param l liste des nouvelles aretes du graphe
     */
    void setListeArcs(vector<Arete*>);
    /**
     * \fn  vector<Sommet*> getListeSommets()
     * \brief Obtenir la liste des sommets du graphe
     * \return vector<Sommet*> liste des sommets du graphe
     */
    vector<Sommet*> getListeSommets();
    /**
     * \fn  vector<Arete*> getListeArcs()
     * \brief Obtenir la liste des aretes du graphe
     * \return vector<Arete*> liste des aretes du graphe
     */
    vector<Arete*> getListeArcs();
    /**
    * \fn  void ajouterSommet(Sommet* sommet)
    * \brief Ajouter un sommet au graphe
    * \param sommet pointeur vers le sommet a ajouter
    */
    void ajouterSommet(Sommet*);
   /**
   * \fn  void ajouterArc(Arete* arc)
   * \brief Ajouter une arete au graphe
   * \param arc pointeur vers l'arete a ajouter
   */
    void ajouterArc(Arete*);
    /**
   * \fn  vector<Sommet*>  obtenirListeAdj(Sommet* som)
   * \brief Obtenir la liste d'adjacence d'un sommet du graphe
   * \param som pointeur vers le sommet dont on veut la liste des sommets adjacents
   * \return vector<Sommet*> liste des pointeurs vers les sommets adjacents au sommet passe en parametre
   */
    vector<Sommet*>  obtenirListeAdj(Sommet*);

    /**
    * \fn  void supprSommet(Sommet* som)
    * \brief Supprimer un sommet du graphe
    * \param som pointeur vers le sommet que l'on veut supprimer
    * \todo regarder si le sommet appartient au graphe ou non et gerer cela avec des exceptions
    * \todo ajouter la suppression des aretes liees au sommet qu'on supprime
    */
    void supprSommet(Sommet*);
    /**
    * \fn void notifyArete(Sommet* som);
    * \brief En cas de changement au niveau d'un sommet, on demande à toutes les arêtes connectées à ce sommet de se mettre à jour.
    * \param som pointeur vers le sommet modifié
    */
    void notifyArete(Sommet*);
    /**
     * \fn  friend ostream& operator<<( ostream &flux, Graphe& graph )
     * \brief Redefinition de l'operateur de flux de sortie pour pouvoir afficher les sommets du graphe
     * \todo ajouter l'affichage des aretes du graphe
     */
    friend void operator<<( ostream &flux, Graphe& graph );

    /**
      * \fn virtual Sommet* obtenirSommet(QString id)
      * \brief A partir d'un identifiant, on obtient un pointeur vers le sommet correspondant. Suppose que les identifiants sont uniques, ce qui est pris en compte dans le reste du programme
      * \param id : nom de l'identifiant à rechercher.
      * \return Sommet* : pointeur vers le sommet recherché
    */
    virtual Sommet* obtenirSommet(QString id);
    /**
      * \fn virtual bool contains(QString id)
      * \brief A partir d'un identifiant, on cherche voir si un sommet correspond à l'identifiant en entrée
      * \param id : nom de l'identifiant à rechercher.
      * \return bool : true si un sommet correspond à cet id, false sinon
    */
    virtual bool contains(QString id);

protected:
    vector<Sommet*> listeSommets;
    vector<Arete*> listeArcs;
};

#endif // GRAPHE_H
