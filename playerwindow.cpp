
#include "playerwindow.h"
#include "ui_playerwindow.h"
#include <QDebug>
#include "logindialog.h"
#include <QFileDialog>
#include <QDir>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QScrollBar>
#include <QSlider>
#include "database.h"
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QSqlError>
extern database databs;

PlayerWindow::PlayerWindow(ToolForm*tool,QWidget *parent)
    : QMainWindow(parent),tool(tool),music_index(0),is_playing(false),isshow(false)
    , ui(new Ui::PlayerWindow),dir_path("../music"),is_like(false)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../pic/moo.jpg"));
    this->setWindowTitle("Moo音乐");
    ui->label_moo->setScaledContents(true);
    ui->label_moo->setPixmap(QPixmap("../pic/moo.jpg"));
    ui->pb_stop->setIcon(QIcon("../pic/play.png"));//暂停键
    ui->pb_stop->setIconSize(QSize(40, 40)); // 设置图标大小
    ui->pb_next->setIcon(QIcon("../pic/next.png"));//下一首
    ui->pb_next->setIconSize(QSize(50,40));
    ui->pb_prev->setIcon(QIcon("../pic/prev.png"));//上一首
    ui->pb_prev->setIconSize(QSize(50,40));
    ui->pb_like->setIcon(QIcon("../pic/like1.png"));//喜欢
    ui->pb_prev->setIconSize(QSize(40,40));
    ui->pb_model->setIcon(QIcon("../pic/shun.png"));//模式
    ui->pb_prev->setIconSize(QSize(40,40));
    ui->pb_conv->setIcon(QIcon("../pic/volume.png"));//音量
    ui->pb_prev->setIconSize(QSize(40,40));
    ui->pb_changedir->setIcon(QIcon("../pic/plus.png"));//打开目录
    ui->pb_changedir->setIconSize(QSize(20,20));
    ui->pb_changepic->setIcon(QIcon("../pic/changepic.png"));
    ui->pb_changepic->setIconSize(QSize(30,30));
    ui->verticalSlider->hide();
    ui->comboBox_2->hide();
    getMusicNames();
    processInit();
    timerinit();
    //隐藏歌词控件中的垂直滚动条
    ui->listWidget_ly->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 在构造函数中连接信号和槽
    connect(ui->verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(slotadjustvolume(int)));

}

PlayerWindow::~PlayerWindow()
{
    process->kill();
    delete ui;

}

//获取目录中所有音乐名
void PlayerWindow::getMusicNames()
{
    //实例化一个目录对象
    QDir dir(dir_path);
    //设置文件名过滤器，只获取符合条件的文件名
    QStringList filters;
    filters << "*.mp3" << "*.wav" << "*.wma";
    dir.setNameFilters(filters);
    music_names = dir.entryList();

    // 清空 listWidget 中的内容
    ui->listWidget->clear();

    //准备原始语句将获取到的歌曲添加进数据库
    QSqlQuery query(databs.db);
    query.prepare("INSERT OR IGNORE INTO t_music (mus_id, mus_name, mus_path) VALUES (:id, :name, :path)");


    // 遍历 music_names 列表,为每个文件名创建一个 QListWidgetItem 并设置图标
    for (auto& filename : music_names)
    {
        //absoluteFilePath 是 QDir 类的一个方法，用于获取文件的绝对路径。它返回包含完整目录路径和文件名的字符串。
        QString filePath = dir.absoluteFilePath(filename);
        //QCryptographicHash::hash 是一个静态方法，用于计算给定数据的加密哈希值。在这个上下文中，它被用来生成文件路径的 MD5 哈希值。
        //这个哈希值可以作为文件的唯一标识符，因为即使文件名相同，只要路径不同，生成的哈希值就会不同。
        QString fileId = QCryptographicHash::hash(filePath.toUtf8(), QCryptographicHash::Md5).toHex();

        query.bindValue(":id", fileId);
        query.bindValue(":name", filename);
        query.bindValue(":path", filePath);
        if (!query.exec())
        {
            qDebug() << "Failed to insert music into t_music:" << query.lastError().text();
        }

        QString displayName = filename;
        displayName.chop(4);  // 移除后缀用于显示
        QListWidgetItem* item = new QListWidgetItem(QIcon("../pic/music.png"), displayName);
        item->setData(Qt::UserRole, filename);  // 存储完整文件名
        ui->listWidget->addItem(item);
    }
    ui->listWidget->setCurrentRow(0);
}
//初始化进程
void PlayerWindow::processInit()
{
    //实例化一个进程对象
    process = new QProcess(this);
    //设置外部程序的路径
    process->setProgram("/usr/bin/mplayer");
    //关联进程的信号
    connect(process,SIGNAL(started()),this,SLOT(slotProcessStarted()));
    connect(process,SIGNAL(finished(int)),this,SLOT(slotProcessFinished(int)));
    connect(process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(slotProcessError(QProcess::ProcessError)));
    connect(process,SIGNAL(readyRead()),this,SLOT(slotProcessReadyRead()));

}
//播放音频
void PlayerWindow::playMusic()
{
    //如果有音乐播放则先关闭
    if(process->state() == QProcess::ProcessState::Running)
    {
        process->close();
    }
    if(music_names.isEmpty())
    {
        return;
    }
    //获取要播放的音乐名
    QString music_pathname = dir_path + '/' +music_names.at(music_index);
    //设置播放器的参数
    QStringList args;
    args << "-slave" << "-quiet" <<music_pathname;
    process->setArguments(args);
    //启动进程
    process->start();
    //获取音乐总时长
    process->write("get_time_length\n");
    //显示歌词
    showlyrics();
    //启动定时器获取播放时间
    play_timer->start();
}

