#ifndef DATABASECONFIGURATION_H
#define DATABASECONFIGURATION_H

#include <QSettings>
#include <QString>
#include <memory>

namespace Database {
    class DatabaseConfiguration {
    public:
        //TODO: memorize ini configuration in the DB!
        DatabaseConfiguration();
        QString GetDatabaseHost();
        QString GetDatabaseName();
        int GetDatabasePort();
        QString GetUserName();
        QString GetUserPassword();
    private:
        std::shared_ptr<QSettings> settings;
    };
}

#endif // DATABASECONFIGURATION_H
