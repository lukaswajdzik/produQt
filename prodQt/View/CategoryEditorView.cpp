#include "CategoryEditorView.h"

#include <QtWidgets>
#include <QtSql>

#include "View/MainWindowView.h"
#include <QSqlRelationalTableModel>
#include <QComboBox>

CategoryEditorView::CategoryEditorView(const QString tableName, MainWindowView* p_mainWindow)
    : QWidget(p_mainWindow),
      m_mainWindow(p_mainWindow)
{
    m_mainWidget = new QWidget(this);
    m_mainLayout = new QVBoxLayout(m_mainWidget);
    m_mainWidget->setLayout(m_mainLayout);
    m_mainWidget->setFixedWidth(220);

    m_fixButtonWidget = new QWidget(m_mainWidget);
    m_fixButtonWidget->setFixedHeight(200);
    m_fixButtonLayout = new QVBoxLayout(m_fixButtonWidget);
    m_fixButtonLayout->setAlignment(Qt::AlignCenter);
    m_fixButtonWidget->setLayout(m_fixButtonLayout);
//    m_fixButtonWidget->setStyleSheet("background-color:green;");

    m_dynamicButtonWidget = new QWidget(m_mainWidget);
    m_dynamicButtoLayout = new QVBoxLayout(m_dynamicButtonWidget);
    m_dynamicButtonWidget->setLayout(m_dynamicButtoLayout);

    m_addCategoryButton = new QPushButton(tr("Dodaj nową kategorię"), m_fixButtonWidget);
    m_EditCategoryButton = new QPushButton(tr("Edytuj kategorię"), m_fixButtonWidget);
    m_removeCategoryButton = new QPushButton(tr("Usuń kategorię"), m_fixButtonWidget);
    m_buttonBox = new QDialogButtonBox(Qt::Vertical, m_fixButtonWidget);

    m_buttonBox->centerButtons();
    m_buttonBox->addButton(m_addCategoryButton, QDialogButtonBox::AcceptRole);
    m_buttonBox->addButton(m_EditCategoryButton, QDialogButtonBox::AcceptRole);
    m_buttonBox->addButton(m_removeCategoryButton, QDialogButtonBox::AcceptRole);

    connect(m_addCategoryButton, SIGNAL(clicked()), this, SLOT(loadAddingPannel()));
    connect(m_removeCategoryButton, SIGNAL(clicked()), this, SLOT(loadRemovingPannel()));
    connect(m_EditCategoryButton, SIGNAL(clicked()), this, SLOT(loadEditingPannel()));

    m_fixButtonLayout->addWidget(m_buttonBox);
    m_mainLayout->addWidget(m_fixButtonWidget);
    m_mainLayout->addWidget(m_dynamicButtonWidget);



//    m_mainWidget->setModel(m_model);
//    m_mainWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    m_mainWidget->setItemDelegate(new QSqlRelationalDelegate(m_mainWidget));
//    auto idIndex = m_model->fieldIndex("product_id");
//    m_mainWidget->setColumnHidden(idIndex, true);
//    m_mainWidget->resizeColumnsToContents();

//    setupProductsPushbuttons();
//    setupCategoryPushbuttons(m_mainLayout);
//    setupProductsLayout();

//    setLayout(m_mainLayout);

//    m_selmodel = m_mainWidget->selectionModel();

//    m_horizHeader = m_mainWidget->horizontalHeader();
//    connect(m_horizHeader, SIGNAL(sectionClicked(int)), this, SLOT(sortColumn(int)));
}