void PlayerWindow::timerinit()
{
    //实例化定时器对象
    sys_timer = new QTimer(this);
    play_timer = new QTimer(this);
    //设置超时时间
    sys_timer->setInterval(1000);//定时1秒
    play_timer->setInterval(20);//定时20毫秒
    //连接信号和槽
    connect(sys_timer,SIGNAL(timeout()),this,SLOT(slotSysTimerOut()));
    connect(play_timer,SIGNAL(timeout()),this,SLOT(slotPlayTimeOut()));
}

void PlayerWindow::showlyrics()
{
    //先清楚控件上的歌词
    ui->listWidget_ly->clear();
    //清楚上首歌的时间链表
    time_list.clear();
    //每次播放前都将滚轮设置在歌词最上方
    ui->listWidget_ly->verticalScrollBar()->setSliderPosition(0);
    //获取当前音乐名
    QString cur_music_name = music_names.at(music_index);
    //将音乐名转换为歌词文件名，以便通过歌名找到对应的歌词
    QString lyrics_name = cur_music_name.replace(".mp3",".lrc");
    //获取歌词文件路径
    QString lyrics_path = dir_path + "/" + lyrics_name;
    //实例化一个file文件
    QFile file(lyrics_path);
    //如果歌词文件不存在
    if(!file.exists())
    {
        //没找到歌词文件
        qDebug() << "歌词文件不存在！";
        return;
    }
    //打开歌词文件，只读形式
    if(!file.open(QIODevice::ReadOnly))
    {
        //如果文件打开错误则将错误信息输出
        qDebug() <<"open"<<lyrics_path<<"error:"<<file.errorString();
        return;
    }
    //实例化一个文本流对象
    QTextStream in(&file);
    //设置字符编码格式
    in.setCodec("GBK");
    //读取文件中数据，如果每到末尾就一直读
    while(!in.atEnd())
    {
        //一次读一行
        QString line = in.readLine();
        //去除歌词前面的时间
        if(line.length()>=10)
        {
            if(line.at(0) == '[' and line.at(9) == ']')
            {
                //将时间信息插入时间链表
                time_list.push_back(line.mid(1,7));
                //删除前面的时间
                line.remove(0,10);
            }
            else if(line.at(0) == '[' and line.at(10) == ']')
            {
                //将时间信息插入链表
                time_list.push_back((line.mid(1,7)));
                //删除前面的时间
                line.remove(0,11);
            }
        }
        //歌词居中显示
        QListWidgetItem *item = new QListWidgetItem(line);
        item->setTextAlignment(Qt::AlignCenter);
        item->setForeground(Qt::white);
        //将读到的歌词显示到控件上去
        ui->listWidget_ly->addItem(item);
    }

}
//同步歌词
void PlayerWindow::inStepLyrics(QString &time)
{
    //从歌词时间链表中去匹配时间，如果匹配到了，返回匹配的行号
    //-1表示没匹配到
    int lrc_row = time_list.indexOf(time);
    if(lrc_row == -1) return;//没找到
    // 重置所有行的字体大小
    for (int i = 0; i < ui->listWidget_ly->count(); ++i)
    {
        ui->listWidget_ly->item(i)->setFont(QFont("Default", 15));
        ui->listWidget_ly->item(i)->setTextColor(QColor(255,255,255));
    }
    //如果找到了，就高亮显示
    if(lrc_row >= 1)
    {
        //将前一行颜色恢复
        ui->listWidget_ly->item(lrc_row-1)->setTextColor(QColor(255,255,255));
    }
    ui->listWidget_ly->item(lrc_row)->setTextColor(QColor(0,255,0));
    ui->listWidget_ly->item(lrc_row)->setFont(QFont("Default", 20));
    //设置滚动条位置，自动滚屏
    if(lrc_row >= 6)
    {
        ui->listWidget_ly->verticalScrollBar()->setSliderPosition(lrc_row-6);
    }
}

