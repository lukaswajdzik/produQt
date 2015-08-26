#include "databaseconnector.h"
#include "Exceptions/databaseconnectioncouldnotbeestablishedexception.h"
#include <QDebug>
#include <QString>
#include "Utils/blowfishprovider.h"
#include "Database/databasequeryprovider.h"


namespace Database {
    DatabaseConnector::DatabaseConnector() {
        Connect();
    }

    DatabaseConnector::~DatabaseConnector() {
        Dispose();
    }

    bool DatabaseConnector::isConnected(){
        if (db.isOpen())
            return true;
        else
            return false;
    }

    bool DatabaseConnector::reconnect(){
        db.close();
        return db.open();
    }

    void DatabaseConnector::Connect() {
        db = QSqlDatabase::addDatabase("QPSQL");
        DatabaseConfiguration configuration;
        ConfigureDatabase(db, configuration);
        if (!db.open()) {
            qDebug() << "Database error occurred";
            throw DatabaseConnectionCouldNotBeEstablishedException(db.lastError());
        }
        qDebug() << "Database connection etablished";
    }

    void DatabaseConnector::Dispose() {
        if(!isConnected()) {
            db.close();
        }
        qDebug() << "Database connection disposed!";
    }

    void DatabaseConnector::ConfigureDatabase(QSqlDatabase db, DatabaseConfiguration configuration) {
        QString passwordDecoded = Utils::BlowFishProvider::GetDbPasswordDecoded(configuration.GetUserPassword());
        db.setHostName(configuration.GetDatabaseHost());
        db.setPort(configuration.GetDatabasePort());
        db.setDatabaseName(configuration.GetDatabaseName());
        db.setUserName(configuration.GetUserName());
        db.setPassword(passwordDecoded);
    }


}
