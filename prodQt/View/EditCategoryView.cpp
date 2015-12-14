#include "EditCategoryView.h"
#include "ui_EditCategoryView.h"

EditCategoryView::EditCategoryView(QWidget *parent) :
    QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::EditCategoryView)
{
    ui->setupUi(this);
}

EditCategoryView::~EditCategoryView()
{
    delete ui;
}
