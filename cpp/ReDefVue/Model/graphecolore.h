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

/**
 * \fn  GrapheColore()
 * \brief Constructeur d'un graphe colore
 */
/**
 * \fn  ~GrapheColore()
 * \brief Destructeur d'un graphe colore
 */
/**
 * \fn  void setListeSommets(vector<SommetColore*>)
 * \brief Modifier la liste des sommets du graphe
 * \param vector<SommetColore*> liste des nouveaux sommets du graphe
 */
/**
 * \fn   void ajouterSommet(SommetColore*)
 * \brief ajouter un sommet au graphe
 * \param SommetColore* pointeur vers le sommet a ajouter
 */
 /**
 * \fn   vector<SommetColore*> getListeSommets()
 * \brief Obtenir la liste des sommets du graphe
 * \return vector<SommetColore*> liste des sommets du graphe
 */
 /**
 * \fn   vector<SommetColore*> obtenirListeAdj(SommetColore*)
 * \brief Obtenir la liste des sommets adjacents a un sommet du graphe
 * \param SommetColore* pointeur vers le sommet dont on veut la liste d'adjacence
 * \return vector<SommetColore*> liste des sommets adjacents
 */
 /**
 * \fn   void colorerDirect()
 * \brief colore le graphe par une méthode directe
 * \warning la coloration n'est pas necessairement optimale
 */
 /**
 * \fn   void colorerH(int k)
 * \brief colore le graphe par une méthode heuristique
 * \warning la coloration n'est pas necessairement optimale
 */
  /**
 * \fn   int comparerEtiquettes(set<int> L1, set<int> L2)
 * \brief compare la longueur des etiquettes
 * \warning methode utile pour colorerDirect()
 */
  /**
 * \fn   vector<int> lexBFS()
 * \brief definit un ordre sur les sommets
 * \warning methode utile pour colorerDirect()
 */
   /**
 * \fn    vector<int> inverser(vector<int> ordre)
 * \brief inverse l'ordre
 * \warning methode utile pour colorerDirect()
 */
    /**
 * \fn    void colorerSommets(vector<int>)
 * \brief affecte la bonne couleur aux sommets
 * \warning methode utile pour colorerDirect()
 */

#ifndef GRAPHECOLORE_H
#define GRAPHECOLORE_H

#include"graphe.h"
#include"sommetcolore.h"
#include"Solution.h"
#include<set>
#include<map>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<queue>

class GrapheColore : public Graphe
{
public:
    GrapheColore();
    ~GrapheColore();
    void setListeSommets(vector<SommetColore*>);
    void ajouterSommet(SommetColore*);
    vector<SommetColore*> getListeSommets();

    vector<SommetColore*> obtenirListeAdj(SommetColore*);

    void colorerDirect();
    void colorerH(int k);

    friend ostream& operator<<( ostream &flux, GrapheColore& graph );

protected:
    vector<SommetColore*> listeSommets;

    int comparerEtiquettes(set<int> L1, set<int> L2);
    vector<int> lexBFS();
    vector<int> inverser(vector<int> ordre);
    void colorerSommets(vector<int>);
};

#endif // GRAPHECOLORE_H
