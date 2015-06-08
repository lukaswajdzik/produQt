#include "databaseconnector.h"
#include "ioperativedatabaseconnector.h"

namespace Database
{
    IDatabaseConnector::IDatabaseConnector()
    {

    }

    IDatabaseConnector::~IDatabaseConnector()
    {
        Dispose();
    }

    void IDatabaseConnector::Connect()
    {
        //TODO: database connection in accordance with configuration file.
    }

    void IDatabaseConnector::Dispose()
    {
        //TODO: safe database disconnection.
    }

    bool VerifyUser(std::string login, std::string password)
    {
        return login != "" && password != "";
        //TODO: first database method.
    }
}
