#include "databaseconnector.h"
#include "Exceptions/databaseconnectioncouldnotbeestablishedexception.h"
#include <QDebug>
#include <QString>
#include "Utils/blowfishprovider.h"
#include "Database/databasequeryprovider.h"
#include "Utils/logger.h"
#include <QMessageBox>


namespace Database {
    DatabaseConnector::DatabaseConnector(DbConfigPtr p_DbConfig) : m_DbConfig(p_DbConfig){
        Connect();
    }

    DatabaseConnector::~DatabaseConnector(){
        Dispose();
    }

    bool DatabaseConnector::isConnected(){
        if (m_SqlDb.isOpen())
            return true;
        else
            return false;
    }

    bool DatabaseConnector::reconnect(){
        m_SqlDb.close();
        return m_SqlDb.open();
    }

    void DatabaseConnector::Connect() {
        try{
            m_SqlDb = QSqlDatabase::addDatabase("QPSQL");
            ConfigureDatabase(m_SqlDb, m_DbConfig);
            if (!m_SqlDb.open()) {
                qDebug() << "Database error occurred";
                throw DatabaseConnectionCouldNotBeEstablishedException(m_SqlDb.lastError());
            }
            qDebug() << "Database connection etablished";
            }
        catch(std::exception& e) {
            qDebug() << e.what();
            Logger::getInstance().log(e.what());
            QMessageBox::information(0, "Błąd",  "Nie można połączyć z bazą danych.");
        }
    }

    void DatabaseConnector::Dispose() {
        if(!isConnected()) {
            m_SqlDb.close();
        }
        qDebug() << "Database connection disposed!";
    }

    void DatabaseConnector::ConfigureDatabase(QSqlDatabase db, DbConfigPtr configuration) {
        QString passwordDecoded = Utils::BlowFishProvider::GetDbPasswordDecoded(configuration->GetUserPassword());
        db.setHostName(configuration->GetDatabaseHost());
        db.setPort(configuration->GetDatabasePort());
        db.setDatabaseName(configuration->GetDatabaseName());
        db.setUserName(configuration->GetUserName());
        db.setPassword(passwordDecoded);
    }


}
