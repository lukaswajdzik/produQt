#ifndef ADDCATEGORYVIEW_H
#define ADDCATEGORYVIEW_H

#include <QDialog>

namespace Ui {
class AddCategoryView;
}

class AddCategoryView : public QDialog
{
    Q_OBJECT

public:
    AddCategoryView(QWidget *parent = 0);
    ~AddCategoryView();

private:
    Ui::AddCategoryView *ui;
};

#endif // ADDCATEGORYVIEW_H
