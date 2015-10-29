#include <QtWidgets>
#include <cmath>
#include "NumericKeyboard.h"
#include "Utils/button.h"
#include <QGridLayout>

NumericKeyboard::NumericKeyboard(QWidget *parent, QLineEdit *p_display) :
    QWidget(parent),
    m_display(p_display)
{
    for (int i = 0; i < NumDigitButtons; ++i) {
        m_digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Button *backspaceButton = createButton(tr("Cofnij"), SLOT(backspaceClicked()));
    Button *clearAllButton = createButton(tr("Usuń"), SLOT(clearAll()));
    m_layoutWidget = new QWidget(this);
    m_layoutWidget->setFixedSize(220,250);
    QGridLayout *mainLayout = new QGridLayout(m_layoutWidget);

    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(m_digitButtons[i], row, column, 1, 1);
    }

    mainLayout->addWidget(m_digitButtons[0], 5, 1, 1, 1);
    mainLayout->addWidget(backspaceButton, 5, 2, 1, 1);
    mainLayout->addWidget(clearAllButton, 5, 3, 1, 1);

//    mainLayout->addWidget(pointButton, 5, 0, 1, 1);

    m_clearDisplay = "";
}

void NumericKeyboard::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue = clickedButton->text().toInt();
//    if (m_display->text() == "0" && digitValue == 0.0)
//        return;

    m_display->setText(m_display->text() + QString::number(digitValue));
}

void NumericKeyboard::pointClicked()
{
    if (!m_display->text().contains("."))
        m_display->setText(m_display->text() + tr("."));
}

void NumericKeyboard::backspaceClicked()
{
    QString text = m_display->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = m_clearDisplay;
    }
    m_display->setText(text);
}

void NumericKeyboard::clearAll()
{
    m_display->setText(m_clearDisplay);
}

Button *NumericKeyboard::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

NumericKeyboard::~NumericKeyboard()
{

}

QWidget *NumericKeyboard::getView()
{
    return m_layoutWidget;
}

