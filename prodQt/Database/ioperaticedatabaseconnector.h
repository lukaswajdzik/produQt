#ifndef IOPERATICEDATABASECONNECTOR
#define IOPERATICEDATABASECONNECTOR

#include <QString>

namespace Database {
    class IOperativeDatabaseConnector {
    public:
        bool VerifyUser(QString login, QString password);
        QString SelectPasswordByUserName(QString userName);
    };
}

#endif // IOPERATICEDATABASECONNECTOR

