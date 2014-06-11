#-------------------------------------------------
#
# Project created by QtCreator 2014-06-06T13:23:22
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = TestGrapheColore
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Tests/TestGrapheColore.cpp \
    Model/arete.cpp \
    Model/graphe.cpp \
    Model/graphecolore.cpp \
    Model/sommet.cpp \
    Model/sommetcolore.cpp \
    Obs/Observable.cpp \
    Obs/Observer.cpp \
    Model/solution.cpp

HEADERS += \
    Model/arete.h \
    Model/graphe.h \
    Model/graphecolore.h \
    Model/sommet.h \
    Model/sommetcolore.h \
    Obs/Observable.hpp \
    Obs/Observer.hpp \
    Model/solution.h

unix:LIBS += -lcppunit
