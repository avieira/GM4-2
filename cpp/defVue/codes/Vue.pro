#-------------------------------------------------
#
# Project created by QtCreator 2014-04-21T21:30:08
#
#-------------------------------------------------

QT       += core gui xml xmlpatterns svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Vue
TEMPLATE = app
DEFINES += WITH_CGRAPH
INCLUDEPATH+=./graphviz/

SOURCES += main.cpp\
        Vue/fenetre.cpp\
        Model/sommet.cpp \
    Model/arete.cpp \
    Vue/xmltree.cpp \
    Vue/messagehandler.cpp \
    Model/sommetcolore.cpp \
    Model/graphe.cpp \
    Model/graphecolore.cpp \
    Vue/implemgraphviz.cpp \
    AccesDonnees/importexport.cpp \
    AccesDonnees/documentxml.cpp \
    Vue/interfacegraph.cpp

HEADERS  += Vue/fenetre.h \
    Model/sommet.h \
    Model/arete.h \
    Vue/xmltree.h \
    Vue/messagehandler.h \
    Model/sommetcolore.h \
    Model/graphe.h \
    Model/graphecolore.h \
    Vue/implemgraphviz.h \
    AccesDonnees/importexport.h \
    AccesDonnees/documentxml.h \
    Vue/interfacegraph.h

FORMS    += Vue/fenetre.ui

unix|win32: LIBS += -lgraph -lcgraph

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/lib/release/ -lcgraph
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/lib/debug/ -lcgraph
#else:unix: LIBS += -L$$PWD/../../../../../../../../usr/lib/ -lcgraph
#
#INCLUDEPATH += $$PWD/../../../../../../../../usr/include
#DEPENDPATH += $$PWD/../../../../../../../../usr/include

unix|win32: LIBS += -lgvc -lcdt
