#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include "toolform.h"
#include <QAbstractButton>
#include <QQueue>
#include <QStack>

namespace Ui {
class CalculatorWindow;
}

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorWindow(ToolForm*tool,QWidget *parent = nullptr);
    ~CalculatorWindow();

    //计算表达式
    QString calculate();
    //将中缀表达式转换成后缀表达式
    void midToPost();
    //运算符入栈
    void operatorPushStack(QString op);
    //计算后缀表达式
    QString calculatePost();

public slots:
    void showWindow();
    void slotButtonGroupClicked(QAbstractButton *button);


private slots:
    void on_toolButton_calo_clicked(bool checked);

    void on_lineEdit_textChanged(const QString &str);

private:
    Ui::CalculatorWindow *ui;
    ToolForm*tool;
    QQueue<QString> queue;  //队列
    QStack<QString> stack;  //栈
    QString express;    //表达式
};

#endif // CALCULATORWINDOW_H
