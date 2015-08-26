#ifndef OPERATIVEDATABASECONNECTOR_H
#define OPERATIVEDATABASECONNECTOR_H

#include "Database/ioperaticedatabaseconnector.h"

namespace Database{

    class OperativeDatabaseConnector : public IOperativeDatabaseConnector
    {
    public:
        virtual bool VerifyUser(QString login, QString password) override;
        virtual QString SelectPasswordByUserName(QString userName) override;
        void addUserToDatabase();
        OperativeDatabaseConnector();
        ~OperativeDatabaseConnector();
    };
}

#endif // OPERATIVEDATABASECONNECTOR_H
