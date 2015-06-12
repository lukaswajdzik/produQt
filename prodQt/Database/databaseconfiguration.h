#ifndef DATABASECONFIGURATION_H
#define DATABASECONFIGURATION_H

#include <QSettings>
#include <QString>

namespace Database
{
    class DatabaseConfiguration
    {
    public:
        DatabaseConfiguration();
        QString GetDatabaseHost();
        QString GetDatabaseName();
        int GetDatabasePort();
        QString GetUserName();
        QString GetUserPassword();
    private:
        QSettings *settings;
    };
}

#endif // DATABASECONFIGURATION_H
