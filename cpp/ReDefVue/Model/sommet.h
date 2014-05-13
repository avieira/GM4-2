/*!
  * \class Sommet
  * \brief Implementation de la classe sommet
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  */

/**
 * \fn     Sommet(bool m=false)
 * \brief Constructeur d'un sommet
 * \param bool m marque
 * \warning si on omet le parametre marque initialise a false
 */
/**
 * \fn ~Sommet()
 * \brief Destructeur
 */
/**
 * \fn void setId(int)
 * \brief Modifie le numero d'identifiant du sommet
 * \param int qui sera le nouveau numero du sommet
 */
  /**
 * \fn void setMarque(bool b)
 * \brief Modifie la marque du sommet
 * \param bool qui sera la nouvelle marque du sommet
 */
  /**
 * \fn int getId()
 * \brief Obtenir l'indentifiant du sommet
 * \return int le numero d'identifiant du sommet
 */
/**
 * \fn bool isMarque()
 * \brief Pour savoir si un sommet est marque ou non
 * \return bool true si le sommet est marque false sinon
 * \warning il s'agit de l'accesseur getMarque()
 */
 /**
 * \fn int getNombreSommets()
 * \brief Obtenir le nombre de sommets crees
 * \return int le nombre de sommets crees
 */
  /**
 * \fn virtual void* sommetToColore()
 * \brief Convertir un Sommet en SommetColore
 * \return void* pointeur vers le SommetColore cree qu'il faudra caste en (SommetColore *)
 */
  /**
 * \fn friend ostream& operator<<( ostream &flux, Sommet& som )
 * \brief Redefinition de l'operateur de flux de sortie pour pouvoir afficher un sommet
 */


#ifndef SOMMET_H
#define SOMMET_H

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Sommet
{
public:
    Sommet(bool m=false);
    ~Sommet();

    void setId(int);
    void setMarque(bool b);
    int getId();
    bool isMarque();
    int getNombreSommets();

    virtual void* sommetToColore();
    
    friend ostream& operator<<( ostream &flux, Sommet& som );

    //void setForme(string);
    //string getForme();
    //void setNom(string);
    //string getNom();

protected:
    int id;
    static int nombreSommets;
    bool marque;

    //string nom;
    //string forme;
};

#endif // SOMMET_H
