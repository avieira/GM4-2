#-------------------------------------------------
#
# Project created by QtCreator 2014-06-05T09:43:00
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = TestGraphe
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Tests/TestGraphe.cpp \
    Model/graphe.cpp \
    Model/arete.cpp \
    Model/sommet.cpp \
    Obs/Observable.cpp \
    Obs/Observer.cpp \
    Model/sommetcolore.cpp

HEADERS += \
    Model/graphe.h \
    Model/arete.h \
    Model/sommet.h \
    Obs/Observable.hpp \
    Obs/Observer.hpp \
    Model/sommetcolore.h

unix:LIBS += -lcppunit
