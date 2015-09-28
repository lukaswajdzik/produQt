#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H

#include "Controllers/MainWindowController.h"
#include "Configuration/ConfigurationProvider.h"
#include "Application/Session.h"

namespace Database{
    class DatabaseConnector;
    class IOperativeDatabaseConnector;
}
class QSqlQuery;

using Database::DatabaseConnector;
using Database::IOperativeDatabaseConnector;

using Configuration::ConfigurationProvider;

namespace Application
{
    class ApplicationContext
    {
    public:
        ApplicationContext();
        ~ApplicationContext();

        Session& getSession();
        std::shared_ptr<QSqlQuery> getConnection();
        std::shared_ptr<IOperativeDatabaseConnector> getOperativeDb();


    private:
        ConfigurationProvider m_configProvider;
        Session m_session;
        std::shared_ptr<DatabaseConnector> m_dbConnector;
        std::shared_ptr<IOperativeDatabaseConnector> m_dbOperativeConnector;
        std::shared_ptr<QSqlQuery> m_query;
    };

}
#endif // APPLICATIONCONTEXT_H
