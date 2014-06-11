#-------------------------------------------------
#
# Project created by QtCreator 2014-06-05T09:58:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = TestSommet
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Tests/TestSommet.cpp \
    Model/sommet.cpp \
    Model/sommetcolore.cpp \
    Obs/Observable.cpp \
    Obs/Observer.cpp

HEADERS += \
    Model/sommet.h \
    Model/sommetcolore.h \
    Obs/Observable.hpp \
    Obs/Observer.hpp

unix:LIBS += -lcppunit
