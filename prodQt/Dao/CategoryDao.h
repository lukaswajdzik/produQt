#ifndef LOGINDAO_H
#define LOGINDAO_H
#include <memory>
#include <QString>
#include "Dao/UserDaoRecord.h"
class QSqlQuery;


namespace Dao {

    class CategoryDao
    {
    public:
        CategoryDao(std::shared_ptr<QSqlQuery>);
        ~CategoryDao();

        bool addCategory(QString, QString);
        bool isCategoryValid(QString, QString);
        QString getCategoryParent(QString);
        QString getUserDatabaseName();

    private:
        void copyUserData(UserDaoRecord&);
        std::shared_ptr<QSqlQuery> m_connector;
        QString selectPasswordByUserName(QString);
    };

}

#endif // LOGINDAO_H
