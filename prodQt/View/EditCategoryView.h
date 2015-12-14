#ifndef EDITCATEGORYVIEW_H
#define EDITCATEGORYVIEW_H

#include <QDialog>

namespace Ui {
class EditCategoryView;
}

class EditCategoryView : public QDialog
{
    Q_OBJECT

public:
    explicit EditCategoryView(QWidget *parent = 0);
    ~EditCategoryView();

private:
    Ui::EditCategoryView *ui;
};

#endif // EDITCATEGORYVIEW_H
