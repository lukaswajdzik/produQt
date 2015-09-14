#include "ConfigurationProvider.h"
#include "Configuration/DatabaseConfiguration.h"

namespace Configuration
{


ConfigurationProvider::ConfigurationProvider()
{
    m_settings = std::make_shared<QSettings>( "config.ini", QSettings::IniFormat);
}

ConfigurationProvider::~ConfigurationProvider()
{}

std::shared_ptr<DatabaseConfiguration> ConfigurationProvider::getDatabaseConfigurator()
{
    return std::make_shared<DatabaseConfiguration>(m_settings);
}

}
