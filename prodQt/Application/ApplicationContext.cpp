#include "ApplicationContext.h"
#include <QDebug>
#include "Utils/logger.h"
#include <QMessageBox>
#include "Database/databaseconnector.h"
#include "Database/useroperativedb.h"
#include <QtSql/QSqlQuery>

using Logger = Utils::Logger;

namespace Application
{
    ApplicationContext::ApplicationContext()
    {
        m_dbConnector = std::make_shared<DatabaseConnector>(m_configProvider.getDatabaseConfigurator());
        m_dbOperativeConnector = std::make_shared<Database::UserOperativeDb>();
        m_query = std::make_shared<QSqlQuery>();
    }
//TBD
    ApplicationContext::~ApplicationContext()
    {}

    Session& ApplicationContext::getSession()
    {
        return m_session;
    }

    std::shared_ptr<QSqlQuery> ApplicationContext::getConnection()
    {
        return m_query;
    }

    std::shared_ptr<Database::IOperativeDatabaseConnector> ApplicationContext::getOperativeDb()
    {
        return m_dbOperativeConnector;
    }

}

