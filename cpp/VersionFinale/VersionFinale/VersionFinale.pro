#-------------------------------------------------
#
# Project created by QtCreator 2014-06-01T14:34:09
#
#-------------------------------------------------

QT       += core gui xml xmlpatterns svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PColoGraph
TEMPLATE = app
INCLUDEPATH += ./graphviz/


SOURCES += main.cpp\
        Vue/fenetre.cpp \
    Model/arete.cpp \
    Model/graphe.cpp \
    Model/graphecolore.cpp \
    Model/solution.cpp \
    Model/sommet.cpp \
    Model/sommetcolore.cpp \
    Obs/Observable.cpp \
    Obs/Observer.cpp \
    Vue/fenetre-Slots.cpp \
    Vue/interfacegraph.cpp \
    AccesDonnees/arbreitemsommet.cpp \
    AccesDonnees/xmlelementsommet.cpp \
    AccesDonnees/arbreitemarete.cpp \
    AccesDonnees/xmlelementarete.cpp \
    AccesDonnees/documentxml.cpp \
    Vue/implemgraphviz.cpp \
    Vue/xmltree.cpp \
    AccesDonnees/importexport.cpp \
    Vue/messagehandler.cpp \
    Vue/fenetre-MethodesPrivees.cpp

HEADERS  += Vue/fenetre.h \
    Model/arete.h \
    Model/graphe.h \
    Model/graphecolore.h \
    Model/solution.h \
    Model/sommet.h \
    Model/sommetcolore.h \
    Obs/Observable.hpp \
    Obs/Observer.hpp \
    Vue/interfacegraph.h \
    AccesDonnees/arbreitemsommet.h \
    AccesDonnees/xmlelementsommet.h \
    AccesDonnees/arbreitemarete.h \
    AccesDonnees/xmlelementarete.h \
    AccesDonnees/documentxml.h \
    Vue/implemgraphviz.h \
    Vue/xmltree.h \
    AccesDonnees/importexport.h \
    Vue/messagehandler.h

FORMS    += Vue/fenetre.ui

unix|win32: LIBS += -lgvc -lcdt -lgraph -std=c++11