void PlayerWindow::showWindow()
{
    //保存用户账号信息
    //根据用户账号查询用户信息(头像、昵称、歌单、上一次播放的歌曲...)
    //初始化播放器界面(设置头像，设置昵称，加载歌单...)
    //隐藏切换前的界面
    if(tool->cur_widget)
    {
        tool->cur_widget->hide();
    }
    //设置当前界面为播放器界面
    tool->cur_widget = this;
    tool->setParent(this);
    //设置跳转框位置
    int x=ui->toolButton->x()-273;
    int y=ui->toolButton->y();

    tool->move(x,y);
    tool->hide();
    ui->toolButton->setChecked(false);
    //显示播放器界面
    show();\
    //更新喜欢标志
    updateLikeButtonState();
    //获取当前时间，并显示到控件上
    ui->label_systime->setText(QDateTime::currentDateTime().toString("MM/dd hh:mm dddd"));
    //启动定时器
    sys_timer->start();
    //显示第一首歌的歌词
    showlyrics();
}

void PlayerWindow::slotProcessStarted()
{
   qDebug() <<"process started success!";
}

void PlayerWindow::slotProcessFinished(int code)
{
    qDebug() <<"process finished with "<<code;
}

void PlayerWindow::slotProcessError(QProcess::ProcessError err)
{
    qDebug() <<"process error:" << err << "," << process->errorString();
}

void PlayerWindow::slotProcessReadyRead()
{
    //读取进程发送来的数据
    while(process->canReadLine())
    {
        QString str = process->readLine();
        if(str.contains("ANS_LENGTH="))
        {
            //获取到时间这一行后，将头和尾都删去
            str.remove("ANS_LENGTH=");
            str.remove("\n");
            //将时间转换为浮点数
            float total_time = str.toFloat();
            //将时间转为分秒形式
            int sec = (int)total_time%60;
            int min = total_time/60;
            //组成一个时间字符串
            QString str_toltime = QString("%1:%2").arg(min).arg(sec);
            //将时间设置到空间上去
            ui->label_mus_toltime->setText(str_toltime);
        }
        else if(str.contains("ANS_TIME_POSITION="))
        {
            //这一行数据是包含当前播放时间数据的字符串
            //提取里面的时间(去头掐尾)
            str.remove("ANS_TIME_POSITION=");
            str.remove("\n");
            //将剩余的时间字符串转换成浮点数
            float play_time = str.toFloat();
            //将总时长转换成分钟秒钟的形式
            QString fractional_part = str.mid(str.length()-2,2);  //获取小数部分
            int sec = (int)play_time%60;
            int min = play_time/60;
            QString str_min = QString::number(min);
            if(min < 10)
            {
                str_min = "0" + str_min;
            }
            QString str_sec = QString::number(sec);
            if(sec < 10)
            {
                str_sec = "0" + str_sec;
            }
            p_time = str_min + ":" + str_sec + fractional_part;
            inStepLyrics(p_time);
            m_time = str_min + ":" + str_sec;
            ui->label_mus_curtime->setText(m_time);
        }
    }
}

