/*!
  * \class Fenetre
  * \brief Conteneur général de widgets
  * \author Alexandre Vieira
  * \author Anca Caranfil
  * \author Pascal Wortel
  * \author Conrad Hillairet
  * \version 1.0
  * \date avril 2014
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
#include <QMainWindow>
#include<QTabWidget>
#include<QLineEdit>
#include<QPushButton>
#include<QComboBox>
#include<QMessageBox>
#include<QXmlSchema>
#include <QXmlSchemaValidator>
#include<QPushButton>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QColorDialog>

#include "interfacegraph.h"
#include "AccesDonnees/documentxml.h"
#include "Vue/xmltree.h"
#include "Vue/implemgraphviz.h"
#include "AccesDonnees/importexport.h"
#include "messagehandler.h"

namespace Ui {
class Fenetre;
}

class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    /**
    * \fn explicit Fenetre(QWidget *parent = 0)
    * \brief Constructeur de fenêtre
    *
    * \param parent, pointeur sur widget défini par Qt, peut être NULL.
    */
    explicit Fenetre(QWidget *parent = 0);
    /**
     * \fn ~Fenetre
     * \brief Destruteur de fenêtre
     */
    ~Fenetre();

protected slots:
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
 * \bug Si on ouvre un deuxième document, tout finira par planter
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

    /**
     * \fn void colorerD()
     * \brief [slot] Appelle la méthode de coloration directe
     */
    void colorerD();
    /**
     * \fn void colorerH()
     * \brief Appelle la méthode de coloration heuristique
     */
    void colorerH();

private:
    //Clases extérieures
    InterfaceGraph graphe;
    XMLTree *xmltree;
    DocumentXML domDocument;
    ImplemGraphviz *affichageSVG;

    //Affichage pur
    Ui::Fenetre *ui;
    QTabWidget *conteneurChamps;
    QPushButton *pushButtonArc;
    QPushButton *pushButtonSommet;
    QLineEdit *lineEditSommet;
    QComboBox *comboBoxArc1;
    QComboBox *comboBoxArc2;

    //Lier actions et slots
    /**
     * \fn void creerActions()
     * \brief Lie les différentes actions des constituants de l'interface graphique avec les slots
     */
    void creerActions();

    //Modification d'attributs via les slots
    /**
     * \fn void modifSommetNom(Sommet*)
     * \brief Appelle une suite de fenêtres de dialogue invitant l'utilisateur à changer le nom d'un sommet. S'occupe ensuite de changer le nom du sommet avec l'information entrée
     * \param Pointeur sur le sommet dont on modifie le nom.
     */
    void modifSommetNom(Sommet*);
    /**
     * \fn void modifSommetForme(Sommet*)
     * \brief Appelle une suite de fenêtres de dialogue invitant l'utilisateur à changer la forme d'un sommet. S'occupe ensuite de changer la forme du sommet avec l'information entrée
     * \param Pointeur sur le sommet dont on modifie la forme.
     */
    void modifSommetForme(Sommet*);
    /**
     * \fn void modifSommetCouleur(SommetColore*)
     * \brief Appelle une suite de fenêtres de dialogue invitant l'utilisateur à changer la couleur d'un sommet. S'occupe ensuite de changer la couleur du sommet avec l'information entrée
     * \param Pointeur sur le sommet coloré dont on modifie la couleur.
     */
    void modifSommetCouleur(SommetColore *);
    /**
     * \fn void modifArcDepart(Arete*)
     * \brief Appelle une suite de fenêtres de dialogue invitant l'utilisateur à changer le sommet départ d'un arc. S'occupe ensuite de modifier l'arc avec l'information entrée
     * \param Pointeur sur l'arête à modifier.
     */
    void modifArcDepart(Arete*);
    /**
     * \fn void modifArcArrivee(Arete*)
     * \brief Appelle une suite de fenêtres de dialogue invitant l'utilisateur à changer le sommet arrivée d'un arc. S'occupe ensuite de modifier l'arc avec l'information entrée
     * \param Pointeur sur l'arête à modifier.
     */
    void modifArcArrivee(Arete*);

    /**
     * \fn void changeAttributSommetGraphe(Graphe*)
     * \brief Appelle une suite de fenêtres de dialogue invitant l'utilisateur à changer l'attribut d'un sommet. Appelle la méthode adéquate suivant le choix de l'utilisateur.
     * \param Pointeur sur le graphe où sommets et arcs sont définis.
     */
    void changeAttributSommetGraphe(Graphe* graphe);
    /**
     * \fn void changeAttributSommetGraphe(GrapheColore*)
     * \brief Appelle une suite de fenêtres de dialogue invitant l'utilisateur à changer l'attribut d'un sommet. Appelle la méthode adéquate suivant le choix de l'utilisateur.
     * \param Pointeur sur le graphe où sommets colorés et arcs sont définis.
     */
    void changeAttributSommetGraphe(GrapheColore* graphe);

    /**
     * \fn void redessinerComboArc()
     * \brief Recharge la boîte d'ajout d'arcs avec les informations en mémoire.
     */
    void redessinerComboArc();
};

#endif // FENETRE_H
