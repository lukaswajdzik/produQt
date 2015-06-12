#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T16:05:25
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prodQt
TEMPLATE = app


SOURCES += main.cpp\
        Visuals/mainwindow.cpp \
    Database/databaseconnector.cpp \
    Utils/logger.cpp \
    Visuals/databasetestwindow.cpp \
    Database/databaseconfiguration.cpp

HEADERS  += Visuals/mainwindow.h \
    Database/databaseconnector.h \
    Utils/logger.h \
    Visuals/databasetestwindow.h \
    Database/databaseconfiguration.h

FORMS    += Visuals/mainwindow.ui \
    Visuals/databasetestwindow.ui

CONFIG += c++11

DISTFILES += \
    config.ini

configfile.path     = $${DESTDIR}
configfile.files    += config.ini
INSTALLS    += configfile
