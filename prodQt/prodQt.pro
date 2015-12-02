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
    Database/databaseconnector.cpp \
    Utils/logger.cpp \
    Controllers/databasetestwindow.cpp \
    Database/Exceptions/databaseconnectioncouldnotbeestablishedexception.cpp \
    Utils/Exceptions/securitycheckfailedexception.cpp \
    Utils/blowfishprovider.cpp \
    Utils/blowFIshProviderTestSuite.cpp \
    Database/useroperativedb.cpp \
    Application/ApplicationContext.cpp \
    Application/Session.cpp \
    Configuration/DatabaseConfiguration.cpp \
    Configuration/ConfigurationProvider.cpp \
    Modules/UserModifierModule.cpp \
    Controllers/UserAddingController.cpp \
    Modules/UserAddingModule.cpp \
    Modules/Module.cpp \
    Controllers/UserAddingControllerFactory.cpp \
    Controllers/FirstUserAddingController.cpp \
    Dao/UserDao.cpp \
    Dao/Exceptions/DbQueryCouldNotBeExecuted.cpp \
    Controllers/LoginController.cpp \
    Dao/LoginDao.cpp \
    Modules/UserLoginModule.cpp \
    Utils/Subject.cpp \
    View/MainWindowView.cpp \
    View/LoginView.cpp \
    Controllers/MainWindowControllerOLD.cpp \
    Controllers/MainWindowController.cpp \
    View/NumericKeyboard.cpp \
    Utils/button.cpp \
    View/TableEditorView.cpp \
    View/WeightTabView.cpp \
    Utils/FullAccessWorkingWindowBuilder.cpp \
    View/WorkingTabsView.cpp

HEADERS  += \
    Database/databaseconnector.h \
    Utils/logger.h \
    Controllers/databasetestwindow.h \
    Database/Exceptions/databaseconnectioncouldnotbeestablishedexception.h \
    External/blowfish.h \
    Utils/constants.h \
    Utils/blowfishprovider.h \
    Utils/Exceptions/securitycheckfailedexception.h \
    Database/databasequeryprovider.h \
    Database/useroperativedb.h \
    Database/ioperativedatabaseconnector.h \
    Application/ApplicationContext.h \
    Application/Session.h \
    Configuration/DatabaseConfiguration.h \
    Configuration/ConfigurationProvider.h \
    Modules/UserModifierModule.h \
    Controllers/UserAddingController.h \
    Modules/UserAddingModule.h \
    Modules/Module.h \
    Controllers/UserAddingControllerFactory.h \
    Controllers/IUserAddingController.h \
    Controllers/FirstUserAddingController.h \
    Dao/UserDao.h \
    Dao/Exceptions/DbQueryCouldNotBeExecuted.h \
    Controllers/LoginController.h \
    Dao/LoginDao.h \
    Modules/UserLoginModule.h \
    Utils/Observer.h \
    Utils/Subject.h \
    View/MainWindowView.h \
    View/LoginView.h \
    Controllers/MainWindowControllerOLD.h \
    Controllers/MainWindowController.h \
    View/IWorkingWindow.h \
    View/NumericKeyboard.h \
    Utils/button.h \
    View/TableEditorView.h \
    View/WeightTabView.h \
    Dao/UserDaoRecord.h \
    Utils/FullAccessWorkingWindowBuilder.h \
    Utils/WorkingWindowBuilder.h \
    View/WorkingTabsView.h \
    Utils/UserAccessType.h \
    Application/UserAccessType.h

FORMS    += Controllers/mainwindow.ui \
    Controllers/databasetestwindow.ui \
    Controllers/adduser.ui

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
