#ifndef ADDCATEGORYVIEW_H
#define ADDCATEGORYVIEW_H

#include <QDialog>
#include <memory>
#include "Utils/Subject.h"

namespace Ui {
    class AddCategoryView;
}

namespace Application{
    class ApplicationContext;
}
namespace Module{
    class AddCategoryModule;
}

class QSqlTableModel;

class AddCategoryView : public QDialog,
                        public Utils::Subject
{
    Q_OBJECT

public:
    AddCategoryView(std::shared_ptr<Application::ApplicationContext>, QWidget *parent = 0);
    ~AddCategoryView();

private slots:
    void addNewCategory();
    void setInfoText(QString p_text = "", QString p_color = "black");

private:
    Ui::AddCategoryView *ui;
    QSqlTableModel* m_model;
    std::unique_ptr<Module::AddCategoryModule> m_module;

    void setupModel();
};

#endif // ADDCATEGORYVIEW_H
