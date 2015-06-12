#include "databaseconnector.h"
#include "Exceptions/databaseconnectioncouldnotbeestablishedexception.h"
#include <QDebug>

namespace Database
{
    DatabaseConnector::DatabaseConnector()
    {
        Connect();
    }

    DatabaseConnector::~DatabaseConnector()
    {
        Dispose();
    }

    void DatabaseConnector::Connect()
    {
        db = QSqlDatabase::addDatabase("QPSQL");
        DatabaseConfiguration configuration;
        db.setHostName(configuration.GetDatabaseHost());
        db.setPort(configuration.GetDatabasePort());
        db.setDatabaseName(configuration.GetDatabaseName());
        db.setUserName(configuration.GetUserName());
        db.setPassword(configuration.GetUserPassword());
        if (!db.open()) {
            qDebug() << "Database error occurred";
            throw new DatabaseConnectionCouldNotBeEstablishedException(configuration.GetDatabaseName());
        }
        qDebug() << "Database connection etablished";
    }

    void DatabaseConnector::Dispose()
    {
        if(db.isOpen()){
            db.close();
        }
        qDebug() << "Database connection disposed";
    }

    bool IOperativeDatabaseConnector::VerifyUser(QString login, QString password)
    {
        QSqlQuery query;
        query.exec("SELECT userpassword FROM users WHERE username = '" + login + "'");
        query.next();
        QString userPassword = query.value(0).toString();
        return password == userPassword;
    }
}
