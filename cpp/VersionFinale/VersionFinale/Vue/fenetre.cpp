#include "fenetre.h"
#include "ui_fenetre.h"

Fenetre::Fenetre(QWidget *parent) :
    QMainWindow(parent),
    graphe(),
    ui(new Ui::Fenetre),
    domDocument(&graphe)
{
    //Touche initiale !
    ui->setupUi(this);
    setWindowTitle("GraphCalculus");

    //Création de l'arbre XML
    xmltree=new XMLTree(&graphe, ui->conteneurDroite);

    //On charge un premier fichier xml vide
    QFile fileXML("schemaVide.xml");
    ImportExport import=ImportExport(&graphe,xmltree, affichageSVG);
    import.ouvrir(&fileXML, &domDocument);

    //Affichage du graph
    affichageSVG=new ImplemGraphviz(&graphe, ui->afficheGraphe);
    ui->afficheGraphe->adjustSize();


    //Création des tab pour l'jaout de sommets et d'arcs
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

    //On relie slots et actions
    creerActions();
}

Fenetre::~Fenetre()
{
    delete ui;
}
