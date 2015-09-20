#ifndef USEROPERATIVEDB_H
#define USEROPERATIVEDB_H

#include "Database/ioperativedatabaseconnector.h"

namespace Database{

    class UserOperativeDb : public IOperativeDatabaseConnector
    {
    public:
        UserOperativeDb();
        virtual ~UserOperativeDb();

        bool VerifyUser(QString login, QString password) override;
        QString SelectPasswordByUserName(QString userName) override;
        void addUserToDatabase(Module::UserData) override;
    };
}

#endif // USEROPERATIVEDB_H
