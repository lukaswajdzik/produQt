#ifndef CONFIGURATIONPROVIDER_H
#define CONFIGURATIONPROVIDER_H
#include <memory>
#include <QSettings>


namespace Configuration{
class DatabaseConfiguration;

    class ConfigurationProvider
    {
    public:
        ConfigurationProvider();
        ~ConfigurationProvider();
        std::shared_ptr<DatabaseConfiguration> getDatabaseConfigurator();
    private:
        std::shared_ptr<QSettings> m_settings;
    };

}

#endif // CONFIGURATIONPROVIDER_H
