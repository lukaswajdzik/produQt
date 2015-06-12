#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>
#include "databaseconfiguration.h"

namespace Database
{
    class DatabaseConnector
    {
    public:
        DatabaseConnector();
        ~DatabaseConnector();
        int GetState();
        DatabaseConfiguration GetConfiguration();
        bool VerifyUser(QString login, QString password);
    private:
        QSqlDatabase db;
        DatabaseConfiguration configuration;
        void Connect();
        void Dispose();
    };
}

#endif
