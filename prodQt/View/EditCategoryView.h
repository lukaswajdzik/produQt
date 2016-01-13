#ifndef EDITCATEGORYVIEW_H
#define EDITCATEGORYVIEW_H

#include <QDialog>
#include <memory>
#include "Utils/Subject.h"

class QSqlTableModel;

namespace Ui {
class EditCategoryView;
}

namespace Application{
    class ApplicationContext;
}

class EditCategoryView : public QDialog,
                         public Utils::Subject
{
    Q_OBJECT

public:
    explicit EditCategoryView(std::shared_ptr<Application::ApplicationContext>, QWidget *parent = 0);
    ~EditCategoryView();

private:
    Ui::EditCategoryView *ui;
    QSqlTableModel* m_model;

    void setupModel();
};

#endif // EDITCATEGORYVIEW_H
