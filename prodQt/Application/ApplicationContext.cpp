#include "ApplicationContext.h"
#include <QDebug>
#include "Utils/logger.h"
#include <QMessageBox>
#include "Database/databaseconnector.h"

using Logger = Utils::Logger;

namespace Application
{
    ApplicationContext::ApplicationContext(MainWindow &win)
        : m_mainWindow(win)
    {
        m_mainWindow.show();
        m_dbConnector = std::make_shared<DatabaseConnector>(m_configProvider.getDatabaseConfigurator());
    }

    ApplicationContext::~ApplicationContext()
    {}

}