void PlayerWindow::slotSysTimerOut()
{
    //
    QString sys_time = QDateTime::currentDateTime().toString("MM/dd hh:mm dddd");
    //
    ui->label_systime->setText(sys_time);
}

void PlayerWindow::slotPlayTimeOut()
{
    //发送获取播放时间的命令
    if(is_playing)
    {
        process->write("get_time_pos\n");
    }
}



void PlayerWindow::slotadjustvolume(int value)
{
    QString volumeCommand = QString("volume %1 1\n").arg(value);

    // 发送音量控制命令到进程
    if (is_playing)
    {
        process->write(volumeCommand.toUtf8());
    }
}


void PlayerWindow::on_toolButton_clicked(bool checked)
{
    if(checked)
    {
        tool->show();
    }
    else
    {
        tool->hide();
    }
}

//暂停
void PlayerWindow::on_pb_stop_clicked()
{
    //如果有进程在运行状态，说明播放器要么是播放状态，要么是暂停状态
    if(process->state() != QProcess::ProcessState::Running)
    {
        //播放器没有播放音频，也没有暂停
        //先启动
        playMusic();
        //将文本改为暂停
        ui->pb_stop->setIcon(QIcon("../pic/stop.png"));
        ui->pb_stop->setIconSize(QSize(40, 40)); // 设置图标大小
        //更改状态量
        is_playing = true;
    }
    else
    {
        if(is_playing)
        {
            is_playing = false;
            ui->pb_stop->setIcon(QIcon("../pic/play.png"));
            ui->pb_stop->setIconSize(QSize(40, 40)); // 设置图标大小
        }
        else
        {
            is_playing = true;
            ui->pb_stop->setIcon(QIcon("../pic/stop.png"));
            ui->pb_stop->setIconSize(QSize(40, 40)); // 设置图标大小
        }
        //发送暂停指令
        process->write("pause\n");
    }

}
//上一曲
void PlayerWindow::on_pb_prev_clicked()
{
    is_playing = true;
    ui->pb_stop->setIcon(QIcon("../pic/stop.png"));
    ui->pb_stop->setIconSize(QSize(40,40));
    switch (play_mode)
    {
        case PlayMode::Sequential://保证index在size范围内，实现循环播放
            music_index = (music_index - 1 + music_names.size()) % music_names.size();
            break;
        case PlayMode::SingleLoop:
            // 不变
            break;
        case PlayMode::Random:
            int temp = qrand() % music_names.size();
            if(temp != music_index)//防止随机到当前歌曲
                music_index = temp;
            break;
    }
    // 设置 listWidget 的当前选中行为 music_index
    ui->listWidget->setCurrentRow(music_index);
    //更新喜欢标志
    updateLikeButtonState();
    playMusic();
}
//下一曲
void PlayerWindow::on_pb_next_clicked()
{
    is_playing = true;
    ui->pb_stop->setIcon(QIcon("../pic/stop.png"));
    ui->pb_stop->setIconSize(QSize(40,40));
    switch (play_mode)
    {
        case PlayMode::Sequential:
            music_index = (music_index + 1) % music_names.size();
            break;
        case PlayMode::SingleLoop:
            // 不变
            break;
        case PlayMode::Random:
        int temp = qrand() % music_names.size();
        if(temp != music_index)//防止随机到当前歌曲
            music_index = temp;
    }
    // 设置 listWidget 的当前选中行为 music_index
    ui->listWidget->setCurrentRow(music_index);
    //更新喜欢标志
    updateLikeButtonState();
    playMusic();
}

void PlayerWindow::on_pb_changedir_clicked()
{
    //更换目录
    dir_path = QFileDialog::getExistingDirectory(this,"打开","../");
    //更新歌单
    getMusicNames();
}

