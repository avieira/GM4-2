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
