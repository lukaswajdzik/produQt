#include "databaseconfiguration.h"
#include <iostream>
#include <QDebug>

namespace Database {
    DatabaseConfiguration::DatabaseConfiguration() {
        settings = std::make_shared<QSettings>( "config.ini", QSettings::IniFormat );
    }

    QString DatabaseConfiguration::GetDatabaseHost() {
        QString value = settings->value( "database/database_host", "").toString();
        qDebug() << "Host: " << value << endl;
        return value;
    }

    QString DatabaseConfiguration::GetDatabaseName() {
        QString value = settings->value( "database/database_name", "").toString();
        qDebug() << "DatabaseName: " << value << endl;
        return value;
    }

    int DatabaseConfiguration::GetDatabasePort() {
        int value = settings->value( "database/database_port", "").toInt();
        qDebug() << "DatabasePort: " << value << endl;
        return value;
    }

    QString DatabaseConfiguration::GetUserName() {
        QString value = settings->value( "database/user_name", "").toString();
        qDebug() << "UserName: " << value << endl;
        return value;
    }

    QString DatabaseConfiguration::GetUserPassword() {
        QString value = settings->value( "database/user_password", "").toString();
        qDebug() << "Pass: " << value << endl;
        return value;
    }
}

