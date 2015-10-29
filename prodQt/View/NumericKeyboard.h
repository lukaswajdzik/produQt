#ifndef NUMERICKEYBOARD_H
#define NUMERICKEYBOARD_H

#include <QWidget>
#include <View/IWorkingWindow.h>

class QLineEdit;
class QString;
class Button;

class NumericKeyboard : public QWidget,
                        public IWorkingWindow
{
    Q_OBJECT
public:
    explicit NumericKeyboard(QWidget *parent, QLineEdit*);
    ~NumericKeyboard();
    QWidget* getView() override;

private slots:
    void digitClicked();
    void pointClicked();
    void backspaceClicked();
    void clearAll();

private:
    Button *createButton(const QString &text, const char *member);
    QLineEdit *m_display;
    QString m_clearDisplay;

    enum { NumDigitButtons = 10 };
    Button *m_digitButtons[NumDigitButtons];
    QWidget *m_layoutWidget;

public slots:
};

#endif // NUMERICKEYBOARD_H
