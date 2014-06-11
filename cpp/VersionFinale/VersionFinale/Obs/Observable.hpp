/*!
  * \class Observable
  * \brief Implémentation pattern Observer : côté observable
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see Observer
  */

#ifndef OBSERVABLE
#define OBSERVABLE
#include"Observer.hpp"
#include<vector>

using namespace std;

class Observable
{
public:
    /**
      * \param vector<Observer*> listeObserver;
      * \brief Liste des Observers associé à l'élément observable courant
    */
    vector<Observer*> listeObserver;

    /**
      * \fn void addObserver(Observer* o)
      * \brief Ajoute un observer à la liste
      * \param o pointeur sur un Observer
    */
    void addObserver(Observer*);
    /**
      * \fn void notify()
      * \brief Envoie la méthode update à tous les éléments de la liste des Observers
      * \see Observer::notify()
    */
    void notify();

};

#endif
