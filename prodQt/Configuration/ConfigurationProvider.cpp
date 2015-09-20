#include "ConfigurationProvider.h"
#include "Configuration/DatabaseConfiguration.h"
#include <QMessageBox>

namespace Configuration
{


ConfigurationProvider::ConfigurationProvider()
{
    m_settings = std::make_shared<QSettings>( "config.ini", QSettings::IniFormat);
    //TODO: check if the file was read correctly
}

ConfigurationProvider::~ConfigurationProvider()
{}

std::shared_ptr<DatabaseConfiguration> ConfigurationProvider::getDatabaseConfigurator()
{
    return std::make_shared<DatabaseConfiguration>(m_settings);
}

}
