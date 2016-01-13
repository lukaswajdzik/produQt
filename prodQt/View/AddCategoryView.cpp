#include "AddCategoryView.h"
#include "ui_AddCategoryView.h"
#include "Utils/constants.h"
#include <QSqlTableModel>
#include "Modules/AddCategoryModule.h"

AddCategoryView::AddCategoryView(std::shared_ptr<Application::ApplicationContext> p_appContext, QWidget *parent) :
    QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::AddCategoryView),
    m_module(new Module::AddCategoryModule(p_appContext))
{
    ui->setupUi(this);
    setupModel();
    ui->categoryComboBox->setModel(m_model);
    auto showColumn = m_model->fieldIndex(Utils::Constants::GetCategoryColumnName());
    ui->categoryComboBox->setModelColumn(showColumn);

    connect(ui->okButton, SIGNAL(clicked()),this, SLOT(addNewCategory()));
    connect(ui->newCategoryLineEdit, SIGNAL(selectionChanged()),this, SLOT(setInfoText()));
    connect(ui->categoryComboBox, SIGNAL(activated(int)),this, SLOT(setInfoText()));
}

AddCategoryView::~AddCategoryView()
{
    delete ui;
}

void AddCategoryView::setupModel()
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(Utils::Constants::GetCategoryTableDbName());
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->sort(m_model->fieldIndex(Utils::Constants::GetCategoryColumnName()), Qt::AscendingOrder);
    m_model->select();
}

void AddCategoryView::addNewCategory()
{
    auto newCategoryName = ui->newCategoryLineEdit->text();
    auto baseCategory = ui->categoryComboBox->currentText();

    if(not m_module->isCategoryNameValid(newCategoryName, baseCategory))
    {
        setInfoText("Kategoria już istnieje!", "red");
        return;
    }
    else if(not m_module->isCategoryParentValid(baseCategory))
    {
        setInfoText("Kategoria nadrzędna niedozwolona!", "red");
        return;
    }
    m_module->addNewCategory(newCategoryName, baseCategory);
    setInfoText("Dodano nową kategorię!", "green");
    notify();
}

void AddCategoryView::setInfoText(QString p_text, QString p_color)
{
    QString base = tr("<font color='%1'>%2</font>");
    ui->infoLabel->setText(base.arg(p_color, p_text));
}
