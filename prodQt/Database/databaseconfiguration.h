#ifndef DATABASECONFIGURATION_H
#define DATABASECONFIGURATION_H

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
        QSettings settings;
        void InitializeConfiguration();
    };
}

#endif // DATABASECONFIGURATION_H
