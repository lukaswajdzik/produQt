#include <QtWidgets>
#include <QtSql>

#include "TableEditorView.h"
#include "View/MainWindowView.h"

TableEditorView::TableEditorView(const QString tableName, MainWindowView* p_mainWindow)
    : QWidget(p_mainWindow),
      m_mainWindow(p_mainWindow)
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(tableName);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();

    m_model->setHeaderData(1, Qt::Horizontal, tr("Nazwa"));
    m_model->setHeaderData(2, Qt::Horizontal, tr("Cena [PLN]"));
    m_model->setHeaderData(3, Qt::Horizontal, tr("Kategoria"));
    m_model->insertRow(m_model->rowCount());

    m_view = new QTableView;
    m_view->setModel(m_model);
//    view->resizeColumnsToContents();
    m_view->setColumnHidden(0, true);

    m_submitButton = new QPushButton(tr("Dodaj"));
    m_submitButton->setDefault(true);
    m_revertButton = new QPushButton(tr("Cofnij"));

    m_buttonBox = new QDialogButtonBox(Qt::Vertical);
    m_buttonBox->addButton(m_submitButton, QDialogButtonBox::ActionRole);
    m_buttonBox->addButton(m_revertButton, QDialogButtonBox::ActionRole);

    connect(m_submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(m_revertButton, SIGNAL(clicked()), m_model, SLOT(revertAll()));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);
    mainLayout->addWidget(m_buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Tabela Produktów"));
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
    } else {
        m_model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1")
                             .arg(m_model->lastError().text()));
    }
    m_model->insertRow(m_model->rowCount());
}
