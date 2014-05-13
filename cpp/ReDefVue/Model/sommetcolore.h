/*!
  * \class SommetColore
  * \brief Implementation de la classe SommetColore
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date mai 2014
  * \see Sommet
  * \todo mettre la table de couleur en attribut de classe, idem pour les methodes correspondantes
  */

/**
 * \fn  SommetColore(bool m=false,string col="#FFFFFF")
 * \brief Constructeur d'un sommet colore
 * \param bool m marque
 * \param string col nom de la couleur
 * \warning si on omet le parametre marque initialise a false
 * \warning si on omet le parametre col initialise a "#FFFFFF"
 */
/**
 * \fn  SommetColore(Sommet*, string col="#FFFFFF")
 * \brief Constructeur d'un sommet colore
 * \param Sommet* sommet non colore
 * \param string col nom de la couleur
 * \warning si on omet le parametre col initialise a "#FFFFFF"
 */
/**
 * \fn  string getCouleur()
 * \brief Obtenir le nom de la couleur du sommet
 * \return string nom de la couleur
 * \warning le nom de la couleur est son code hexadecimal
 */
 /**
 * \fn  vector<string> getTableCouleur()
 * \brief Obtenir la table de conversion des couleurs
 * \return vector<string> la table des couleurs
 * \todo mettre en methode de classe
 */
 /**
 * \fn  void setCouleur(string codeRGB)
 * \brief Modifier la couleur du sommet
 * \param string codeRGB le code hexadecimal de la couleur
 */
 /**
 * \fn  void setTableCouleur(vector<string>)
 * \brief Modifier table des couleurs
 * \param vector<string> la nouvelle table des couleurs
 * \todo mettre en methode de classe
 */
 /**
 * \fn virtual void* sommetToColore()
 * \brief Convertir un Sommet en SommetColore
 * \return void* pointeur vers le SommetColore cree qu'il faudra caste en (SommetColore *)
 */
  /**
 * \fn  string getCouleurDansTable(int)
 * \brief Obtenir le code hexadecimal d'une couleur a partir de son numero
 * \param int numero de la couleur dans la table
 * \return string code hexadecimal de la couleur
 * \todo mettre en methode de classe
 */
 /**
 * \fn friend ostream& operator<<( ostream &flux, SommetColore& som )
 * \brief Redefinition de l'operateur de flux de sortie pour pouvoir afficher un sommet colore
 */

#ifndef SOMMETCOLORE_H
#define SOMMETCOLORE_H

#include "sommet.h"

using namespace std;

class SommetColore : public Sommet
{
public:
    SommetColore(bool m=false,string col="#FFFFFF");
    SommetColore(Sommet*, string col="#FFFFFF");

    string getCouleur();
    vector<string> getTableCouleur();
    void setCouleur(string codeRGB); //Sous forme de code #RGB
    void setCouleur(int numeroCouleur); //On choisit dans la table la bonne couleur
    void setTableCouleur(vector<string>);

    virtual void *sommetToColore();

    friend ostream& operator<<( ostream &flux, SommetColore& som );

protected:
    string couleur;
    vector<string> tableCouleur;
    static int nombreSommetsColore;

    string getCouleurDansTable(int);
};

#endif // SOMMETCOLORE_H
