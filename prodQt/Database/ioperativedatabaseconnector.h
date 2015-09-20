#ifndef IOPERATICEDATABASECONNECTOR
#define IOPERATICEDATABASECONNECTOR

#include <QString>
#include "Modules/UserAddingModule.h"

namespace Database {
    class IOperativeDatabaseConnector {
    public:
        virtual bool VerifyUser(QString login, QString password) = 0;
        virtual QString SelectPasswordByUserName(QString userName) = 0;
        virtual void addUserToDatabase(Module::UserData) = 0;
    };
}

#endif // IOPERATICEDATABASECONNECTOR

