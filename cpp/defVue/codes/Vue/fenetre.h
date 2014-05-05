/*!
  * \class Fenetre
  * \brief Conteneur général de widgets
  * \author Alexandre Vieira
  * \version 1.0
  * \date avril 2014
  * \bug None
  * \warning None
  *
  * Conteneur général de l'interface graphique. Contient un ui défini par QtCreator ainsi que quelques widgets créés spécifiquement. Contient slots et actions pour faire le lien entre l'utilisateur et le programme. 
  * Plus spécifiquement, cette classe contient :
  * 	- Une ui, définie par QtCreator, qui contient :
  *		-# Un menu, contenant le menu de fichier et d'édtion
  *		-# Une barre contenant les mêmes actions sous forme de boutons
  *		-# Une barre d'état
  *		-# Deux conteneurs : un à droite et un à gauche.
  * 	- Une fenêtre affichant le graph (classe ImplemGraphviz)
  * 	- Une fenêtre contenant à la fois un champ pour ajouter arcs et sommets, et une fenêtre affichant arcs et sommets existants.
  * De même, chaque bouton est relié à une action mettant à jour aussi bien vue que model.
  */



#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include<QTabWidget>
#include<QPushButton>
#include<QComboBox>
#include <vector>

#include "Model/sommetcolore.h"
#include "Model/graphe.h"
#include "xmltree.h"
#include "implemgraphviz.h"


namespace Ui {
class Fenetre;
}

class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
/**
 * \fn explicit Fenetre(QWidget *parent = 0, Graphe *graph=new Graphe())
 * \brief Constructeur de fenêtre
 *
 * \param parent, pointeur sur widget défini par Qt, peut être NULL.
 * \param graph, pointeur sur un Graphe.
 */
    explicit Fenetre(QWidget *parent = 0, Graphe *graph=new Graphe());
/**
 * \fn ~Fenetre
 * \brief Destruteur de fenêtre
 */
    ~Fenetre();

private slots:
/**
 * \fn void slotButtonSommet()
 * \brief [slot] Slot s'activant lors de la pression du bouton du champ d'ajout de sommet
 */
    void slotButtonSommet();
/**
 * \fn void slotButtonArc()
 * \brief [slot] Slot s'activant lors de la pression du bouton du champ d'ajout d'arc
 */
    void slotButtonArc();
/**
 * \fn void ouvrir()
 * \brief [slot] Slot s'activant lors de la pression du bouton d'ouverture de fichier (sert à l'importation)
 */
    void ouvrir();
/**
 * \fn void enregistrer()
 * \brief [slot] Slot s'activant lors de la pression du bouton d'enregistrement de fichier (sert à l'exportation)
 */
    void enregistrer();
/**
 * \fn void changeAttributSommet()
 * \brief [slot] Slot s'activant lors de la pression du bouton de changement attribut d'un arc
 */
    void changeAttributSommet();
/**
 * \fn void changeAttributArc()
 * \brief [slot] Slot s'activant lors de la pression du bouton de changement attribut d'un sommet
 */
    void changeAttributArc();

private:
    Ui::Fenetre *ui;

    ImplemGraphviz *affichageSVG;
    XMLTree *xmltree;
    QTabWidget *conteneurChamps;
    QPushButton *pushButtonArc;
    QPushButton *pushButtonSommet;
    QLineEdit *lineEditSommet;
    QStringList listeFormes;
    QComboBox *comboBoxArc1;
    QComboBox *comboBoxArc2;

    std::vector<Sommet*> *listeSommets;
    std::vector<Arete*> *listeArcs;

    void creerActions();

    void modifSommetNom(Sommet*);
    void modifSommetForme(Sommet*);
    void modifSommetCouleur(SommetColore *);
    void modifArcDepart(Arete*);
    void modifArcArrivee(Arete*);

};

#endif // FENETRE_H

