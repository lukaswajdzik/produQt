#include "MainWindowView.h"
#include "LoginView.h"
#include "WorkingTabsView.h"
#include "Controllers/MainWindowController.h"
#include <QLabel>
#include <QPushButton>
#include <QLine>
#include <QDebug>
#include <QFrame>
#include <Application/ApplicationContext.h>
#include <QGridLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "View/WorkingTabsView.h"


MainWindowView::MainWindowView(std::shared_ptr<Application::ApplicationContext> p_appContext, QWidget *p_parent) :
    QMainWindow(p_parent),
    m_appContext(std::move(p_appContext)),
    m_workingWindow(nullptr),
    m_opacityForWindow(nullptr),
    m_animationForWindow(nullptr)
{
    setupUI(this);
    QWidget::setFixedSize(1100, 750);
    m_appContext->getSession().attach(this);
    m_controller = std::make_shared<MainWindowController>(m_appContext);
    loadWindow(m_controller->getLoginWindow(this));
}

MainWindowView::~MainWindowView()
{
    m_appContext->getSession().detach(this);
    delete m_workingWindow;
    qDebug() << "Program terminate!";
}

void MainWindowView::setupLogoutButton()
{
    m_pushbuttonLogout->setObjectName(QStringLiteral("pushbuttonLogout"));
    m_pushbuttonLogout->setText("WYLOGUJ");
    m_pushbuttonLogout->setGeometry(QRect(900, 0, 100, 50));
    m_pushbuttonLogout->setVisible(false);
}

void MainWindowView::setupExitButton()
{
    m_pushbuttonClose->setObjectName(QStringLiteral("pushbuttonClose"));
    m_pushbuttonClose->setText("ZAMKNIJ");
    m_pushbuttonClose->setGeometry(QRect(1000, 0, 100, 50));
}


void MainWindowView::setupInfoLabel()
{
    m_labelApplicationInfo->setObjectName(QStringLiteral("labelDbInfo"));
    m_labelApplicationInfo->setGeometry(QRect(20, 730, 500, 17));
    m_labelApplicationInfo->setText(".");
    QFont font;
    font.setBold(true);
    m_labelApplicationInfo->setFont(font);
}

void MainWindowView::setupMainWindow(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle("ProduQt");
    MainWindow->setCentralWidget(m_centralWidget);
}

void MainWindowView::setupWidget()
{
    m_centralWidget->setObjectName(QStringLiteral("centralWidget"));
//    m_centralWidget->setStyleSheet("background-color:black;"); //TODO: style option?
}


void MainWindowView::setupLine()
{
    m_line->setObjectName(QStringLiteral("line"));
    m_line->setGeometry(QRect(1, 723, 1098, 10));
    m_line->setFrameShape(QFrame::HLine);
    m_line->setFrameShadow(QFrame::Sunken);
}

void MainWindowView::setupElements(QMainWindow *MainWindow)
{
    setupMainWindow(MainWindow);
    setupInfoLabel();
    setupExitButton();
    setupLogoutButton();
    setupWidget();
    setupLine();
}

void MainWindowView::createNewObjects(QMainWindow *MainWindow)
{
    m_centralWidget = new QWidget(MainWindow);
    m_layout = new QGridLayout(m_centralWidget);
    m_pushbuttonClose = new QPushButton(m_centralWidget);
    m_pushbuttonLogout = new QPushButton(m_centralWidget);
    m_labelApplicationInfo = new QLabel(m_centralWidget);
    m_line = new QFrame(m_centralWidget);
}

void MainWindowView::setupUI(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));

    createNewObjects(MainWindow);

    setupElements(MainWindow);
    m_centralWidget->setLayout(m_layout);
    setAnimationForInfoText();
    setupAnimationEffectsForWindow();
    QMetaObject::connectSlotsByName(MainWindow);
}

void MainWindowView::setUserInfoText(QString p_text, QString p_color)
{
    QString base = tr("<font color='%1'>%2</font>");
    m_labelApplicationInfo->setText(base.arg(p_color, p_text));
    m_animationForInfoText->start();
}

void MainWindowView::setupAnimationEffectsForWindow()
{
    m_opacityForWindow = new QGraphicsOpacityEffect(this);
    m_animationForWindow = new QPropertyAnimation( m_opacityForWindow, "opacity", this );
    m_animationForWindow->setDuration( 1000 );
    m_animationForWindow->setStartValue( 0.1 );
    m_animationForWindow->setEndValue( 1.0 );
}

void MainWindowView::setAnimationForInfoText()
{
    m_opacityForText = new QGraphicsOpacityEffect(this);
    m_animationForInfoText = new QPropertyAnimation( m_opacityForText, "opacity", this );
    m_labelApplicationInfo->setGraphicsEffect(m_opacityForText);
    m_animationForInfoText->setDuration( 3000 );
    m_animationForInfoText->setStartValue( 1.0 );
    m_animationForInfoText->setEndValue( 0.0 );
}

void MainWindowView::loadWindow(IWorkingWindow* p_window)
{
    p_window->getView()->setGraphicsEffect(m_opacityForWindow);
    cleanupLayout();
    m_workingWindow = p_window;
    showWorkingWindow(p_window);
}

void MainWindowView::cleanupLayout()
{
    clearLayout(m_layout);
    clearWorkingWindow();
}

void MainWindowView::showWorkingWindow(IWorkingWindow* p_window)
{
    m_animationForWindow->start();
    m_layout->addWidget(m_controller->getView(*p_window));
}

void MainWindowView::clearWorkingWindow()
{
    if(m_workingWindow != nullptr)
        delete m_workingWindow;
    m_workingWindow = nullptr;
}

void MainWindowView::clearLayout(QLayout *layout)
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

void MainWindowView::update(Utils::Subject *p)
{
    if (m_appContext->getSession().isLogged())
    {
        loadWindow(m_controller->getWorkingView(this));
        m_pushbuttonLogout->setVisible(true);
    }
    else
    {
        loadWindow(m_controller->getLoginWindow(this));
        m_pushbuttonLogout->setVisible(false);
    }
}

void MainWindowView::on_pushbuttonClose_clicked()
{
    close();
}

void MainWindowView::on_pushbuttonLogout_clicked()
{
    m_controller->logout();
}
