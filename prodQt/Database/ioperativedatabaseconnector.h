#ifndef IOPERATICEDATABASECONNECTOR
#define IOPERATICEDATABASECONNECTOR

#include <QString>
#include "User/usermodifier.h"

namespace Database {
    class IOperativeDatabaseConnector {
    public:
        virtual bool VerifyUser(QString login, QString password) = 0;
        virtual QString SelectPasswordByUserName(QString userName) = 0;
        virtual void addUserToDatabase(User::UserData) = 0;
    };
}

#endif // IOPERATICEDATABASECONNECTOR

