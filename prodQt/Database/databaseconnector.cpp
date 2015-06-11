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

    int DatabaseConnector::GetState()
    {
        return 0;
    }

    bool DatabaseConnector::VerifyUser(QString login, QString password)
    {
        return login != "" && password != "";
        //TODO: first database method.
    }

    void DatabaseConnector::Connect()
    {
        qDebug() << "Database connection etablished";
        //TODO: database connection in accordance with configuration file.
    }

    void DatabaseConnector::Dispose()
    {
        qDebug() << "Database connection disposed";
        //TODO: safe database disconnection.
    }
}
