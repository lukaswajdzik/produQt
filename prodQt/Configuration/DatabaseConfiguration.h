#ifndef DATABASECONFIGURATION_H
#define DATABASECONFIGURATION_H

#include <QSettings>
#include <QString>
#include <memory>

namespace Configuration {

    class DatabaseConfiguration {
    public:
        //TODO: memorize ini configuration in the DB!
        DatabaseConfiguration(std::shared_ptr<QSettings>&);
        QString GetDatabaseHost();
        QString GetDatabaseName();
        int GetDatabasePort();
        QString GetUserName();
        QString GetUserPassword();
    private:
        std::shared_ptr<QSettings> m_settings;
    };
}

#endif // DATABASECONFIGURATION_H
