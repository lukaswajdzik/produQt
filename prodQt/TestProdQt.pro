TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
CONFIG += c++11

SOURCES += testMain.cpp \
    tests/blowfishprovidertestsuite.cpp \
    Utils/Exceptions/securitycheckfailedexception.cpp \
    Utils/blowfishprovider.cpp \

HEADERS  += Utils/constants.h \
            Utils/Exceptions/securitycheckfailedexception.h \
            Utils/blowfishprovider.h \

LIBS += -lpthread -lgtest -pthread

include(deployment.pri)
qtcAddDeployment()

