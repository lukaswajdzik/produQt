#include "ApplicationContext.h"
#include <QDebug>
#include "Utils/logger.h"
#include <QMessageBox>

using Logger = Utils::Logger;

namespace Application
{
    ApplicationContext::ApplicationContext(MainWindow &win) : window(win)
    {
        window.show();
        window.setDbLabelAsIsConnecting();
        initDBConnection();
    }

    ApplicationContext::~ApplicationContext()
    {}

    bool ApplicationContext::initDBConnection()
    {
        try {
            DbConnector = std::make_shared<DatabaseConnector>();
            if(DbConnector->isConnected())
                window.setDbLabelAsConnected();
        }
        catch(std::exception& e) {
            qDebug() << e.what();
            Logger::getInstance().log(e.what());
            QMessageBox::information(0, "BŁĄD",  "Nie można połączyć z bazą danych.");
            window.setDbLabelAsDisconected();
        }

    }
}

