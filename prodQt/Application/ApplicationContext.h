#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H

#include "Controllers/MainWindowController.h"
#include "Configuration/ConfigurationProvider.h"
#include "Application/Session.h"

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
        ApplicationContext();
        ~ApplicationContext();

        Session &getSession();

    private:
        ConfigurationProvider m_configProvider;
        Session m_session;
        std::shared_ptr<DatabaseConnector> m_dbConnector;
    };

}
#endif // APPLICATIONCONTEXT_H
