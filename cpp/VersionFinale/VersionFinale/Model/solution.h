/*!
  * \class Solution
  * \brief Sert pour la coloration heuristique, génère des solutions acceptables aléatoirement
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see GrapheColore
  */

#ifndef __SOLUTION_h__
#define __SOLUTION_h__

#include<vector>
#include<time.h>
#include<deque>
#include<stdlib.h>

#include "Model/graphecolore.h"

using namespace std;

class Solution{
private :
    int nbCouleurs;
    vector<int> leTableau;
    Sommet* sommetModifie;
    int cout;
    GrapheColore* graphe;

public :
    /**
      * \fn Solution(int k, vector<int> tab, GrapheColore* graphe)
      * \brief Constructeur de Solution
      * \param int k : le nombre de couleurs utilisées dans la Solution
      * \param tab : tableau affichant dans la iè case le numéro de la couleur qui colore le iè sommet
      * \param graphe : graphe sur lequel s'appuye la solution
    */
    Solution(int k, vector<int> tab, GrapheColore *graphe);
    /**
      * \fn int calculerCout()
      * \brief calcule le coût d'une solution, c'est à dire, le nombre de Sommets adjacents de même couleur
    */
    int calculerCout();
    /**
      * \fn vector<SommetColore *> calculerSommetsModifiables();
      * \brief Repère les sommets dont la coloration n'est pas admissible et les retourne.
      * \return vector<SommetColore*> : vector contenant les sommets d'une coloration non acceptable
    */
    vector<SommetColore *> calculerSommetsModifiables();
    /**
      * \fn Solution genererSolVoisine(vector<SommetColore *> sommetsModifiables)
      * \brief  Génère une solution "proches"
      * \return Solution : la Solution proche obtenue
    */
    Solution *genererSolVoisine(vector<SommetColore *> sommetsModifiables);
    /**
      * \fn bool appartientA(deque<Solution*> T)
      * \brief Vérifie que la solution en cours appartient bien à cette liste de solution
      * \param T : file de pointeurs sur Solutions
      * \return bool : true si la solution appartient à la pile, faux sinon
    */
    bool appartientA(deque<Solution *> *T);
    /**
      * \fn void setCout(int nvCout)
      * \brief Définit le cout de la solution
      * \param int nvCout : nouveau cout de la solution
    */
    void setCout(int nvCout);
    /**
      * \fn int getCout()
      * \brief Retourne le cout de la solution
      * \return int : cout actuel de la solution
    */
    int getCout();
    /**
     * \fn void setIemeCouleur(int indiceModif, int couleurModif)
     * \brief Modifie la coleur corresspondant à l'entier d'indice dans le tableau
     * \param indiceModif Indice dans le tableau
     * \param couleurModif Nouvelle couleur à l'indice donné
     */
    void setIemeCouleur(int indiceModif, int couleurModif);
    /**
     * \fn void setSommetModifie(Sommet* sommetModif)
     * \brief permet de garder en attribut le sommet qui a été aléatoirement modifié pour faciliter les calculs de coût
     * \param sommetModif : le sommet qui a été modifié aléatoirement à partir de ka Solution précédente
     */
    void setSommetModifie(Sommet* sommetModif);
    /**
     * \fn vector<int> getCouleurs()
     * \brief Obtenir les souleurs pour les sommets de la solution courante
     * \return vector<int> : vector d'entier correspondant aux couleurs de chaque sommet
     */
    vector<int> getCouleurs();

};

#endif
