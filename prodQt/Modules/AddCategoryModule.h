#ifndef ADDCATEGORYMODULE_H
#define ADDCATEGORYMODULE_H
#include <QString>
#include "Modules/Module.h"


class QSqlTableModel;
class QWidget;

namespace Application {
    class ApplicationContext;
}
namespace Dao{
    class CategoryDao;
}

namespace Module{

    class AddCategoryModule : public Module
    {
    public:
        AddCategoryModule(std::shared_ptr<Application::ApplicationContext>);
        ~AddCategoryModule();

        bool addNewCategory(QString, QString);
        bool isCategoryNameValid(QString, QString);
        bool isCategoryParentValid(QString);

    private:
        std::shared_ptr<Application::ApplicationContext> m_appContext;
        std::shared_ptr<Dao::CategoryDao> m_categoryDao;
        void handeException(std::exception*);
    };
}


#endif // ADDCATEGORYMODULE_H
