#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include "Configuration/DatabaseConfiguration.h"
#include "ioperativedatabaseconnector.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>

namespace Utils{
    class Logger;
}
namespace Configuration {
    class DatabaseConfiguration;
}

using Utils::Logger;
using Configuration::DatabaseConfiguration;
using DbConfigPtr = std::shared_ptr<DatabaseConfiguration>;

namespace Database {
    class DatabaseQueryProvider;

    class DatabaseConnector {
    public:
        DatabaseConnector(DbConfigPtr);
        ~DatabaseConnector();
        bool isConnected();
        //TODO: implement reconnection mechanism: a few attampt to connect with possibility to manually change a DB data, like DB name etc
        bool reconnect();
    private:
        void Connect();
        void Dispose();
        void ConfigureDatabase(QSqlDatabase, DbConfigPtr);

        QSqlDatabase m_SqlDb;
        DbConfigPtr m_DbConfig;
    };
}

#endif
