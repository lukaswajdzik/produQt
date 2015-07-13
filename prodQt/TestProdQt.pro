TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
CONFIG += c++11

SOURCES += testMain.cpp \
    tests/blowfishprovidertestsuite.cpp \
    Utils/Exceptions/securitycheckfailedexception.cpp \

HEADERS  += Utils/constants.h \
            Utils/Exceptions/securitycheckfailedexception.h \

LIBS += -lpthread -lgtest -pthread

include(deployment.pri)
qtcAddDeployment()

