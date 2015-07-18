#include "processcontrol.h"
#include <QDebug>
#include "Utils/logger.h"
#include <QMessageBox>

using Logger = Utils::Logger;

namespace Control
{
    ProcessControl::ProcessControl()
    {
        window.show();
        window.setDbLabelAsIsConnecting();
    }

    ProcessControl::~ProcessControl()
    {}

    void ProcessControl::initOperations()
    {
        initDBConnection();
    }

    bool ProcessControl::initDBConnection()
    {
        try {
            DbConnection = std::make_shared<DatabaseConnector>();
            if(DbConnection->isConnected())
                window.setDbLabelAsConnected();
        }
        catch(std::exception& e) {
            qDebug() << e.what();
            Logger::getInstance().log(e.what());
            QMessageBox::information(0, "BŁĄD",  "Nie można połączyć z bazą danych.");
        }

    }
}

