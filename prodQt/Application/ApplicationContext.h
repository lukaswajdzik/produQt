#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H

#include "Visuals/mainwindow.h"
#include "Configuration/ConfigurationProvider.h"

namespace Database{
    class DatabaseConnector;
}

using Database::DatabaseConnector;
using Configuration::ConfigurationProvider;

namespace Application
{

    class ApplicationContext
    {
    public:
        ApplicationContext(MainWindow&);
        ~ApplicationContext();

    private:
        MainWindow& m_mainWindow;
        ConfigurationProvider m_configProvider;

        std::shared_ptr<DatabaseConnector> m_dbConnector;

    };

}
#endif // APPLICATIONCONTEXT_H
