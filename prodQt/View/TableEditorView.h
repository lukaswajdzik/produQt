#ifndef TABLEEDITOR_H
#define TABLEEDITOR_H

#include <QDialog>
#include "View/IWorkingWindow.h"

class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
class QTableView;
class MainWindowView;

class TableEditorView : public QWidget,
                        public IWorkingWindow
{
    Q_OBJECT
public:
    explicit TableEditorView(const QString tableName, MainWindowView* p_mainWindow = 0);
    QWidget* getView() override;

private slots:
    void submit();

private:
    MainWindowView *m_mainWindow;
    QPushButton *m_submitButton;
    QPushButton *m_revertButton;
    QDialogButtonBox *m_buttonBox;
    QSqlTableModel *m_model;
    QTableView *m_view;
};

#endif
