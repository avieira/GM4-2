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

#ifndef SOMMETCOLORE_H
#define SOMMETCOLORE_H

#include "sommet.h"

using namespace std;

class SommetColore : public Sommet
{
public:
    /**
     * \fn  SommetColore(bool m=false,string col="#FFFFFF")
     * \brief Constructeur d'un sommet colore
     * \param m Fixe le fait que le sommet soit marqué ou non
     * \param col nom de la couleur
     * \warning si on omet le parametre marque initialise a false
     * \warning si on omet le parametre col initialise a "#FFFFFF"
     */
    SommetColore(bool m=false,string col="#FFFFFF");
    /**
     * \fn  SommetColore(Sommet* s, string col="#FFFFFF")
     * \brief Constructeur d'un sommet colore par recopie de Sommet
     * \param s sommet non colore
     * \param col nom de la couleur
     * \warning si on omet le parametre col initialise a "#FFFFFF"
     */
    SommetColore(Sommet*, string col="#FFFFFF");

    /**
     * \fn  string getCouleur()
     * \brief Obtenir le nom de la couleur du sommet
     * \return string nom de la couleur
     * \warning le nom de la couleur est son code hexadecimal
     */
    string getCouleur();
    /**
    * \fn  vector<string> getTableCouleur()
    * \brief Obtenir la table de conversion des couleurs
    * \return vector<string> la table des couleurs
    * \todo mettre en methode de classe
    */
    vector<string> getTableCouleur();
    /**
    * \fn  void setCouleur(string codeRGB)
    * \brief Modifier la couleur du sommet
    * \param codeRGB le code hexadecimal de la couleur commençant par #
    */
    void setCouleur(string codeRGB); //Sous forme de code #RGB
    /**
    * \fn  void setCouleur(int numeroCouleur)
    * \brief Modifier la couleur du sommet
    * \param numeroCouleur Numéro de la couleur qui sera choisie dans une table définie à l'avance
    */
    void setCouleur(int numeroCouleur); //On choisit dans la table la bonne couleur
    /**
    * \fn  void setTableCouleur(vector<string> l)
    * \brief Modifier table des couleurs
    * \param l la nouvelle table des couleurs
    * \todo mettre en methode de classe
    */
    void setTableCouleur(vector<string>);

    /**
    * \fn virtual void* sommetToColore()
    * \brief Convertir un Sommet en SommetColore
    * \return void * pointeur vers le SommetColore cree qu'il faudra caste en (SommetColore *)
    */
    virtual void *sommetToColore();
    /**
    * \fn friend ostream& operator<<( ostream &flux, SommetColore& som )
    * \brief Redefinition de l'operateur de flux de sortie pour pouvoir afficher un sommet colore
    */
    friend void operator<<( ostream &flux, SommetColore& som );

protected:
    string couleur;
    vector<string> tableCouleur;
    static int nombreSommetsColore;

    /**
   * \fn  string getCouleurDansTable(int i)
   * \brief Obtenir le code hexadecimal d'une couleur a partir de son numero
   * \param i numero de la couleur dans la table
   * \return string code hexadecimal de la couleur
   * \todo mettre en methode de classe
   */
    string getCouleurDansTable(int);
};

#endif // SOMMETCOLORE_H
