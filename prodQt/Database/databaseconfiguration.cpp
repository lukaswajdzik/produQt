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
        settings = new QSettings( file_path, QSettings::IniFormat );
    }

    QString DatabaseConfiguration::GetDatabaseHost()
    {
        return settings->value( "database/database_host", "r").toString();
    }

    QString DatabaseConfiguration::GetDatabaseName()
    {
        return settings->value( "database/database_name", "r").toString();
    }

    int DatabaseConfiguration::GetDatabasePort()
    {
        return settings->value( "database/database_port", "r").Int;
    }

    QString DatabaseConfiguration::GetUserName()
    {
        return settings->value( "database/user_name", "r").toString();
    }

    QString DatabaseConfiguration::GetUserPassword()
    {
        return settings->value( "database/user_password", "r").toString();
    }
}

