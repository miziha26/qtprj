#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QDebug>
#include "database.h"
QString Dialog::user_id="";
extern database databs;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../pic/cow.png"));
    this->setWindowTitle("Doggy");
    ui->label_logo->setScaledContents(true);
    ui->label_logo->setPixmap(QPixmap("../pic/dog.png"));
    ui->label_login->setScaledContents(true);
    ui->label_login->setPixmap(QPixmap("../pic/login.png"));
    ui->label_pwd->setScaledContents(true);
    ui->label_pwd->setPixmap(QPixmap("../pic/pwd.png"));
    //设置登陆界面为初始界面
    ui->stackedWidget->setCurrentIndex(0);
}

Dialog::~Dialog()
{
    delete ui;
}


//登录跳转到找回密码
void Dialog::on_pushButton_findback_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->lineEdit_login_pwd->clear();
}

//登录
void Dialog::on_pushButton_login_clicked()
{
    QString id = ui->lineEdit_login_id->text();
    QString passwd = ui->lineEdit_login_pwd->text();
    //判断账号密码是否为空
    if(id.isEmpty() or passwd.isEmpty())
    {
        QMessageBox::critical(this,"错误","用户名或密码不能为空!");
        return;
    }
    //验证账号密码是否正确
    if(databs.usrlogin(id,passwd))
    {
        QMessageBox::information(this,"成功","登录成功");
        //清空密码
        ui->lineEdit_login_pwd->clear();
        //发送登录成功的信号
        user_id = id;
        emit loginsuccess();
        //隐藏登录界面
        hide();
    }
    else
    {
        QMessageBox::critical(this,"错误","用户名或密码错误!");
        //清空密码
        ui->lineEdit_login_pwd->clear();
        return;
    }

}

//登录跳转到注册界面
void Dialog::on_pushButton_reg_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_login_pwd->clear();
}

//注册跳回登录
void Dialog::on_pushButton_reg_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_reg_id->clear();
    ui->lineEdit_reg_phone->clear();
    ui->lineEdit_reg_pwd->clear();
    ui->lineEdit_reg_pwd2->clear();
}

//找回跳转到登录
void Dialog::on_pushButton_find_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_find_id->clear();
    ui->lineEdit_find_newpwd->clear();
    ui->lineEdit_find_pwd2->clear();
}

//找回界面确定，将新密码保存
void Dialog::on_pushButton_find_ok_clicked()
{
    QString id = ui->lineEdit_find_id->text();
    QString newpwd = ui->lineEdit_find_newpwd->text();
    QString newpwd2 = ui->lineEdit_find_pwd2->text();
    if(newpwd != newpwd2)
    {
        QMessageBox::critical(this,"错误","两次输入的密码不相同!");
        return;
    }
    if(!databs.usrfind(id,newpwd))
    {
        //如果语句执行失败说明账户可能不存在
        QMessageBox::critical(this,"失败","账户不存在！");
        return;
    }
    QMessageBox::information(this,"成功","修改成功！请妥善保存您的账号和密码！");
    on_pushButton_find_back_clicked();
}

//注册界面注册按钮
void Dialog::on_pushButton_reg_reg_clicked()
{
    //获取用户输入的信息
    QString id = ui->lineEdit_reg_id->text();
    QString passwd = ui->lineEdit_reg_pwd->text();
    QString passwd2 = ui->lineEdit_reg_pwd2->text();
    QString tel = ui->lineEdit_reg_phone->text();

    //检擦有没有内容为空
    if(id.isEmpty() or passwd.isEmpty() or passwd2.isEmpty() or tel.isEmpty())
    {
        //信息不完整
        QMessageBox::critical(this,"错误","请输入完整的信息再试！");
        return;
    }
    //检查两次密码是否相同
    if(passwd != passwd2)
    {
        //两次输入的密码不同
        QMessageBox::critical(this,"错误","两次输入的密码不同，请检查后再试！");
        return;
    }
    //检查手机号码、身份证号码位数是否正确
    if(tel.length() != 11)
    {
        //手机号码位数错误
        QMessageBox::critical(this,"错误","请输入正确的手机号码！");
        return;
    }

    qDebug() << "id:" << id;
    qDebug() << "passwd:" << passwd;
    qDebug() << "tel:" << tel;

    if(!databs.usrreg(id,passwd,tel))
    {
        //用户已经存在
        QMessageBox::critical(this,"失败","用户已经存在或信息有误!");
        return;
    }
    QMessageBox::information(this,"成功","添加用户成功！");
    on_pushButton_reg_back_clicked();
}

