#include "projectwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),tool(new ToolForm)
{}

Widget::~Widget()
{
    delete login;
    delete player;
    delete calo;
}

void Widget::run()
{
    //初始化各界面
    login = new Dialog();
    player = new PlayerWindow(tool);
    calo = new CalculatorWindow(tool);
    //显示登录界面
    login->show();
    //如果登录成功，默认显示播放器界面
    connect(login,&Dialog::loginsuccess,player,&PlayerWindow::showWindow);
    //功能之间跳转
    connect(tool,&ToolForm::switchPlayer,player,&PlayerWindow::showWindow);
    connect(tool,&ToolForm::switchCalo,calo,&CalculatorWindow::showWindow);
    //该界面执行相关的功能

    //如果这个界面退出(返回)

    //退出程序
}
