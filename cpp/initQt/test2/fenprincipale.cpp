#include "fenprincipale.h"
#include<QMenuBar>
#include<QToolBar>

FenPrincipale::FenPrincipale()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    QMenu *fichiersRecents = menuFichier->addMenu("Fichiers &récents");
    fichiersRecents->addAction("Fichier bidon 1.txt");
    fichiersRecents->addAction("Fichier bidon 2.txt");
    fichiersRecents->addAction("Fichier bidon 3.txt");

    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));

    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

    QToolBar *toolBarFichier = addToolBar("Fichier");

    QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
}
