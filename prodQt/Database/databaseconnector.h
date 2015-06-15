#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include "databaseconfiguration.h"
#include "ioperaticedatabaseconnector.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>

namespace Database {
    class DatabaseConnector : public IOperativeDatabaseConnector {
    public:
        DatabaseConnector();
        ~DatabaseConnector();
    private:
        QSqlDatabase db;
        void Connect();
        void Dispose();
        void ConfigureDatabase(QSqlDatabase db, DatabaseConfiguration configuration);
    };
}

#endif
