#include "toolform.h"
#include "ui_toolform.h"
#include <QIcon>
ToolForm::ToolForm(QWidget *parent)
    : QWidget(parent),cur_widget(nullptr)
    , ui(new Ui::ToolForm)
{
    ui->setupUi(this);
    ui->pushButton_player->setIcon(QIcon("../pic/moo.jpg"));
    ui->pushButton_player->setIconSize(QSize(60,60));
    ui->pushButton_calo->setIcon(QIcon("../pic/calo.png"));
    ui->pushButton_calo->setIconSize(QSize(60,60));
    ui->pushButton_2048->setIcon(QIcon("../pic/2048.png"));
    ui->pushButton_2048->setIconSize(QSize(60,60));
    ui->pushButton_rat->setIcon(QIcon("../pic/rat.png"));
    ui->pushButton_rat->setIconSize(QSize(60,60));
}

ToolForm::~ToolForm()
{
    delete ui;
}

void ToolForm::on_pushButton_player_clicked()
{
    //切换到播放器
    emit switchPlayer();
}


void ToolForm::on_pushButton_calo_clicked()
{
    //切换到计算器
    emit switchCalo();
}

