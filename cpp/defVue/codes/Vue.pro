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
INCLUDEPATH+=/usr/include/graphviz/

SOURCES += main.cpp\
        Vue/fenetre.cpp\
        Model/sommet.cpp \
    Model/arete.cpp \
    Vue/xmltree.cpp \
    Vue/messagehandler.cpp \
    Model/sommetcolore.cpp \
    Model/sommetvalue.cpp \
    Model/graphe.cpp \
    Model/grapheoriente.cpp \
    Model/graphecolore.cpp \
    Vue/implemgraphviz.cpp

HEADERS  += Vue/fenetre.h \
    Model/sommet.h \
    Model/arete.h \
    Vue/xmltree.h \
    Vue/messagehandler.h \
    Model/sommetcolore.h \
    Model/sommetvalue.h \
    Model/graphe.h \
    Model/grapheoriente.h \
    Model/graphecolore.h \
    Vue/implemgraphviz.h

FORMS    += Vue/fenetre.ui

unix|win32: LIBS += -lgraph -lcgraph

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/lib/release/ -lcgraph
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../usr/lib/debug/ -lcgraph
else:unix: LIBS += -L$$PWD/../../../../../../../../usr/lib/ -lcgraph

INCLUDEPATH += $$PWD/../../../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../../../usr/include

unix|win32: LIBS += -lgvc -lcdt
