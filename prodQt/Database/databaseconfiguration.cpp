#include "databaseconfiguration.h"

namespace Database {
    DatabaseConfiguration::DatabaseConfiguration() {
        settings = new QSettings( "config.ini", QSettings::IniFormat );
    }

    QString DatabaseConfiguration::GetDatabaseHost() {
        QString value = settings->value( "database/database_host", "").toString();
        return value;
    }

    QString DatabaseConfiguration::GetDatabaseName() {
        QString value = settings->value( "database/database_name", "").toString();
        return value;
    }

    int DatabaseConfiguration::GetDatabasePort() {
        int value = settings->value( "database/database_port", "").toInt();
        return value;
    }

    QString DatabaseConfiguration::GetUserName() {
        QString value = settings->value( "database/user_name", "").toString();
        return value;
    }

    QString DatabaseConfiguration::GetUserPassword() {
        QString value = settings->value( "database/user_password", "").toString();
        return value;
    }
}

