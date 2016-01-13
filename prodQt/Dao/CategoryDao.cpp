#include "CategoryDao.h"
#include "Database/databasequeryprovider.h"
#include "Utils/blowfishprovider.h"
#include "Dao/Exceptions/DbQueryCouldNotBeExecuted.h"
#include <QSqlQuery>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>

namespace Dao {

    CategoryDao::CategoryDao(std::shared_ptr<QSqlQuery> p_connector) :
        m_connector(std::move(p_connector))
    {
    }

    CategoryDao::~CategoryDao()
    {
    }

    bool CategoryDao::addCategory(QString category, QString base) {
        m_connector->prepare(Database::DatabaseQueryProvider::addNewCategory());
        m_connector->bindValue(0, category);
        m_connector->bindValue(1, base);
        if(base != "-")
            m_connector->bindValue(2, category + " | " + base);
        else
            m_connector->bindValue(2, category);

        if(not m_connector->exec())
            throw new DbQueryCouldNotBeExecuted(m_connector->lastError());

        return true;
    }

    void CategoryDao::copyUserData(UserDaoRecord & userData)
    {
        userData.userId = m_connector->value(0).toInt();
        userData.name = m_connector->value(1).toString();
        userData.role = m_connector->value(2).toInt();
    }

    bool CategoryDao::isCategoryValid(QString p_category, QString p_parent)
    {
        m_connector->prepare(Database::DatabaseQueryProvider::existCategory());
        m_connector->bindValue(0, p_category);
        m_connector->bindValue(1, p_parent);
        if(not m_connector->exec())
            throw new DbQueryCouldNotBeExecuted(m_connector->lastError());

        m_connector->next();
        return not m_connector->value(0).toBool();
    }

    QString CategoryDao::getCategoryParent(QString p_name)
    {
        m_connector->prepare(Database::DatabaseQueryProvider::getCategoryParent());
        m_connector->bindValue(0, p_name);
        if(not m_connector->exec())
            throw new DbQueryCouldNotBeExecuted(m_connector->lastError());

        m_connector->next();
        return m_connector->value(0).toString();
    }

    QString CategoryDao::getUserDatabaseName()
    {
        return Database::DatabaseQueryProvider::getUserDatabaseName();
    }

    QString CategoryDao::selectPasswordByUserName(QString userName) {
        m_connector->prepare(Database::DatabaseQueryProvider::getUserPassword() );
        m_connector->bindValue(0, userName);
        if(not m_connector->exec())
            throw new DbQueryCouldNotBeExecuted(m_connector->lastError());

        m_connector->next();
        return m_connector->value(0).toString();
    }

}

