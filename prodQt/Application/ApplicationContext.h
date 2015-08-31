#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H

#include "Visuals/mainwindow.h"
#include "Database/databaseconnector.h"

using DatabaseConnector = Database::DatabaseConnector;

namespace Application
{

    class ApplicationContext
    {

    public:
        ApplicationContext(MainWindow&);
        ~ApplicationContext();

    private:
        bool initDBConnection();
        MainWindow& window;
        std::shared_ptr<DatabaseConnector> DbConnector;

    };

}
#endif // APPLICATIONCONTEXT_H
