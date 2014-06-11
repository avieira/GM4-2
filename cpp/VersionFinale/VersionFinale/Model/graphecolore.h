/*!
  * \class GrapheColore
  * \brief Implementation de la classe GrapheColore
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see SommetColore
  * \see Graphe
  * \see Arete
  */

#ifndef GRAPHECOLORE_H
#define GRAPHECOLORE_H

#include"graphe.h"
#include"sommetcolore.h"
#include<QDebug>
#include<set>
#include<map>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<queue>

class GrapheColore : public Graphe
{
public:
    /**
     * \fn  GrapheColore()
     * \brief Constructeur d'un graphe colore
     */
    GrapheColore();
    /**
     * \fn  ~GrapheColore()
     * \brief Destructeur d'un graphe colore
     */
    ~GrapheColore();
    /**
     * \fn  void setListeSommets(vector<SommetColore*> l)
     * \brief Modifier la liste des sommets du graphe
     * \param l liste des nouveaux sommets du graphe
     */
    void setListeSommets(vector<SommetColore*>);
    /**
     * \fn   void ajouterSommet(SommetColore* s)
     * \brief ajouter un sommet au graphe
     * \param s pointeur vers le sommet a ajouter
     */
    void ajouterSommet(SommetColore*);
    /**
     * \fn   vector<SommetColore*> getListeSommets()
     * \brief Obtenir la liste des sommets du graphe
     * \return vector<SommetColore*> liste des sommets du graphe
     */
    vector<SommetColore*> getListeSommets();
    /**
     * \fn   vector<SommetColore*> obtenirListeAdj(SommetColore* s)
     * \brief Obtenir la liste des sommets adjacents a un sommet du graphe
     * \param s pointeur vers le sommet dont on veut la liste d'adjacence
     * \return vector<SommetColore*> liste des sommets adjacents
     */
    vector<SommetColore*> obtenirListeAdj(SommetColore*);

    /**
     * \fn   void colorerDirect()
     * \brief colore le graphe par une méthode directe
     * \warning la coloration n'est pas necessairement optimale
     */
    void colorerDirect();
    /**
    * \fn  void supprSommet(SommetColore* som)
    * \brief Supprimer un sommet du graphe
    * \param som pointeur vers le sommet que l'on veut supprimer
    * \todo regarder si le sommet appartient au graphe ou non et gerer cela avec des exceptions
    * \todo ajouter la suppression des aretes liees au sommet qu'on supprime
    */
    void supprSommet(SommetColore* som);

    /**
     * \fn   bool colorerH()
     * \brief colore le graphe par une méthode heuristique
     * \return bool : True si la coloration a réussi, false sinon
     * \warning la coloration n'est pas necessairement optimale
     * \bug Coloration clairement non opitmale + Bug de temps à autre.
     */
    bool colorerH();


    friend void operator<<( ostream &flux, GrapheColore& graph );
    /**
      * \fn virtual SommetColore* obtenirSommet(QString id)
      * \brief A partir d'un identifiant, on obtient un pointeur vers le sommet correspondant. Suppose que les identifiants sont uniques, ce qui est pris en compte dans le reste du programme
      * \param id : nom de l'identifiant à rechercher.
      * \return SommetColore* : pointeur vers le sommet recherché
    */
    virtual SommetColore* obtenirSommet(QString id);
    /**
      * \fn virtual bool contains(QString id)
      * \brief A partir d'un identifiant, on cherche voir si un sommet correspond à l'identifiant en entrée
      * \param id : nom de l'identifiant à rechercher.
      * \return bool : true si un sommet correspond à cet id, false sinon
    */
    virtual bool contains(QString id);


protected:
    vector<SommetColore*> listeSommets;

    /**
     * \fn   int comparerEtiquettes(set<int> L1, set<int> L2)
     * \brief compare la longueur des etiquettes
     * \warning methode utile pour colorerDirect()
     */
    int comparerEtiquettes(set<int> L1, set<int> L2);
    /**
     * \fn   vector<int> lexBFS()
     * \brief definit un ordre sur les sommets
     * \warning methode utile pour colorerDirect()
     */
    vector<int> lexBFS();
    /**
     * \fn    vector<int> inverser(vector<int> ordre)
     * \brief inverse l'ordre
     * \warning methode utile pour colorerDirect()
     */
    vector<int> inverser(vector<int> ordre);
    /**
     * \fn    void colorerSommets(vector<int>)
     * \brief affecte la bonne couleur aux sommets
     * \warning methode utile pour colorerDirect()
     */
    void colorerSommets(vector<int>);
    /**
     * \fn int appelerH(int k)
     * \brief Donne une coloration du graphe avec le nombre de couleur en entrée
     * \param k : nombre de couleur maximale
     * \return int Cout de la solution
     */
    int appelerH(int k);
};

#endif // GRAPHECOLORE_H
