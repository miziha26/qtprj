#ifndef TOOLFORM_H
#define TOOLFORM_H

#include <QWidget>

namespace Ui {
class ToolForm;
}

class ToolForm : public QWidget
{
    Q_OBJECT

public:
    explicit ToolForm(QWidget *parent = nullptr);
    ~ToolForm();
    QWidget *cur_widget;    //指向当前界面的指针
signals:
    void switchPlayer();    //切换到播放器
    void switchCalo();      //切换到计算器
private slots:
    void on_pushButton_player_clicked();

    void on_pushButton_calo_clicked();

private:
    Ui::ToolForm *ui;
};

#endif // TOOLFORM_H
