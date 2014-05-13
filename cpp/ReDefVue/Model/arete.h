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

/**
 * \fn Arete(Sommet*, Sommet*)
 * \brief Constructeur d'une arete a partir de pointeurs vers deux sommets
 * \param Sommet* pointeur vers un sommet qui sera le premier sommet de l'arete
 * \param Sommet* pointeur vers un sommet qui sera le second sommet de l'arete
 */
/**
 * \fn Sommet getDepart()
 * \brief Retourne le premier sommet de l'arete
 * \return Sommet premier sommet de l'arete
 */
/**
 * \fn Sommet *getArrivee();
 * \brief Retourne le second sommet de l'arete
 * \return Sommet second sommet de l'arete
 */
/**
 * \fn void setDepart(Sommet*)
 * \brief Modifie le premier sommet de l'arete en passant en parametre un pointeur vers un sommet
 * \param pointeur vers un sommet qui sera le premier sommet de l'arete
 */
 /**
 * \fn void setArrivee(Sommet*)
 * \brief Modifie le second sommet de l'arete en passant en parametre un pointeur vers un sommet
 * \param pointeur vers un sommet qui sera le second sommet de l'arete
 */

#ifndef ARETE_H
#define ARETE_H

#include "sommet.h"

using namespace std;

class Arete
{
public:
    Arete(Sommet*, Sommet*);
    Sommet *getDepart();
    Sommet *getArrivee();
    void setDepart(Sommet*);
    void setArrivee(Sommet*);

    friend ostream& operator<<( ostream &flux, Arete& arc );


protected:
    Sommet *depart;
    Sommet *arrivee;
};

#endif // ARETE_H
