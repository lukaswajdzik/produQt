#include "databaseconnectioncouldnotbeestablishedexception.h"

namespace Database {
    DatabaseConnectionCouldNotBeEstablishedException::DatabaseConnectionCouldNotBeEstablishedException(QString databaseName) {
        ErrorMessage = "Database " + databaseName + " connection could not be established";
    }

    const char* DatabaseConnectionCouldNotBeEstablishedException::what() const throw() {
        return ErrorMessage.toStdString().c_str();
    }
}
