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
LIBS = \
       -lboost_system\

SOURCES += main.cpp\
        Visuals/mainwindow.cpp \
    Database/databaseconnector.cpp \
    Utils/logger.cpp \
    Visuals/databasetestwindow.cpp \
    Database/databaseconfiguration.cpp \
    Database/Exceptions/databaseconnectioncouldnotbeestablishedexception.cpp \
    Utils/Exceptions/securitycheckfailedexception.cpp \
    Utils/blowfishprovider.cpp

HEADERS  += Visuals/mainwindow.h \
    Database/databaseconnector.h \
    Utils/logger.h \
    Visuals/databasetestwindow.h \
    Database/databaseconfiguration.h \
    Database/Exceptions/databaseconnectioncouldnotbeestablishedexception.h \
    Database/ioperaticedatabaseconnector.h \
    External/blowfish.h \
    Utils/constants.h \
    Utils/blowfishprovider.h \
    Utils/Exceptions/securitycheckfailedexception.h

FORMS    += Visuals/mainwindow.ui \
    Visuals/databasetestwindow.ui

CONFIG += c++11

DISTFILES += \
    config.ini

win32 {
}
macx {
    APP_CONFIG_FILES.files = $$PWD/config.ini
    APP_CONFIG_FILES.path = Contents/MacOS
    QMAKE_BUNDLE_DATA += APP_CONFIG_FILES
}
