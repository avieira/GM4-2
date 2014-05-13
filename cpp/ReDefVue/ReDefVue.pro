#-------------------------------------------------
#
# Project created by QtCreator 2014-05-08T17:03:08
#
#-------------------------------------------------

QT       += core gui xml xmlpatterns svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReDefVue
TEMPLATE = app
#DEFINES += WITH_CGRAPH
INCLUDEPATH+=./graphviz/


SOURCES += Vue/main.cpp\
    Model/arete.cpp \
    Model/sommet.cpp \
    Model/sommetcolore.cpp \
    Model/graphe.cpp \
    Model/graphecolore.cpp \
    AccesDonnees/importexport.cpp \
    Vue/xmltree.cpp \
    Vue/messagehandler.cpp \
    AccesDonnees/documentxml.cpp \
    Vue/implemgraphviz.cpp \
    Vue/fenetre-Slots.cpp \
    Vue/fenetre-MethodePrivees.cpp \
    Vue/fenetre-ConDestructeur.cpp \
    Vue/interfacegraph.cpp \
    Model/solution.cpp \
    ../Tests/testgraphe.cpp \
    ../Tests/testsommet.cpp \
    ../Tests/testsommetcolore.cpp

HEADERS  += Vue/fenetre.h \
    AccesDonnees/importexport.h\
    Model/sommet.h \
    Model/arete.h \
    Model/sommetcolore.h \
    Model/graphe.h \
    Model/graphecolore.h \
    Vue/xmltree.h \
    Vue/messagehandler.h \
    AccesDonnees/documentxml.h \
    Vue/implemgraphviz.h \
    Vue/interfacegraph.h \
    Model/solution.h


FORMS    += Vue/fenetre.ui

unix|win32: LIBS += -lgvc -lcdt -lgraph -std=c++11
