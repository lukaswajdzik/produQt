#include "EditCategoryView.h"
#include "ui_EditCategoryView.h"
#include <QSqlTableModel>
#include "Utils/constants.h"

EditCategoryView::EditCategoryView(std::shared_ptr<Application::ApplicationContext> p_appContext, QWidget *parent) :
    QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::EditCategoryView)
{
    ui->setupUi(this);
    setupModel();
    ui->categoryComboBox->setModel(m_model);
    auto showColumn = m_model->fieldIndex(Utils::Constants::GetCategoryColumnName());
    ui->categoryComboBox->setModelColumn(showColumn);
    connect(ui->categoryComboBox, SIGNAL(currentIndexChanged(QString)), ui->newCategorlineEdit, SLOT(setText(QString)));
    connect(ui->newCategorlineEdit, SIGNAL(textChanged(QString)), ui->newCategorlineEdit, SLOT(selectAll()));
}

EditCategoryView::~EditCategoryView()
{
    delete ui;
}

void EditCategoryView::setupModel()
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(Utils::Constants::GetCategoryTableDbName());
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->setFilter(Utils::Constants::GetDefaultCategoryExtractionFilter());
    m_model->select();
}
