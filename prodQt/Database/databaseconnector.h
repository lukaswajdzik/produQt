#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include "databaseconfiguration.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>

namespace Database
{
    class DatabaseConnector
    {
    public:
        DatabaseConnector();
        ~DatabaseConnector();
        bool VerifyUser(QString login, QString password);
    private:
        QSqlDatabase db;
        void Connect();
        void Dispose();
    };
}

#endif
