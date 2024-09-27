#ifndef PROJECTWIDGET_H
#define PROJECTWIDGET_H

#include <QWidget>
#include "logindialog.h"
#include "playerwindow.h"
#include "toolform.h"
#include "calculatorwindow.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    ToolForm*tool;
    void run();
private:
    Dialog *login;      //登陆界面指针
    PlayerWindow*player;//播放器指针
    CalculatorWindow*calo;//计算器指针
};
#endif // PROJECTWIDGET_H
