#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

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
        int GetState();
        bool VerifyUser(QString login, QString password);
    private:
        QSqlDatabase db;
        QString databaseHost;
        QString databasePort;
        QString databaseName;
        QString userName;
        QString userPassword;
        void InitializeConfiguration();
        void Connect();
        void Dispose();
    };
}

#endif
