/*!
  * \class Arete
  * \brief Implementation de la classe arete
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see Sommet
  */

#ifndef ARETE_H
#define ARETE_H

#include "sommet.h"
#include "Obs/Observable.hpp"

using namespace std;

class Arete : public Observable
{
public:
    /**
     * \fn Arete(Sommet* som1, Sommet* som2)
     * \brief Constructeur d'une arete a partir de pointeurs vers deux sommets
     * \param som1 Pointeur vers un sommet qui sera le premier sommet de l'arete
     * \param som2 Pointeur vers un sommet qui sera le second sommet de l'arete
     */
    Arete(Sommet*, Sommet*);
    /**
     * \fn Sommet getDepart()
     * \brief Retourne le premier sommet de l'arete
     * \return Sommet * Premier sommet de l'arete
     */
    Sommet *getDepart();
    /**
     * \fn Sommet *getArrivee();
     * \brief Retourne le second sommet de l'arete
     * \return Sommet * Second sommet de l'arete
     */
    Sommet *getArrivee();
    /**
     * \fn void setDepart(Sommet* som)
     * \brief Modifie le premier sommet de l'arete en passant en parametre un pointeur vers un sommet
     * \param som Pointeur vers un sommet qui sera le premier sommet de l'arete
     */
    void setDepart(Sommet*);
    /**
    * \fn void setArrivee(Sommet* som)
    * \brief Modifie le second sommet de l'arete en passant en parametre un pointeur vers un sommet
    * \param som Pointeur vers un sommet qui sera le second sommet de l'arete
    */
    void setArrivee(Sommet*);

    /**
     * \fn friend ostream& operator<<( ostream &flux, Arete& arc )
     * \brief Redefinition de l'operateur de flux de sortie pour pouvoir afficher un arc
     */
    friend void operator<<( ostream &flux, Arete& arc );


protected:
    Sommet *depart;
    Sommet *arrivee;
};

#endif // ARETE_H
