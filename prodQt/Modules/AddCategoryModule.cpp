#include "AddCategoryModule.h"
#include "Dao/CategoryDao.h"
#include "Utils/logger.h"
#include <QSqlTableModel>
#include <QDebug>
#include "Application/UserAccessType.h"
#include "Utils/constants.h"

namespace Module{

    AddCategoryModule::AddCategoryModule(std::shared_ptr<Application::ApplicationContext> p_appContext) :
        Module(p_appContext),
        m_appContext(std::move(p_appContext))
    {
        m_categoryDao = std::make_shared<Dao::CategoryDao>(m_appContext->getConnection());
    }

    AddCategoryModule::~AddCategoryModule()
    {
    }

    bool AddCategoryModule::addNewCategory(QString p_name, QString p_base)
    {
        auto result = false;
        try{
            result = m_categoryDao->addCategory(p_name.simplified(), p_base.simplified());
        }
        catch(std::exception* ex){
            handeException(ex);
        }
        return result;

    }

    bool AddCategoryModule::isCategoryNameValid(QString p_name, QString p_parent)
    {
        auto result = false;
        try{
            result = m_categoryDao->isCategoryValid(p_name.simplified(), p_parent);
        }
        catch(std::exception* ex){
            handeException(ex);
        }
        return result;
    }

    bool AddCategoryModule::isCategoryParentValid(QString p_name)
    {
        auto result = false;
        try{
            result = m_categoryDao->getCategoryParent(p_name) == Utils::Constants::GetValidCategoryParentName();
        }
        catch(std::exception* ex){
            handeException(ex);
        }
        return result;
    }

    void AddCategoryModule::handeException(std::exception* ex)
    {
        Utils::Logger::getInstance().log(ex->what());
        qDebug() << ex->what();
        delete ex;
    }


}

