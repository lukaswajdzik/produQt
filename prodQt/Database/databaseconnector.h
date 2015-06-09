#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include "ioperativedatabaseconnector.h"

namespace Database
{
    class DatabaseConnector : public IDatabaseConnector
    {
    public:
        virtual bool VerifyUser(std::string login, std::string password);
    };
}

#endif
