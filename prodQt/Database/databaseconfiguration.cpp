#include "databaseconfiguration.h"
#include <QSettings>

namespace Database
{
    DatabaseConfiguration::DatabaseConfiguration()
    {
        InitializeConfiguration();
    }

    void DatabaseConfiguration::InitializeConfiguration()
    {
        QString strKey("database/");
        QSettings * settings = 0;
        settings = new QSettings( file_path, QSettings::IniFormat );
        databaseHost = settings->value( strKey + "database_host", "r").toString();
        databaseName = settings->value( strKey + "database_name", "r").toString();
        databasePort = settings->value( strKey + "database_port", "r").Int;
        userName = settings->value( strKey + "user_name", "r").toString();
        userPassword = settings->value( strKey + "user_password", "r").toString();
    }

    QString DatabaseConfiguration::GetDatabaseHost()
    {
        return databaseHost;
    }

    QString DatabaseConfiguration::GetDatabaseName()
    {
        return databaseName;
    }

    int DatabaseConfiguration::GetDatabasePort()
    {
        return databasePort;
    }

    QString DatabaseConfiguration::GetUserName()
    {
        return userName;
    }

    QString DatabaseConfiguration::GetUserPassword()
    {
        return userPassword;
    }
}

