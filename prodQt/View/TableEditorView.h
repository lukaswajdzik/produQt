#ifndef TABLEEDITOR_H
#define TABLEEDITOR_H

#include <QDialog>
#include "View/IWorkingWindow.h"

class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
class QTableView;
class MainWindowView;
class QHBoxLayout;
class QItemSelectionModel;

class TableEditorView : public QWidget,
                        public IWorkingWindow
{
    Q_OBJECT
public:
    explicit TableEditorView(const QString tableName, MainWindowView* p_mainWindow = 0);
    QWidget* getView() override;

private slots:
    void submit();
    void removeRow();
    void sutupModel(const QString tableName);
    void setupPushbuttons(QHBoxLayout* p_layout);

private:
    MainWindowView *m_mainWindow;
    QPushButton *m_submitButton;
    QPushButton *m_revertButton;
    QPushButton *m_removeButton;
    QDialogButtonBox *m_buttonBox;
    QSqlTableModel *m_model;
    QTableView *m_view;
    QItemSelectionModel *m_selmodel;
};

#endif
