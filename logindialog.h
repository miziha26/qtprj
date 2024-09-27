#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void loginsuccess();//登录成功

private slots:
    void on_pushButton_findback_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_reg_clicked();

    void on_pushButton_reg_back_clicked();

    void on_pushButton_find_back_clicked();

    void on_pushButton_find_ok_clicked();

    void on_pushButton_reg_reg_clicked();

private:
    Ui::Dialog *ui;
public:
    static QString user_id;//保存用户账号
};
#endif // LOGINDIALOG_H
