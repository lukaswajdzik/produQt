#ifndef OPERATIVEDATABASECONNECTOR_H
#define OPERATIVEDATABASECONNECTOR_H

#include "Database/ioperaticedatabaseconnector.h"
#include "User/usermodifier.h"

namespace Database{

    class OperativeDatabaseConnector : public IOperativeDatabaseConnector
    {
    public:
        virtual bool VerifyUser(QString login, QString password) override;
        virtual QString SelectPasswordByUserName(QString userName) override;
        void addUserToDatabase(User::UserData);
        OperativeDatabaseConnector();
        ~OperativeDatabaseConnector();
    };
}

#endif // OPERATIVEDATABASECONNECTOR_H
