#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include "databaseconfiguration.h"
#include "ioperativedatabaseconnector.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>

namespace Database {
    class DatabaseQueryProvider;

    class DatabaseConnector {
    public:
        DatabaseConnector();
        ~DatabaseConnector();
        bool isConnected();
        //TODO: implement reconnection mechanism: a few attampt to connect with possibility to manually change a DB data, like DB name etc
        bool reconnect();
    private:
        QSqlDatabase db;
        void Connect();
        void Dispose();
        void ConfigureDatabase(QSqlDatabase db, DatabaseConfiguration configuration);
    };
}

#endif
