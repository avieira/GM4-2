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

#ifndef SOMMET_H
#define SOMMET_H

#include<string>
#include<sstream>
#include<iostream>
#include<vector>

#include<QString>
#include "Obs/Observable.hpp"

using namespace std;

class Sommet : public Observable
{
public:
    /**
     * \fn     Sommet(bool m=false)
     * \brief Constructeur d'un sommet
     * \param m Fixe le sommet comme marqué ou non
     * \warning Si on omet le parametre marque initialise a false
     */
    Sommet(bool m=false);
    /**
     * \fn ~Sommet()
     * \brief Destructeur
     */
    virtual ~Sommet();

    /**
     * \fn void setId(int i)
     * \brief Modifie le numero d'identifiant du sommet
     * \param i qui sera le nouveau numero du sommet
     */
    void setId(int);
    /**
     * \fn void setMarque(bool b)
     * \brief Modifie la marque du sommet
     * \param b qui sera la nouvelle marque du sommet
     */
    void setMarque(bool b);
    /**
     * \fn int getId()
     * \brief Obtenir l'indentifiant du sommet
     * \return int le numero d'identifiant du sommet
     */
    int getId();
    /**
     * \fn bool isMarque()
     * \brief Pour savoir si un sommet est marqué ou non
     * \return bool true si le sommet est marqué, false sinon
     */
    bool isMarque();
    /**
     * \fn int getNombreSommets()
     * \brief Obtenir le nombre de sommets créés
     * \return int le nombre de sommets créés
     */
    int getNombreSommets();
    /**
     * \fn virtual void* sommetToColore()
     * \brief Convertir un Sommet en SommetColore
     * \return void * pointeur vers le SommetColore cree qu'il faudra caste en (SommetColore *)
     */
    virtual void* sommetToColore();
    
    /**
     * \fn friend ostream& operator<<( ostream &flux, Sommet& som )
     * \brief Redefinition de l'operateur de flux de sortie pour pouvoir afficher un sommet
     */
    friend void operator<<( ostream &flux, Sommet& som );
    /**
    * \fn friend inline bool operator== (Sommet som1, Sommet som2);
    * \brief Redéfinition de l'opérateur d'égalité pour deux sommets. Se base sur l'identifiant (int) qui doit être le même.
    * \param som1 : premier sommet à tester pour l'égalité
    * \param som2 : deuxième sommet à tester pour l'égalité
    * \return bool : vrai si les deux mêmes sommets, faux sinon
    */
    friend inline bool operator== (Sommet som1, Sommet som2);
    /**
    * \fn void setForme(QString);
    * \brief Modifie la forme du sommet dessiné dans l'IHM
    * \param QString : nouvelle forme
    */
    void setForme(QString);
    /**
    * \fn QString getForme();
    * \brief Renvoie la forme du sommet dessiné dans l'IHM
    * \return QString : forme actuelle du sommet
    */
    QString getForme();
    /**
    * \fn void setNom(QString);
    * \brief Modifie le nom du sommet affiché dans l'IHM
    * \return QString : nouveau nom
    */
    void setNom(QString);
    /**
    * \fn QString getNom()
    * \brief Renvoie le nom du sommet affiché dans l'IHM
    * \return QString : nom actuel du sommet
    */
    QString getNom();

protected:
    int id;
    static int nombreSommets;
    bool marque;

    QString nom;
    QString forme;
};

#endif // SOMMET_H
