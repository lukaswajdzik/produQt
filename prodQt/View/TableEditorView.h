#ifndef TABLEEDITOR_H
#define TABLEEDITOR_H

#include <QDialog>
#include "View/IWorkingWindow.h"
#include <memory>
#include <QSqlRelationalDelegate>
#include <QComboBox>
#include <QStringList>
#include "Utils/Observer.h"

class QDialogButtonBox;
class QPushButton;
class QSqlRelationalTableModel;
class QTableView;
class MainWindowView;
class QHBoxLayout;
class QItemSelectionModel;
class QSqlRecord;
class QComboBox;
class QHeaderView;
class QVBoxLayout;
class QLineEdit;
class TableEditorController;

namespace Application{
    class ApplicationContext;
}

class ProductsEditorView : public QWidget,
                        public IWorkingWindow,
                        public Utils::Observer
{
    Q_OBJECT
public:
    explicit ProductsEditorView(const QString tableName,
                             std::shared_ptr<Application::ApplicationContext> p_appContext,
                             MainWindowView* p_mainWindow = 0);
    QWidget* getView() override;

private slots:
    void revert();
    void submit();
    void removeRow();
    void setupModel(const QString tableName);
    void setupProductsPushbuttons();
    void sortColumn(int);

    void showCategoryFields();
    void closeEditMode();
    void showCategoryAddingView();
    void showCategoryEditView();

    void update(Utils::Subject*) override;
private:
    QString m_tableName;

    MainWindowView *m_mainWindow;
    std::shared_ptr<TableEditorController> m_controller;

    QPushButton *m_addRecordItemButton;
    QPushButton *m_saveButton;
    QPushButton *m_removeButton;
    QPushButton *m_refreshButton;
    QPushButton *m_newCategory;
    QPushButton *m_addCategoryButton;
    QPushButton *m_editCategoryButton;
    QHeaderView *m_horizHeader;
    QDialogButtonBox *m_buttonBox;
    QSqlRelationalTableModel *m_model;
    QTableView *m_view;
    QItemSelectionModel *m_selmodel;
    QVBoxLayout *m_categoryLayout;
    QHBoxLayout *m_mainLayout;
    Qt::SortOrder m_columnSoringOrder[];

    void setupProductsLayout();
    void setupTableView(const QString tableName);
    void connectModelSignals();
    void changeColumnOrder(Qt::SortOrder&);
    void applyChangesToDb();

    QLineEdit* categoryName;
    QComboBox* parentCategory;
    QPushButton* close;

};

#endif
