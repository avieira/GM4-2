#include"fenetre.h"
#include"ui_fenetre.h"

void Fenetre::changeAttributSommetGraphe(Graphe* graph)
{
    vector<Sommet*>* listeSommets=graph->getListeSommets();
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
    for (int i = 0 ; i < listeSommets->size(); i++){
        boxSommets->addItem(graphe.obtenirId(listeSommets->at(i)));
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
        int currentIndex=boxSommets->currentIndex();
        Sommet *sommetModif=listeSommets->at(currentIndex);

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
            case 0 : { //On modifie le nom
                modifSommetNom(sommetModif);
                break;
            } case 1 : {//On modifie la forme
                modifSommetForme(sommetModif);
                break;
            } case 2 : {//On modifie la couleur
                if(!(graphe.isColore()))
                    graphe.grapheToColore();
                GrapheColore* grapheColore=(GrapheColore*)graphe.getGraph();
                SommetColore* sommetColore=grapheColore->getListeSommets()->at(currentIndex);
                modifSommetCouleur(sommetColore);
                break;
            }
            }
        }
    }
}

void Fenetre::changeAttributSommetGraphe(GrapheColore* graph)
{
    vector<SommetColore*>* listeSommets=graph->getListeSommets();
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
    for (int i = 0 ; i < listeSommets->size(); i++){
        boxSommets->addItem(graphe.obtenirId(listeSommets->at(i)));
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
        SommetColore *sommetModif=listeSommets->at(boxSommets->currentIndex());

        qDebug()<<"Dans changeAttributSommetGraphe : "<<sommetModif;
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
                modifSommetCouleur(sommetModif);
                break;
            }
            }
        }
    }
}

void Fenetre::modifSommetNom(Sommet *sommet)
{
    qDebug()<<"Dans modifSommetNom : "<<sommet;
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
        QString nvid=lineEdit->text();
        if(graphe.modifierId(sommet,nvid))
        {
            xmltree->changerNom(sommet);
            domDocument.changerNom(sommet);
        }
        else
            QMessageBox::warning(window(), tr("GraphCalculus"),
                                     tr("Le nom du sommet existe déjà !"));
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
    boxFormes->addItems(graphe.getListeForme());

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
        QString currentText=boxFormes->currentText();
        graphe.modifierForme(sommet,currentText);
        domDocument.changerForme(sommet);
        affichageSVG->drawGraph();
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
        //TODO : modifier affichage, document XML, arbreXML, via le pattern observer.
    }
}

void Fenetre::modifArcDepart(Arete* arc)
{
    Graphe* graph=(Graphe*)graphe.getGraph();
    vector<Sommet*>* listeSommets=graph->getListeSommets();
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
    for (int i = 0 ; i < listeSommets->size(); i++){
        boxSommets->addItem(graphe.obtenirId(listeSommets->at(i)));
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
        arc->setDepart(listeSommets->at(boxSommets->currentIndex()));
        //TODO : modifier affichage, xmltree, domdocument via observer
    }
}

void Fenetre::modifArcArrivee(Arete* arc)
{
    Graphe* graph=(Graphe*)graphe.getGraph();
    vector<Sommet*>* listeSommets=graph->getListeSommets();
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
    for (int i = 0 ; i < listeSommets->size(); i++){
        boxSommets->addItem(graphe.obtenirId(listeSommets->at(i)));
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
        arc->setArrivee(listeSommets->at(boxSommets->currentIndex()));
        //TODO : modifier affichage, xmltree, domdocument via observer
    }

}
