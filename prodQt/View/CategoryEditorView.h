#ifndef CATEGORYEDITORVIEW_H
#define CATEGORYEDITORVIEW_H


#include <QDialog>
#include "View/IWorkingWindow.h"

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

class CategoryEditorView : public QWidget,
                           public IWorkingWindow
{
    Q_OBJECT
public:
    explicit CategoryEditorView(const QString tableName, MainWindowView* p_mainWindow = 0);
    QWidget* getView() override;

    void setupProductsLayout();
private slots:
    void revert();
    void submit();
    void removeRow();
    void setupModel(const QString tableName);
    void setupProductsPushbuttons();
    void setupCategoryPushbuttons(QLayout* p_layout);

    void showCategoryFields();
    void closeEditMode();

    void loadAddingPannel();
    void loadEditingPannel();
    void loadRemovingPannel();
    void cleanUp();
private:
    MainWindowView *m_mainWindow;

    QWidget *m_mainWidget;
    QVBoxLayout *m_mainLayout;

    QWidget *m_fixButtonWidget;
    QVBoxLayout *m_fixButtonLayout;

    QWidget *m_dynamicButtonWidget;
    QVBoxLayout *m_dynamicButtoLayout;

    QPushButton *m_addCategoryButton;
    QPushButton *m_EditCategoryButton;
    QPushButton *m_removeCategoryButton;
    QDialogButtonBox *m_buttonBox;

    QPushButton *m_refreshButton;
    QPushButton *m_newCategory;
    QHeaderView *m_horizHeader;
    QSqlRelationalTableModel *m_model;
    QItemSelectionModel *m_selmodel;
    QWidget *m_productsPannel;
    QVBoxLayout *m_categoryLayout;
    QVBoxLayout *m_productsLayout;


    QLineEdit* categoryName;
    QComboBox* parentCategory;
    QPushButton* close;

    void clearLayout(QLayout *layout);


};

#endif // CATEGORYEDITORVIEW_H
