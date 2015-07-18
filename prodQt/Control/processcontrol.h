#ifndef PROCESSCONTROL_H
#define PROCESSCONTROL_H

#include "Visuals/mainwindow.h"
#include "Database/databaseconnector.h"

using DatabaseConnector = Database::DatabaseConnector;

namespace Control
{

    class ProcessControl
    {

    public:
        ProcessControl();
        ~ProcessControl();
        void initOperations();

    private:
        bool initDBConnection();
        MainWindow window;
        std::shared_ptr<DatabaseConnector> DbConnection;

    };

}
#endif // PROCESSCONTROL_H
