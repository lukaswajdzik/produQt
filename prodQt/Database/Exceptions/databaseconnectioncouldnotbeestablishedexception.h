#ifndef DATABASECONNECTIONCOULDNOTBEESTABLISHEDEXCEPTION_H
#define DATABASECONNECTIONCOULDNOTBEESTABLISHEDEXCEPTION_H

#include <exception>
#include <QString>

namespace Database {
    class DatabaseConnectionCouldNotBeEstablishedException : public std::exception {
    public:
        DatabaseConnectionCouldNotBeEstablishedException(QString databaseName);
        virtual const char* what() const throw();
        private:
            QString ErrorMessage;
    };
}

#endif // DATABASECONNECTIONCOULDNOTBEESTABLISHEDEXCEPTION_H
