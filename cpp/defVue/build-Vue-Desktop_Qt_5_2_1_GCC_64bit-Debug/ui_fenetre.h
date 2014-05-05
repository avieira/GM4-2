/********************************************************************************
** Form generated from reading UI file 'fenetre.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETRE_H
#define UI_FENETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fenetre
{
public:
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionAttribut_sommet;
    QAction *actionAttribut_arc;
    QAction *actionQuitter;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *afficheGraphe;
    QFrame *conteneurDroite;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Fenetre)
    {
        if (Fenetre->objectName().isEmpty())
            Fenetre->setObjectName(QStringLiteral("Fenetre"));
        Fenetre->resize(892, 538);
        actionOuvrir = new QAction(Fenetre);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionEnregistrer = new QAction(Fenetre);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        actionAttribut_sommet = new QAction(Fenetre);
        actionAttribut_sommet->setObjectName(QStringLiteral("actionAttribut_sommet"));
        actionAttribut_arc = new QAction(Fenetre);
        actionAttribut_arc->setObjectName(QStringLiteral("actionAttribut_arc"));
        actionQuitter = new QAction(Fenetre);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(Fenetre);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        afficheGraphe = new QFrame(centralWidget);
        afficheGraphe->setObjectName(QStringLiteral("afficheGraphe"));
        afficheGraphe->setFrameShape(QFrame::StyledPanel);
        afficheGraphe->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(afficheGraphe);

        conteneurDroite = new QFrame(centralWidget);
        conteneurDroite->setObjectName(QStringLiteral("conteneurDroite"));
        conteneurDroite->setMinimumSize(QSize(300, 0));
        conteneurDroite->setFrameShape(QFrame::StyledPanel);
        conteneurDroite->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(conteneurDroite);

        Fenetre->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Fenetre);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 892, 20));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        Fenetre->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Fenetre);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Fenetre->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Fenetre);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Fenetre->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionAttribut_sommet);
        menuEdition->addAction(actionAttribut_arc);
        mainToolBar->addAction(actionOuvrir);
        mainToolBar->addAction(actionEnregistrer);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAttribut_sommet);
        mainToolBar->addAction(actionAttribut_arc);

        retranslateUi(Fenetre);

        QMetaObject::connectSlotsByName(Fenetre);
    } // setupUi

    void retranslateUi(QMainWindow *Fenetre)
    {
        Fenetre->setWindowTitle(QApplication::translate("Fenetre", "Fenetre", 0));
        actionOuvrir->setText(QApplication::translate("Fenetre", "Ouvrir", 0));
#ifndef QT_NO_TOOLTIP
        actionOuvrir->setToolTip(QApplication::translate("Fenetre", "Importer un document XML", 0));
#endif // QT_NO_TOOLTIP
        actionOuvrir->setShortcut(QApplication::translate("Fenetre", "Ctrl+O", 0));
        actionEnregistrer->setText(QApplication::translate("Fenetre", "Enregistrer", 0));
#ifndef QT_NO_TOOLTIP
        actionEnregistrer->setToolTip(QApplication::translate("Fenetre", "Enregistrer le graphe sous forme d'un document XML", 0));
#endif // QT_NO_TOOLTIP
        actionEnregistrer->setShortcut(QApplication::translate("Fenetre", "Ctrl+S", 0));
        actionAttribut_sommet->setText(QApplication::translate("Fenetre", "Attribut sommet", 0));
#ifndef QT_NO_TOOLTIP
        actionAttribut_sommet->setToolTip(QApplication::translate("Fenetre", "Modifier ou ajouter un attribut \303\240 un sommet", 0));
#endif // QT_NO_TOOLTIP
        actionAttribut_arc->setText(QApplication::translate("Fenetre", "Attribut arc", 0));
#ifndef QT_NO_TOOLTIP
        actionAttribut_arc->setToolTip(QApplication::translate("Fenetre", "Ajouter ou modifier l'attribut d'un rc", 0));
#endif // QT_NO_TOOLTIP
        actionQuitter->setText(QApplication::translate("Fenetre", "Quitter", 0));
        menuFichier->setTitle(QApplication::translate("Fenetre", "&Fichier", 0));
        menuEdition->setTitle(QApplication::translate("Fenetre", "&Edition", 0));
    } // retranslateUi

};

namespace Ui {
    class Fenetre: public Ui_Fenetre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETRE_H
