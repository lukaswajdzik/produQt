#include "MainWindowView.h"
#include "LoginView.h"
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


MainWindowView::MainWindowView(std::shared_ptr<Application::ApplicationContext> p_appContext, QWidget *p_parent) :
    QMainWindow(p_parent)
{
    setupUI(this);
    QWidget::setFixedSize(1100, 750);
    m_controller = std::make_shared<MainWindowController>(std::move(p_appContext));
    showLoginPage();
}

MainWindowView::~MainWindowView()
{
    qDebug() << "Program terminate!";
}

void MainWindowView::setupExitButton()
{
    m_pushbuttonClose->setObjectName(QStringLiteral("pushbuttonClose"));
    m_pushbuttonClose->setText("ZAMKNIJ");
    m_pushbuttonClose->setGeometry(QRect(970, 0, 130, 30));
}

void MainWindowView::setupInfoLabel()
{
    m_labelApplicationInfo->setObjectName(QStringLiteral("labelDbInfo"));
    m_labelApplicationInfo->setGeometry(QRect(20, 730, 500, 17));
    m_labelApplicationInfo->setText("Witaj.");
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
    setupWidget();
    setupLine();
}

void MainWindowView::createNewObjects(QMainWindow *MainWindow)
{
    m_centralWidget = new QWidget(MainWindow);
    m_layout = new QGridLayout(m_centralWidget);
    m_pushbuttonClose = new QPushButton(m_centralWidget);
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
    setupAnimationEffectsForWindow();
    QMetaObject::connectSlotsByName(MainWindow);
}

void MainWindowView::setUserInfoText(QString p_text, QString p_color)
{
    QString base = tr("<font color='%1'>%2</font>");
    m_labelApplicationInfo->setText(base.arg(p_color, p_text));
    m_labelApplicationInfo->setGraphicsEffect(m_opacity);
//    m_animationForInfoText->start();
}

void MainWindowView::on_pushbuttonClose_clicked()
{
    close();
}

void MainWindowView::setupAnimationEffectsForWindow()
{
    m_opacity = new QGraphicsOpacityEffect(this);
    m_animationForWindow = new QPropertyAnimation( m_opacity, "opacity", this );
    m_animationForWindow->setDuration( 1000 );
    m_animationForWindow->setStartValue( 0.1 );
    m_animationForWindow->setEndValue( 1.0 );
}

void MainWindowView::setAnimationForInfoText()
{
    m_animationForInfoText = new QPropertyAnimation( m_opacity, "opacity", this );
    m_animationForInfoText->setDuration( 2000 );
    m_animationForInfoText->setStartValue( 1.0 );
    m_animationForInfoText->setEndValue( 0.0 );
}

void MainWindowView::showLoginPage()
{
    m_workingWindow = m_controller->getLoginWindow(this);
    m_controller->getView(*m_workingWindow)->setGraphicsEffect(m_opacity);
    m_animationForWindow->start();
    m_layout->addWidget(m_controller->getView(*m_workingWindow));
}
