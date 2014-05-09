#include <QtWidgets>
#include<QXmlSchema>
#include <QXmlSchemaValidator>
#include<QAbstractMessageHandler>
#include<QPushButton>

#include "fenetre.h"
#include "ui_fenetre.h"
#include "messagehandler.h"


Fenetre::Fenetre(QWidget *parent, Graphe *graph) :
    QMainWindow(parent),
    ui(new Ui::Fenetre)
{
    //Récupération infos graph
    /*listeSommets=&(graph->getListeSommets());
    listeArcs=&(graph->getListeArcs());*/

    listeSommets=new vector<Sommet*>;
    listeSommets->push_back(new Sommet("id1"));
    listeSommets->push_back(new Sommet("id2"));
    listeSommets->push_back(new Sommet("id3"));
    listeSommets->push_back(new Sommet("id4"));

    listeArcs=new vector<Arete*>;
    listeArcs->push_back(new Arete(listeSommets->at(0),listeSommets->at(1)));
    listeArcs->push_back(new Arete(listeSommets->at(2),listeSommets->at(3)));
    listeArcs->push_back(new Arete(listeSommets->at(2),listeSommets->at(1)));
    listeArcs->push_back(new Arete(listeSommets->at(3),listeSommets->at(1)));

    ui->setupUi(this);
    setWindowTitle("GraphCalculus");

    xmltree=new XMLTree(ui->conteneurDroite, graph);

    conteneurChamps=new QTabWidget(ui->conteneurDroite);
    QWidget *page1 = new QWidget;
    lineEditSommet = new QLineEdit("Entrez un nom de sommet");
    pushButtonSommet = new QPushButton("OK");
    QHBoxLayout *vbox1 = new QHBoxLayout;
    vbox1->addWidget(lineEditSommet);
    vbox1->addWidget(pushButtonSommet);
    page1->setLayout(vbox1);
    conteneurChamps->addTab(page1, "Ajout de sommet");

    QWidget *page2 = new QWidget;
    comboBoxArc1=new QComboBox;
    comboBoxArc2=new QComboBox;
    pushButtonArc = new QPushButton("OK");
    QHBoxLayout *vbox2 = new QHBoxLayout;
    vbox2->addWidget(comboBoxArc1);
    vbox2->addWidget(comboBoxArc2);
    vbox2->addWidget(pushButtonArc);
    page2->setLayout(vbox2);
    conteneurChamps->addTab(page2, "Ajout d'arc");

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(xmltree,0,0,100,9);
    gridLayout->addWidget(conteneurChamps,100,0,9,1);

    ui->conteneurDroite->setLayout(gridLayout);

    affichageSVG=new ImplemGraphviz(ui->afficheGraphe, graph);
    creerActions();

    listeFormes<<"box"<<"ellipse"<<"circle"<<"square"<<"star"<<"diamond"<<"pentagon"<<"septagon";
}

Fenetre::~Fenetre()
{
    delete ui;
}

void Fenetre::slotButtonSommet()
{
    Sommet *nvSommet=new Sommet(lineEditSommet->text().toStdString());
    listeSommets->push_back(nvSommet);

    xmltree->ajouterSommet(nvSommet);
}

void Fenetre::slotButtonArc()
{
    Sommet *nvSommet1=(*listeSommets)[comboBoxArc1->currentIndex()];
    Sommet *nvSommet2=(*listeSommets)[comboBoxArc2->currentIndex()];
    Arete *nvArc=new Arete(nvSommet1,nvSommet2);
    listeArcs->push_back(nvArc);

    xmltree->ajouterArc(nvArc);

}