void PlayerWindow::on_pb_model_clicked()
{
    switch (play_mode)
    {
        case PlayMode::Sequential:
            play_mode = PlayMode::SingleLoop;
            ui->pb_model->setIcon(QIcon("../pic/loop.png"));
            break;
        case PlayMode::SingleLoop:
            play_mode = PlayMode::Random;
            ui->pb_model->setIcon(QIcon("../pic/random.png"));
            break;
        case PlayMode::Random:
            play_mode = PlayMode::Sequential;
            ui->pb_model->setIcon(QIcon("../pic/shun.png"));
            break;
    }
}

void PlayerWindow::on_pb_conv_clicked()
{
    if(isshow)
    {
        ui->verticalSlider->hide();
        isshow = false;
    }
    else
    {
        ui->verticalSlider->show();
        isshow = true;
    }
}


void PlayerWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    // 获取被双击项目在列表中的索引,更新 music_index 为选中项目的索引
    music_index = ui->listWidget->row(item);
    ui->pb_stop->setIcon(QIcon("../pic/stop.png"));
    ui->pb_stop->setIconSize(QSize(40,40));
    // 播放选中的音乐
    playMusic();
}

void PlayerWindow::on_comboBox_currentIndexChanged(const QString &speed)
{
    QString cmd = QString("speed_set %1\n").arg(speed);
    process->write(cmd.toUtf8());
}


//调节音量
void PlayerWindow::on_verticalSlider_valueChanged(int value)
{
    value = ui->verticalSlider->value();
    slotadjustvolume(value);
}


void PlayerWindow::on_pb_like_clicked()
{
    QString currentSong = music_names.at(music_index);
    QString currentUser = Dialog::user_id;

    // 查询数据库，获取当前歌曲的 mus_id
    QSqlQuery query(databs.db);
    query.prepare("SELECT mus_id FROM t_music WHERE mus_name = :name");
    query.bindValue(":name", currentSong);

    QString songId;
    if (query.exec() && query.next()) {
        songId = query.value(0).toString();
    } else {
        qDebug() << "Failed to find song ID for" << currentSong;
        return;
    }

    // 调用 toggleLikedSong 函数，并传入 songId 而非 currentSong
    if (databs.toggleLikedSong(currentUser, songId))
    {
        updateLikeButtonState();
    }


}
void PlayerWindow::updateLikeButtonState()
{
    QString currentSong = music_names.at(music_index);
    QString currentUser = Dialog::user_id;

    QSqlQuery query(databs.db);
    query.prepare("SELECT mus_id FROM t_music WHERE mus_name = :name");
    query.bindValue(":name", currentSong);

    QString songId;
    if (query.exec() && query.next())
    {
        songId = query.value(0).toString();
    }
    else
    {
        qDebug() << "Failed to find song ID for" << currentSong;
        return;
    }

    if (databs.isLikedSong(currentUser, songId))
    {
        ui->pb_like->setIcon(QIcon("../pic/like2.png"));
        is_like = true;
        qDebug() << "Setting like button icon to111" << (is_like ? "../pic/like2.png" : "../pic/like1.png");

    }
    else
    {
        ui->pb_like->setIcon(QIcon("../pic/like1.png"));
        is_like = false;
        qDebug() << "Setting like button icon to222" << (is_like ? "../pic/like2.png" : "../pic/like1.png");

    }
}



void PlayerWindow::on_pb_changepic_clicked()
{
    if(comshow)
    {
        ui->comboBox_2->hide();
        comshow = false;
    }
    else
    {
        ui->comboBox_2->show();
        comshow = true;
    }
}

void PlayerWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString styleSheet;

    if (arg1 == "girl")
    {
        styleSheet = "QLabel#label_bk { background-image: url(:/pic/bk.jpg); }";
    }
    else if (arg1 == "真爱粉")
    {
        styleSheet = "QLabel#label_bk { background-image: url(:/pic/ikun.png); }";
    }
    else if (arg1 == "小黑子")
    {
        styleSheet = "QLabel#label_bk { background-image: url(:/pic/heizi.png); }";
    }

    if (!styleSheet.isEmpty()) {
        ui->label_bk->setStyleSheet(styleSheet);
    }

}