void CategoryEditorView::loadAddingPannel()
{
    clearLayout(m_dynamicButtoLayout);

    auto newCategoryName = new QLineEdit(this);
    auto actualCategory = new QComboBox(this);
    auto buttonBox = new QDialogButtonBox(Qt::Horizontal, this);
    auto acceptButton = new QPushButton("Dodaj", this);
    auto rejectButton = new QPushButton("Anuluj", this);

    newCategoryName->setPlaceholderText("Wpisz nową nazwę");

    buttonBox->centerButtons();
    buttonBox->addButton(acceptButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(rejectButton, QDialogButtonBox::ActionRole);

    m_dynamicButtoLayout->addWidget(newCategoryName);
    m_dynamicButtoLayout->addWidget(actualCategory);
    m_dynamicButtoLayout->addWidget(buttonBox);
    m_dynamicButtoLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

//    connect(acceptButton, SIGNAL(clicked()), this, SLOT(addNewCategory()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(cleanUp()));
}

void CategoryEditorView::loadEditingPannel()
{
    clearLayout(m_dynamicButtoLayout);

    auto actualCategory = new QComboBox(this);
    auto editCategoryName = new QLineEdit(this);
    auto buttonBox = new QDialogButtonBox(Qt::Horizontal, this);
    auto acceptButton = new QPushButton("Zapisz zmianę", this);
    auto rejectButton = new QPushButton("Anuluj", this);

    editCategoryName->setPlaceholderText("Wybierz kategorię");

    buttonBox->centerButtons();
    buttonBox->addButton(acceptButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(rejectButton, QDialogButtonBox::ActionRole);

    m_dynamicButtoLayout->addWidget(actualCategory);
    m_dynamicButtoLayout->addWidget(editCategoryName);
    m_dynamicButtoLayout->addWidget(buttonBox);
    m_dynamicButtoLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

//    connect(acceptButton, SIGNAL(clicked()), this, SLOT(editSelectedCategory()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(cleanUp()));
}

void CategoryEditorView::loadRemovingPannel()
{
    clearLayout(m_dynamicButtoLayout);

    auto actualCategory = new QComboBox(this);
    auto buttonBox = new QDialogButtonBox(Qt::Horizontal, this);
    auto acceptButton = new QPushButton("Usuń", this);
    auto rejectButton = new QPushButton("Anuluj", this);

    buttonBox->centerButtons();
    buttonBox->addButton(acceptButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(rejectButton, QDialogButtonBox::ActionRole);

    m_dynamicButtoLayout->addWidget(actualCategory);
    m_dynamicButtoLayout->addWidget(buttonBox);
    m_dynamicButtoLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

//    connect(acceptButton, SIGNAL(clicked()), this, SLOT(editSelectedCategory()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(cleanUp()));
}

void CategoryEditorView::cleanUp()
{
    clearLayout(m_dynamicButtoLayout);
}

void CategoryEditorView::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void CategoryEditorView::setupProductsLayout()
{
    m_productsPannel = new QWidget(this);
    m_productsLayout = new QVBoxLayout(this);

    m_productsPannel->setLayout(m_productsLayout);
    m_productsLayout->addWidget(m_buttonBox);
    m_productsLayout->addWidget(m_mainWidget);
    m_mainLayout->addWidget(m_productsPannel);
}

void CategoryEditorView::setupProductsPushbuttons()
{


}

void CategoryEditorView::setupCategoryPushbuttons(QLayout *p_layout)
{
    m_newCategory = new QPushButton(tr("Dodaj nową kategorię"), this);
    m_categoryLayout = new QVBoxLayout(this);
    connect(m_newCategory, SIGNAL(clicked()), this, SLOT(showCategoryFields()));
    p_layout->addWidget(m_newCategory);

}

void CategoryEditorView::showCategoryFields()
{
    categoryName = new QLineEdit(this);
    parentCategory = new QComboBox(this);
    close = new QPushButton(tr("Anuluj"), this);

    categoryName->setMaximumWidth(230);
    parentCategory->setMaximumWidth(230);
    m_categoryLayout->addWidget(categoryName);
    m_categoryLayout->addWidget(parentCategory);
    m_categoryLayout->addWidget(close);
    connect(close, SIGNAL(clicked()), this, SLOT(closeEditMode()));

}

void CategoryEditorView::closeEditMode()
{
    m_categoryLayout->removeWidget(categoryName);
    m_categoryLayout->removeWidget(parentCategory);
    m_categoryLayout->removeWidget(close);
}

void CategoryEditorView::setupModel(const QString tableName)
{
    m_model = new QSqlRelationalTableModel(this);
    m_model->setTable(tableName);
    auto nameIndex = m_model->fieldIndex("name");
    auto typeIndex = m_model->fieldIndex("Category_Id");
    m_model->setRelation(typeIndex, QSqlRelation("categories", "id", "category"));
    m_model->setEditStrategy(QSqlTableModel::OnRowChange);
    m_model->setSort(nameIndex, Qt::AscendingOrder);
    m_model->select();

    m_model->setHeaderData(1, Qt::Horizontal, tr("Nazwa"));
    m_model->setHeaderData(2, Qt::Horizontal, tr("Cena [PLN]"));
    m_model->setHeaderData(3, Qt::Horizontal, tr("Kategoria"));

}
void CategoryEditorView::revert()
{
    m_model->revert();
    m_model->select();
}

QWidget *CategoryEditorView::getView()
{
    return m_mainWidget;
}

void CategoryEditorView::submit()
{
    QSqlRecord record;
    record.append(QSqlField("name", QVariant::String));
    record.append(QSqlField("price", QVariant::Double));
    record.append(QSqlField("Category_Id", QVariant::Int));
    record.setValue(0, " ");
    record.setValue(1, 0.0);
    record.setValue(2, 0);
    m_model->insertRecord(m_selmodel->currentIndex().row(), record);
    m_model->select();
}

void CategoryEditorView::removeRow()
{
    m_model->removeRows(m_selmodel->currentIndex().row(), 1);
    m_model->select();
}