void Fenetre::ouvrir()
{
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Séléctionner un fichier"),
                                         QDir::currentPath(),
                                         tr("Fichiers XML (*.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Erreur lecture"),
                             tr("Impossible de lire le fichier %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QFile fileSchema("schemaGraph.xsd");
    fileSchema.open(QIODevice::ReadOnly);

    QXmlSchema schema;
    MessageHandler messageHandler;
    schema.setMessageHandler(&messageHandler);

    schema.load(&fileSchema, QUrl::fromLocalFile(file.fileName()));
    if (schema.isValid()) {
        QFile fileXML(fileName);
        fileXML.open(QIODevice::ReadOnly);

        QXmlSchemaValidator validator(schema);
        if (!validator.validate(&fileXML, QUrl::fromLocalFile(file.fileName()))){
            QMessageBox::warning(this, tr("Fichier malformé"),
                                 tr("Impossible d'ouvrir le fichier' %1'.\n Le document ne correspond pas au schéma. \n%2")
                                 .arg(fileName)
                                 .arg(messageHandler.statusMessage()));
            return;
        }
    }

    if (xmltree->ouvrir(&file))
        ui->statusBar->showMessage(tr("Fichier chargé"), 2000);

}

void Fenetre::enregistrer()
{
    QString fileName =
            QFileDialog::getSaveFileName(this, tr("Enregistrer sous..."),
                                         QDir::currentPath(),
                                         tr("Fichiers XML (*.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Erreur d'enregistrement"),
                             tr("Impossible d'écrire dans le fichier %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    if (xmltree->enregistrer(&file))
        ui->statusBar->showMessage(tr("Fichier enregisrté"), 2000);

}

//Ajout de la forme et de la valeur
void Fenetre::changeAttributSommet()
{
    //Création d'une boîte de dialogue
    QDialog fenDiag;

    //Boutons OK et Annuler
    QHBoxLayout *layoutButton=new QHBoxLayout;
    QPushButton *okFenDiag=new QPushButton("&OK");
    QPushButton *cancFenDiag=new QPushButton("&Annuler");
    layoutButton->addWidget(okFenDiag);
    layoutButton->addWidget(cancFenDiag);

    connect(okFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(accept()));
    connect(cancFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(reject()));

    //Création de la liste des sommets
    QComboBox *boxSommets=new QComboBox;
    for (int i = 0 ; i < (*listeSommets).size(); i++){
        boxSommets->addItem(QString((*listeSommets)[i]->getId().c_str()));
    }

    //Ajout de tout ça à la fenêtre de dialogue
    QVBoxLayout *layoutFenetre=new QVBoxLayout;
    layoutFenetre->addWidget(boxSommets);
    layoutFenetre->addLayout(layoutButton);
    fenDiag.setLayout(layoutFenetre);

    //On affiche la fenêtre
    fenDiag.setVisible(true);
    fenDiag.setModal(true);

    //On traîte la demande
    if(fenDiag.exec()){ //Si on a cliqué sur ok !
        Sommet *sommetModif=(*listeSommets)[boxSommets->currentIndex()];

        //On demande ce qu'on veut modifier à ce sommet
        QDialog fenDiag2;

        //On réutilise les mêmes boutons qu'avant
        disconnect(okFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(accept()));
        disconnect(cancFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(reject()));
        connect(okFenDiag, SIGNAL(clicked()), &fenDiag2, SLOT(accept()));
        connect(cancFenDiag, SIGNAL(clicked()), &fenDiag2, SLOT(reject()));

        QComboBox *boxOptions=new QComboBox;
        QStringList options;
        options<<"Modifier le nom du sommet"<<"Modifier la forme du sommet"<<"Modifier la couleur du sommet";
        boxOptions->addItems(options);

        QVBoxLayout *layoutFenetre2=new QVBoxLayout;
        layoutFenetre->removeItem(layoutButton);
        layoutFenetre2->addWidget(boxOptions);
        layoutFenetre2->addLayout(layoutButton);

        fenDiag2.setLayout(layoutFenetre2);
        fenDiag2.setVisible(true);
        fenDiag2.setModal(true);

        if(fenDiag2.exec()){
            switch(boxOptions->currentIndex()){
            case 0 : {
                modifSommetNom(sommetModif);
                break;
            } case 1 : {
                modifSommetForme(sommetModif);
                break;
            } case 2 : {
                SommetColore* sommetColore=(SommetColore*)sommetModif->sommetToColore();
                sommetModif=sommetColore;
                modifSommetCouleur(sommetColore);
                break;
            }

            }
        }
    }
}

void Fenetre::changeAttributArc()
{
    //Création d'une boîte de dialogue
    QDialog fenDiag;

    //Boutons OK et Annuler
    QHBoxLayout *layoutButton=new QHBoxLayout;
    QPushButton *okFenDiag=new QPushButton("&OK");
    QPushButton *cancFenDiag=new QPushButton("&Annuler");
    layoutButton->addWidget(okFenDiag);
    layoutButton->addWidget(cancFenDiag);

    connect(okFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(accept()));
    connect(cancFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(reject()));

    //Création de la liste des arcs
    QComboBox *boxArcs=new QComboBox;
    for (int i = 0 ; i < (*listeArcs).size(); i++){
        boxArcs->addItem(QString((*listeArcs)[i]->getDepart()->getId().c_str())+"->"+QString((*listeArcs)[i]->getDepart()->getId().c_str()));
    }

    //Ajout de tout ça à la fenêtre de dialogue
    QVBoxLayout *layoutFenetre=new QVBoxLayout;
    layoutFenetre->addWidget(boxArcs);
    layoutFenetre->addLayout(layoutButton);
    fenDiag.setLayout(layoutFenetre);

    //On affiche la fenêtre
    fenDiag.setVisible(true);
    fenDiag.setModal(true);

    //On traîte la demande
    if(fenDiag.exec()){ //Si on a cliqué sur ok !
        Arete *arcModif=(*listeArcs)[boxArcs->currentIndex()];

        //On demande ce qu'on veut modifier à ce sommet
        QDialog fenDiag2;

        //On réutilise les mêmes boutons qu'avant
        disconnect(okFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(accept()));
        disconnect(cancFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(reject()));
        connect(okFenDiag, SIGNAL(clicked()), &fenDiag2, SLOT(accept()));
        connect(cancFenDiag, SIGNAL(clicked()), &fenDiag2, SLOT(reject()));

        QComboBox *boxOptions=new QComboBox;
        QStringList options;
        options<<"Modifier le départ"<<"Modifier l'arrivée";
        boxOptions->addItems(options);

        QVBoxLayout *layoutFenetre2=new QVBoxLayout;
        layoutFenetre->removeItem(layoutButton);
        layoutFenetre2->addWidget(boxOptions);
        layoutFenetre2->addLayout(layoutButton);

        fenDiag2.setLayout(layoutFenetre2);
        fenDiag2.setVisible(true);
        fenDiag2.setModal(true);

        if(fenDiag2.exec()){
            switch(boxOptions->currentIndex()){
            case 0 : {
                modifArcDepart(arcModif);
                break;
            } case 1 : {
                modifArcArrivee(arcModif);
                break;
            }
            }
        }
    }
}

//Penser : nom devrait être unique, trouver moyen de vérifier ça
void Fenetre::modifSommetNom(Sommet *sommet)
{
    //Création d'une boîte de dialogue
    QDialog fenDiag;

    //Boutons OK et Annuler
    QHBoxLayout *layoutButton=new QHBoxLayout;
    QPushButton *okFenDiag=new QPushButton("&OK");
    QPushButton *cancFenDiag=new QPushButton("&Annuler");
    layoutButton->addWidget(okFenDiag);
    layoutButton->addWidget(cancFenDiag);

    connect(okFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(accept()));
    connect(cancFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(reject()));

    //Champ pour entrer un nom de sommet
    QLineEdit *lineEdit = new QLineEdit("Entrez un nouveau nom pour le sommet");

    //Ajout de tout ça à la fenêtre de dialogue
    QVBoxLayout *layoutFenetre=new QVBoxLayout;
    layoutFenetre->addWidget(lineEdit);
    layoutFenetre->addLayout(layoutButton);
    fenDiag.setLayout(layoutFenetre);

    //On affiche la fenêtre
    fenDiag.setVisible(true);
    fenDiag.setModal(true);

    //On traîte la demande
    if(fenDiag.exec()){ //Si on a cliqué sur ok !
        sommet->setId(lineEdit->text().toStdString());
    }
}

void Fenetre::modifSommetForme(Sommet *sommet)
{
    //Création d'une boîte de dialogue
    QDialog fenDiag;

    //Boutons OK et Annuler
    QHBoxLayout *layoutButton=new QHBoxLayout;
    QPushButton *okFenDiag=new QPushButton("&OK");
    QPushButton *cancFenDiag=new QPushButton("&Annuler");
    layoutButton->addWidget(okFenDiag);
    layoutButton->addWidget(cancFenDiag);

    connect(okFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(accept()));
    connect(cancFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(reject()));

    //Champ pour choisir la forme
    QComboBox *boxFormes=new QComboBox;
    boxFormes->addItems(listeFormes);

    //Ajout de tout ça à la fenêtre de dialogue
    QVBoxLayout *layoutFenetre=new QVBoxLayout;
    layoutFenetre->addWidget(boxFormes);
    layoutFenetre->addLayout(layoutButton);
    fenDiag.setLayout(layoutFenetre);

    //On affiche la fenêtre
    fenDiag.setVisible(true);
    fenDiag.setModal(true);

    //On traîte la demande
    if(fenDiag.exec()){ //Si on a cliqué sur ok !
        sommet->setForme(boxFormes->currentText().toStdString());
    }
}

void Fenetre::modifSommetCouleur(SommetColore *sommet)
{
    //Création d'une boîte de dialogue
    QColor couleur = QColorDialog::getColor(Qt::white, this);

    //On traîte la demande
    if(couleur.isValid()){ //Si on a cliqué sur ok !
        int r, g, b;
        r=couleur.red();
        g=couleur.green();
        b=couleur.blue();
        string codeRGB="#"+QString(r).toStdString()+QString(g).toStdString()+QString(b).toStdString();
        sommet->setCouleur(codeRGB);
    }
}

void Fenetre::modifArcDepart(Arete* arc)
{
    //Création d'une boîte de dialogue
    QDialog fenDiag;

    //Boutons OK et Annuler
    QHBoxLayout *layoutButton=new QHBoxLayout;
    QPushButton *okFenDiag=new QPushButton("&OK");
    QPushButton *cancFenDiag=new QPushButton("&Annuler");
    layoutButton->addWidget(okFenDiag);
    layoutButton->addWidget(cancFenDiag);

    connect(okFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(accept()));
    connect(cancFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(reject()));

    //Création de la liste des sommets
    QComboBox *boxSommets=new QComboBox;
    for (int i = 0 ; i < (*listeSommets).size(); i++){
        boxSommets->addItem(QString((*listeSommets)[i]->getId().c_str()));
    }

    //Ajout de tout ça à la fenêtre de dialogue
    QVBoxLayout *layoutFenetre=new QVBoxLayout;
    layoutFenetre->addWidget(boxSommets);
    layoutFenetre->addLayout(layoutButton);
    fenDiag.setLayout(layoutFenetre);

    //On affiche la fenêtre
    fenDiag.setVisible(true);
    fenDiag.setModal(true);

    //On traîte la demande
    if(fenDiag.exec()){ //Si on a cliqué sur ok !
        arc->setDepart((*listeSommets)[boxSommets->currentIndex()]);
    }
}

void Fenetre::modifArcArrivee(Arete* arc)
{
    //Création d'une boîte de dialogue
    QDialog fenDiag;

    //Boutons OK et Annuler
    QHBoxLayout *layoutButton=new QHBoxLayout;
    QPushButton *okFenDiag=new QPushButton("&OK");
    QPushButton *cancFenDiag=new QPushButton("&Annuler");
    layoutButton->addWidget(okFenDiag);
    layoutButton->addWidget(cancFenDiag);

    connect(okFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(accept()));
    connect(cancFenDiag, SIGNAL(clicked()), &fenDiag, SLOT(reject()));

    //Création de la liste des sommets
    QComboBox *boxSommets=new QComboBox;
    for (int i = 0 ; i < (*listeSommets).size(); i++){
        boxSommets->addItem(QString((*listeSommets)[i]->getId().c_str()));
    }

    //Ajout de tout ça à la fenêtre de dialogue
    QVBoxLayout *layoutFenetre=new QVBoxLayout;
    layoutFenetre->addWidget(boxSommets);
    layoutFenetre->addLayout(layoutButton);
    fenDiag.setLayout(layoutFenetre);

    //On affiche la fenêtre
    fenDiag.setVisible(true);
    fenDiag.setModal(true);

    //On traîte la demande
    if(fenDiag.exec()){ //Si on a cliqué sur ok !
        arc->setArrivee((*listeSommets)[boxSommets->currentIndex()]);
    }

}


void Fenetre::creerActions()
{
    ui->actionOuvrir->setShortcuts(QKeySequence::Open);
    connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrir()));

    ui->actionEnregistrer->setShortcuts(QKeySequence::Save);
    connect(ui->actionEnregistrer, SIGNAL(triggered()), this, SLOT(enregistrer()));

    ui->actionQuitter->setShortcuts(QKeySequence::Quit);
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui->actionAttribut_arc, SIGNAL(triggered()), this, SLOT(changeAttributArc()));
    connect(ui->actionAttribut_sommet, SIGNAL(triggered()), this, SLOT(changeAttributSommet()));

    connect(pushButtonSommet, SIGNAL(clicked()), this, SLOT(slotButtonSommet()));
    connect(pushButtonArc, SIGNAL(clicked()), this, SLOT(slotButtonArc()));
}
