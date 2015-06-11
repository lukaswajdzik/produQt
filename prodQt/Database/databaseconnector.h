#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QString>

namespace Database
{
    class DatabaseConnector
    {
    public:
        DatabaseConnector();
        ~DatabaseConnector();
        int GetState();
        bool VerifyUser(QString login, QString password);
    private:
        void Connect();
        void Dispose();
    };
}

#endif
