#include <QtWidgets>
#include <QtSql>

#include "TableEditorView.h"

TableEditorView::TableEditorView(const QString &tableName, QWidget *parent)
    : QWidget(parent)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(1, Qt::Horizontal, tr("Nazwa"));
    model->setHeaderData(2, Qt::Horizontal, tr("Cena [PLN]"));
    model->setHeaderData(3, Qt::Horizontal, tr("Kategoria"));
    model->insertRow(model->rowCount());

    m_view = new QTableView;
    m_view->setModel(model);
//    view->resizeColumnsToContents();
    m_view->setColumnHidden(0, true);

    m_submitButton = new QPushButton(tr("Dodaj"));
    m_submitButton->setDefault(true);
    m_revertButton = new QPushButton(tr("Cofnij"));

    m_buttonBox = new QDialogButtonBox(Qt::Vertical);
    m_buttonBox->addButton(m_submitButton, QDialogButtonBox::ActionRole);
    m_buttonBox->addButton(m_revertButton, QDialogButtonBox::ActionRole);

    connect(m_submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(m_revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));

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
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
    model->insertRow(model->rowCount());
}
