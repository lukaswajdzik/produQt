#include "databaseconnector.h"
#include <QDebug>

namespace Database
{
    DatabaseConnector::DatabaseConnector()
    {
        InitializeConfiguration();
        Connect();
    }

    DatabaseConnector::~DatabaseConnector()
    {
        Dispose();
    }

    int DatabaseConnector::GetState()
    {
        return 0;
    }

    bool DatabaseConnector::VerifyUser(QString login, QString password)
    {
        QSqlQuery query;
        query.exec("SELECT userpassword FROM users WHERE username = '" + login + "'");
        query.next();
        QString userPassword = query.value(0).toString();
        return password == userPassword;
    }

    void DatabaseConnector::InitializeConfiguration()
    {
        //TODO: Values to be taken from QSettings.
        databaseHost = "127.0.0.1";
        databasePort = "5432";
        databaseName = "H8";
        userName = "H8";
        userPassword = "";
    }

    void DatabaseConnector::Connect()
    {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName(databaseHost);
        db.setDatabaseName(databaseName);
        db.setUserName(userName);
        db.setPassword(userPassword);
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
