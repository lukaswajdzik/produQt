#include "databaseconnector.h"
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

    bool DatabaseConnector::VerifyUser(QString login, QString password)
    {
        QSqlQuery query;
        query.exec("SELECT userpassword FROM users WHERE username = '" + login + "'");
        query.next();
        QString userPassword = query.value(0).toString();
        return password == userPassword;
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
            return;
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
}
