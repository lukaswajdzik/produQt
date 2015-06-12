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
        void InitializeConfiguration();
        QString databaseHost;
        QString databaseName;
        int databasePort;
        QString userName;
        QString userPassword;
    };
}

#endif // DATABASECONFIGURATION_H
