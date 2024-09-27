#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QMainWindow>
#include "toolform.h"
#include <QProcess>
#include <QListWidgetItem>
#include <QTimer>
#include <QList>
namespace Ui {
class PlayerWindow;
}

class PlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayerWindow(ToolForm*tool,QWidget *parent = nullptr);
    ~PlayerWindow();
    void getMusicNames();   //获取歌曲目录中所有音乐的名字
    void processInit();     //初始化进程
    void playMusic();       //播放音频
    void timerinit();       //初始化定时器
    void showlyrics();      //显示歌词
    void inStepLyrics(QString &time);   //同步歌词
    void updateLikeButtonState();//更新喜欢标志
public slots:
    void showWindow();
    void slotProcessStarted();  //当进程启动成功以后的槽函数
    void slotProcessFinished(int);  //进程结束时的槽函数
    void slotProcessError(QProcess::ProcessError);  //进程出错时的槽函数
    void slotProcessReadyRead();    //进程有数据可读时的槽函数
    void slotSysTimerOut();         //获取系统时间
    void slotPlayTimeOut();         //获取播放时间
    void slotadjustvolume(int);     //调节音量

private slots:
    void on_toolButton_clicked(bool checked);

    void on_pb_stop_clicked();

    void on_pb_prev_clicked();

    void on_pb_next_clicked();

    void on_pb_changedir_clicked();

    void on_pb_model_clicked();

    void on_pb_conv_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_verticalSlider_valueChanged(int value);

    void on_pb_like_clicked();

    void on_pb_changepic_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::PlayerWindow *ui;
    QString id;
    ToolForm *tool;//工具框界面指针
    QString dir_path;   //歌曲目录的路径名
    QStringList music_names;    //目录中所有歌曲的名字列表
    QProcess *process;  //播放音频的进程指针
    int music_index;    //播放的歌曲的索引
    bool is_playing;    //判断播放器是播放还是暂停状态
    enum class PlayMode { Sequential, SingleLoop, Random };
    PlayMode play_mode = PlayMode::Sequential;
    bool isshow;    //音量控制是否显示
    QTimer *sys_timer;//定时器
    QTimer *play_timer;//获取播放时间的定时器
    QList<QString> time_list;   //歌词的时间链表
    QString p_time; //当前歌曲播放时间
    QString m_time; //进度条上的时间
    bool is_like;//是否为喜欢的歌
    bool comshow;
};

#endif // PLAYERWINDOW_H
