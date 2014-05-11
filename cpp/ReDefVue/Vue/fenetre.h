#ifndef FENETRE_H
#define FENETRE_H

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

#include <vector>

#include "ui_fenetre.h"
#include "xmltree.h"
#include "AccesDonnees/documentxml.h"
#include "messagehandler.h"
#include "AccesDonnees/importexport.h"
#include "implemgraphviz.h"
#include "interfacegraph.h"

namespace Ui {
class Fenetre;
}

class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fenetre(InterfaceGraph graphe=InterfaceGraph(), QWidget *parent = 0);
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
    //Clases extérieures
    ImplemGraphviz *affichageSVG;
    XMLTree *xmltree;
    DocumentXML domDocument;
    InterfaceGraph graphe;

    //Affichage pur
    Ui::Fenetre *ui;
    QTabWidget *conteneurChamps;
    QPushButton *pushButtonArc;
    QPushButton *pushButtonSommet;
    QLineEdit *lineEditSommet;
    QComboBox *comboBoxArc1;
    QComboBox *comboBoxArc2;

    //Lier actions et slots
    void creerActions();

    //Modification d'attributs via les slots
    void modifSommetNom(Sommet*);
    void modifSommetForme(Sommet*);
    void modifSommetCouleur(SommetColore *);
    void modifArcDepart(Arete*);
    void modifArcArrivee(Arete*);

    void changeAttributSommetGraphe(Graphe* graphe);
    void changeAttributSommetGraphe(GrapheColore* graphe);
};

#endif // FENETRE_H
