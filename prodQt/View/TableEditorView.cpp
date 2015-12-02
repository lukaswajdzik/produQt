#include <QtWidgets>
#include <QtSql>

#include "TableEditorView.h"
#include "View/MainWindowView.h"

//QItemSelectionModel
TableEditorView::TableEditorView(const QString tableName, MainWindowView* p_mainWindow)
    : QWidget(p_mainWindow),
      m_mainWindow(p_mainWindow)
{
    m_view = new QTableView;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    sutupModel(tableName);
    m_view->setModel(m_model);
    m_view->setEditTriggers(QAbstractItemView::DoubleClicked);
    m_view->setColumnHidden(0, true);

    setupPushbuttons(mainLayout);

    mainLayout->addWidget(m_view);

    setLayout(mainLayout);

    setWindowTitle(tr("Tabela Produktów"));

    m_selmodel = m_view->selectionModel();
}

void TableEditorView::setupPushbuttons(QHBoxLayout *p_layout)
{
    m_submitButton = new QPushButton(tr("Dodaj"));
    m_submitButton->setDefault(true);
    m_revertButton = new QPushButton(tr("Cofnij"));
    m_removeButton = new QPushButton(tr("Usuń"));

    m_buttonBox = new QDialogButtonBox(Qt::Vertical);
    m_buttonBox->addButton(m_submitButton, QDialogButtonBox::ActionRole);
    m_buttonBox->addButton(m_revertButton, QDialogButtonBox::ActionRole);
    m_buttonBox->addButton(m_removeButton, QDialogButtonBox::ActionRole);

    connect(m_submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(m_revertButton, SIGNAL(clicked()), m_model, SLOT(revertAll()));
    connect(m_removeButton, SIGNAL(clicked()), this, SLOT(removeRow()));

    p_layout->addWidget(m_buttonBox);
}

void TableEditorView::sutupModel(const QString tableName)
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(tableName);
    m_model->setEditStrategy(QSqlTableModel::OnRowChange);
    m_model->select();

    m_model->setHeaderData(1, Qt::Horizontal, tr("Nazwa"));
    m_model->setHeaderData(2, Qt::Horizontal, tr("Cena [PLN]"));
    m_model->setHeaderData(3, Qt::Horizontal, tr("Kategoria"));
    m_model->insertRow(m_model->rowCount());
}

QWidget *TableEditorView::getView()
{
    return m_view;
}

void TableEditorView::submit()
{
    m_model->database().transaction();
    if (m_model->submitAll()) {
        m_model->database().commit();
        m_model->insertRow(m_model->rowCount());
    } else {
        m_model->database().rollback();
        m_mainWindow->setUserInfoText("Błąd podczas dodawania, spróbuj ponownie", "red");
    }
}

void TableEditorView::removeRow()
{
    m_model->setEditStrategy(QSqlTableModel::OnRowChange);
    m_model->removeRows(m_selmodel->currentIndex().row(), 1);
    QString abc = QString("WARTOŚĆ : %1").arg(m_selmodel->currentIndex().row());
    m_mainWindow->setUserInfoText(abc);
    m_model->select();
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}
