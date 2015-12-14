#include <QtWidgets>
#include <QtSql>

#include "TableEditorView.h"
#include "View/MainWindowView.h"
#include <QSqlRelationalTableModel>
#include <QComboBox>
#include "Controllers/TableEditorController.h"

TableEditorView::TableEditorView(const QString tableName,
                                 std::shared_ptr<Application::ApplicationContext> p_appContext,
                                 MainWindowView* p_mainWindow)
    : QWidget(p_mainWindow),
      m_mainWindow(p_mainWindow),
      m_controller(std::make_shared<TableEditorController>(p_appContext, p_mainWindow))
{
    setWindowTitle(tr("Tabela Produktów"));
    m_view = new QTableView(this);
    m_mainLayout = new QHBoxLayout(this);

    setupModel(tableName);

    m_view->setModel(m_model);
//    m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_view->setItemDelegate(new QSqlRelationalDelegate(m_view));
    auto idIndex = m_model->fieldIndex("product_id");
    m_view->setColumnHidden(idIndex, true);
    m_view->resizeColumnsToContents();

    setupProductsPushbuttons();

    setupProductsLayout();

    setLayout(m_mainLayout);

    m_selmodel = m_view->selectionModel();

    m_horizHeader = m_view->horizontalHeader();
    connect(m_horizHeader, SIGNAL(sectionClicked(int)), this, SLOT(sortColumn(int)));
}

void TableEditorView::setupProductsLayout()
{
    m_mainLayout->addWidget(m_buttonBox);
    m_mainLayout->addWidget(m_view);
}

void TableEditorView::sortColumn(int p_nb)
{
    changeColumnOrder(m_columnSoringOrder[p_nb]);
    m_model->sort(p_nb, m_columnSoringOrder[p_nb]);
}

void TableEditorView::changeColumnOrder(Qt::SortOrder& p_column)
{
    if(p_column == Qt::DescendingOrder)
    {
        p_column = Qt::AscendingOrder;
    }
    else if (p_column == Qt::AscendingOrder)
    {
        p_column = Qt::DescendingOrder;
    }
    else
        p_column = Qt::AscendingOrder;
}

void TableEditorView::setupProductsPushbuttons()
{
    m_addRecordItemButton = new QPushButton(tr("Dodaj nowy produkt"), this);
    m_removeButton = new QPushButton(tr("Usuń zaznaczony"), this);
    m_refreshButton = new QPushButton(tr("Odśwież"), this);
    m_saveButton = new QPushButton(tr("Zapisz"), this);
    m_addCategoryButton = new QPushButton(tr("Dodaj kategorię"), this);
    m_editCategoryButton = new QPushButton(tr("Edytuj kategorię"), this);

    m_buttonBox = new QDialogButtonBox(Qt::Vertical, this);
    m_buttonBox->centerButtons();
    m_buttonBox->addButton(m_addRecordItemButton, QDialogButtonBox::ApplyRole);
    m_buttonBox->addButton(m_saveButton, QDialogButtonBox::ApplyRole);
    m_buttonBox->addButton(m_refreshButton, QDialogButtonBox::ApplyRole);
    m_buttonBox->addButton(m_removeButton, QDialogButtonBox::ApplyRole);
    m_buttonBox->addButton(m_addCategoryButton, QDialogButtonBox::HelpRole);
    m_buttonBox->addButton(m_editCategoryButton, QDialogButtonBox::HelpRole);

    connect(m_addRecordItemButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(m_removeButton, SIGNAL(clicked()), this, SLOT(removeRow()));
    connect(m_refreshButton, SIGNAL(clicked()), m_model, SLOT(select()));
    connect(m_saveButton, SIGNAL(clicked()), m_model, SLOT(submitAll()));
    connect(m_addCategoryButton, SIGNAL(clicked()), this, SLOT(showCategoryAddingView()));
    connect(m_editCategoryButton, SIGNAL(clicked()), this, SLOT(showCategoryEditView()));
}

void TableEditorView::showCategoryAddingView()
{
    m_controller->showCategoryAddingView();
}

void TableEditorView::showCategoryEditView()
{
    m_controller->showCategoryEditingView();
}

void TableEditorView::showCategoryFields()
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

void TableEditorView::closeEditMode()
{
    m_categoryLayout->removeWidget(categoryName);
    m_categoryLayout->removeWidget(parentCategory);
    m_categoryLayout->removeWidget(close);
}

void TableEditorView::setupModel(const QString tableName)
{
    m_model = new QSqlRelationalTableModel(this);
    m_model->setTable(tableName);
    auto nameIndex = m_model->fieldIndex("name");
    auto typeIndex = m_model->fieldIndex("Category_Id");
    m_model->setRelation(typeIndex, QSqlRelation("categories", "id", "category"));
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->setSort(nameIndex, Qt::AscendingOrder);
    m_model->select();

    m_model->setHeaderData(1, Qt::Horizontal, tr("Nazwa"));
    m_model->setHeaderData(2, Qt::Horizontal, tr("Cena [PLN]"));
    m_model->setHeaderData(3, Qt::Horizontal, tr("Kategoria"));

}
void TableEditorView::revert()
{
    m_model->revert();
    m_model->select();
}

QWidget *TableEditorView::getView()
{
    return m_view;
}

void TableEditorView::submit()
{
    QSqlRecord record;
    record.append(QSqlField("name", QVariant::String));
    record.append(QSqlField("price", QVariant::Double));
    record.append(QSqlField("Category_Id", QVariant::Int));
    record.setValue(0, " ");
    record.setValue(1, 0.0);
    record.setValue(2, 0);
    m_model->insertRecord(m_selmodel->currentIndex().row(), record);
    applyChangesToDb();
}

void TableEditorView::applyChangesToDb()
{
    m_model->database().transaction();
    if (m_model->submitAll()) {
        m_model->database().commit();
    }
    m_model->select();
}

void TableEditorView::removeRow()
{
    m_model->removeRows(m_selmodel->currentIndex().row(), 1);
    applyChangesToDb();
}
