#include "AddCategoryView.h"
#include "ui_AddCategoryView.h"

AddCategoryView::AddCategoryView(QWidget *parent) :
    QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::AddCategoryView)
{
    ui->setupUi(this);
}

AddCategoryView::~AddCategoryView()
{
    delete ui;
}
