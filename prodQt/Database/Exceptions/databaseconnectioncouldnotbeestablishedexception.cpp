#include "databaseconnectioncouldnotbeestablishedexception.h"

namespace Database {
    DatabaseConnectionCouldNotBeEstablishedException::DatabaseConnectionCouldNotBeEstablishedException(QSqlError error)
    {
        ErrorMessage = "-Database driverText: " + error.driverText();
        ErrorMessage += " -databaseText: " + error.databaseText();
    }

    const char* DatabaseConnectionCouldNotBeEstablishedException::what() const throw() {
        return ErrorMessage.toStdString().c_str();
    }
}
