#ifndef DATABASECONNECTIONCOULDNOTBEESTABLISHEDEXCEPTION_H
#define DATABASECONNECTIONCOULDNOTBEESTABLISHEDEXCEPTION_H

#include <exception>
#include <QString>
#include <QSqlError>

namespace Database {
    class DatabaseConnectionCouldNotBeEstablishedException : public std::exception {
    public:
        DatabaseConnectionCouldNotBeEstablishedException(QSqlError);
        const char* what() const throw();
        private:
            QString ErrorMessage;
    };
}

#endif // DATABASECONNECTIONCOULDNOTBEESTABLISHEDEXCEPTION_H
