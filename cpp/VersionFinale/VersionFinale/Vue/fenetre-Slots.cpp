#include "fenetre.h"
#include "ui_fenetre.h"

void Fenetre::slotButtonSommet()
{
    QString id=lineEditSommet->text();
    if(!(graphe.contains(id))){
        if(graphe.isColore())
        {
            SommetColore* nvSommet=new SommetColore();
            nvSommet->setNom(id);
            //Ajout au document XML
            domDocument.ajouterSommet(nvSommet,id);

            //Ajout du graphe au sommet pour observeur
            //nvSommet->addObserver(affichageSVG);
            //GraphViz non thread-safe : affichage mal géré. Mieux vaut donc redemander l'affichage à chaque fois.

            //Ajout à l'arbre
            xmltree->ajouterSommet(nvSommet);

            GrapheColore* graph=(GrapheColore*)graphe.getGraph();
            graph->ajouterSommet(nvSommet);
        }
        else
        {
            Sommet* nvSommet=new Sommet();
            nvSommet->setNom(id);
            //Ajout au document XML
            domDocument.ajouterSommet(nvSommet,id);

            //Ajout du graphe au sommet pour observeur
            //nvSommet->addObserver(affichageSVG);
            //GraphViz non thread-safe : affichage mal géré. Mieux vaut donc redemander l'affichage à chaque fois.

            //Ajout à l'arbre
            xmltree->ajouterSommet(nvSommet);

            Graphe* graph=(Graphe*)graphe.getGraph();
            graph->ajouterSommet(nvSommet);
        }
    }
    else
        QMessageBox::warning(window(), tr("GraphCalculus"),
                             tr("Le nom du sommet existe déjà !"));

    affichageSVG->drawGraph();
    //On pense à mettre à jour l'ajout d'arêtes
    redessinerComboArc();
}

void Fenetre::slotButtonArc()
{
    if(graphe.isColore())
    {
        GrapheColore* graph=(GrapheColore*)graphe.getGraph();
        vector<SommetColore*> listeSommets=graph->getListeSommets();
        Sommet *nvSommet1=listeSommets[comboBoxArc1->currentIndex()];
        Sommet *nvSommet2= listeSommets[comboBoxArc2->currentIndex()];
        Arete *nvArc=new Arete(nvSommet1,nvSommet2);
        graph->ajouterArc(nvArc);

        //Ajout au document XML
        domDocument.ajouterArc(nvArc);

        //Ajout du graphe au sommet pour observeur
        //nvArc->addObserver(affichageSVG);
        //GraphViz non thread-safe : affichage mal géré. Mieux vaut donc redemander l'affichage à chaque fois.

        //Ajout à l'arbre
        xmltree->ajouterArc(nvArc);
    }
    else
    {
        Graphe* graph=(Graphe*)graphe.getGraph();
        vector<Sommet*> listeSommets=graph->getListeSommets();
        Sommet *nvSommet1=listeSommets[comboBoxArc1->currentIndex()];
        Sommet *nvSommet2= listeSommets[comboBoxArc2->currentIndex()];
        Arete *nvArc=new Arete(nvSommet1,nvSommet2);
        graph->ajouterArc(nvArc);

        //Ajout au document XML
        domDocument.ajouterArc(nvArc);

        //Ajout du graphe au sommet pour observeur
        //nvArc->addObserver(affichageSVG);
        //GraphViz non thread-safe : affichage mal géré. Mieux vaut donc redemander l'affichage à chaque fois.

        //Ajout à l'arbre
        xmltree->ajouterArc(nvArc);
    }

    affichageSVG->drawGraph();
    //C'est tellement sale... Mais je ne vois vraiment pas comment faire autrement.
}

void Fenetre::ouvrir()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Séléctionner un fichier"),
                                                    QDir::currentPath(),
                                                    tr("Fichiers XML (*.xml)"));
    if (fileName.isEmpty())
        return;

    QFile fileXML(fileName);
    if (!fileXML.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Erreur lecture"),
                             tr("Impossible de lire le fichier %1:\n%2.")
                             .arg(fileName)
                             .arg(fileXML.errorString()));
        return;
    }

    QFile fileSchema("schemaGraph.xsd");
    fileSchema.open(QIODevice::ReadOnly);

    QXmlSchema schema;
    MessageHandler messageHandler;
    schema.setMessageHandler(&messageHandler);

    schema.load(&fileSchema, QUrl::fromLocalFile(fileSchema.fileName()));
    if (schema.isValid()) {
        QFile fileXML2(fileName);
        fileXML2.open(QIODevice::ReadOnly);

        QXmlSchemaValidator validator(schema);
        if (!validator.validate(&fileXML2, QUrl::fromLocalFile(fileXML2.fileName()))){
            QMessageBox::warning(this, tr("Fichier malformé"),
                                 tr("Impossible d'ouvrir le fichier' %1'.\n Le document ne correspond pas au schéma. \n%2")
                                 .arg(fileName)
                                 .arg(messageHandler.statusMessage()));
            return;
        }
    }

    ImportExport import=ImportExport(&graphe,xmltree, affichageSVG);
    if (import.ouvrir(&fileXML, &domDocument))
        ui->statusBar->showMessage(tr("Fichier chargé"), 2000);

    affichageSVG->drawGraph();
    ui->afficheGraphe->adjustSize();

    //On pense à remettre la liste des sommets pour créer les arcs
    redessinerComboArc();
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


    //ImportExport exporteur=ImportExport(&graphe,&sommetForString,&stringForSommet,xmltree);
    if (ImportExport::enregistrer(&file,&domDocument))
        ui->statusBar->showMessage(tr("Fichier enregisrté"), 2000);
}

void Fenetre::changeAttributSommet()
{
    if(graphe.isColore()){
        GrapheColore* graph=(GrapheColore*) graphe.getGraph();
        changeAttributSommetGraphe(graph);
    }
    else
    {
        Graphe* graph=(Graphe*)graphe.getGraph();
        changeAttributSommetGraphe(graph);
    }
    affichageSVG->drawGraph();
}

void Fenetre::changeAttributArc()
{
    Graphe* graph=(Graphe*)graphe.getGraph();
    vector<Arete*> listeArcs=graph->getListeArcs();
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
    for (int i = 0 ; i < listeArcs.size(); i++){
        boxArcs->addItem(listeArcs[i]->getDepart()->getNom()+"->"+listeArcs[i]->getArrivee()->getNom());
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
        Arete *arcModif=listeArcs[boxArcs->currentIndex()];

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

void Fenetre::colorerD()
{
    graphe.colorerGraphD();
    affichageSVG->drawGraph();
}

void Fenetre::colorerH()
{
    if (graphe.colorerGraphH())
        ui->statusBar->showMessage(tr("Coloration effectuée"), 2000);
    else
        ui->statusBar->showMessage(tr("Echec de la coloration"), 2000);

    affichageSVG->drawGraph();
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

    connect(ui->actionColorer_Directement,SIGNAL(triggered()), this, SLOT(colorerD()));
    connect(ui->actionColorer_Heuristique,SIGNAL(triggered()), this, SLOT(colorerH()));
}
