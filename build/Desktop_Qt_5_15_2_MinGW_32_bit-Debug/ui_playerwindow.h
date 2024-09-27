/********************************************************************************
** Form generated from reading UI file 'playerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERWINDOW_H
#define UI_PLAYERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerWindow
{
public:
    QWidget *centralwidget;
    QToolButton *toolButton;
    QSlider *horizontalSlider;
    QLabel *label_moo;
    QPushButton *pb_prev;
    QPushButton *pb_stop;
    QPushButton *pb_next;
    QPushButton *pb_like;
    QPushButton *pb_model;
    QPushButton *pb_conv;
    QSlider *verticalSlider;
    QListWidget *listWidget;
    QLabel *label_99;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *PlayerWindow)
    {
        if (PlayerWindow->objectName().isEmpty())
            PlayerWindow->setObjectName(QString::fromUtf8("PlayerWindow"));
        PlayerWindow->resize(800, 480);
        PlayerWindow->setMinimumSize(QSize(800, 480));
        PlayerWindow->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(PlayerWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(770, 160, 27, 25));
        toolButton->setCheckable(true);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(160, 445, 441, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_moo = new QLabel(centralwidget);
        label_moo->setObjectName(QString::fromUtf8("label_moo"));
        label_moo->setGeometry(QRect(10, 0, 69, 61));
        pb_prev = new QPushButton(centralwidget);
        pb_prev->setObjectName(QString::fromUtf8("pb_prev"));
        pb_prev->setGeometry(QRect(5, 433, 50, 40));
        pb_stop = new QPushButton(centralwidget);
        pb_stop->setObjectName(QString::fromUtf8("pb_stop"));
        pb_stop->setGeometry(QRect(65, 433, 30, 40));
        pb_next = new QPushButton(centralwidget);
        pb_next->setObjectName(QString::fromUtf8("pb_next"));
        pb_next->setGeometry(QRect(105, 433, 50, 40));
        pb_like = new QPushButton(centralwidget);
        pb_like->setObjectName(QString::fromUtf8("pb_like"));
        pb_like->setGeometry(QRect(620, 433, 40, 40));
        pb_model = new QPushButton(centralwidget);
        pb_model->setObjectName(QString::fromUtf8("pb_model"));
        pb_model->setGeometry(QRect(680, 433, 40, 40));
        pb_conv = new QPushButton(centralwidget);
        pb_conv->setObjectName(QString::fromUtf8("pb_conv"));
        pb_conv->setGeometry(QRect(740, 433, 40, 40));
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(750, 270, 22, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 70, 171, 361));
        label_99 = new QLabel(centralwidget);
        label_99->setObjectName(QString::fromUtf8("label_99"));
        label_99->setGeometry(QRect(90, 30, 611, 411));
        PlayerWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(PlayerWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        PlayerWindow->setMenuBar(menuBar);

        retranslateUi(PlayerWindow);

        QMetaObject::connectSlotsByName(PlayerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlayerWindow)
    {
        PlayerWindow->setWindowTitle(QCoreApplication::translate("PlayerWindow", "MainWindow", nullptr));
        toolButton->setText(QCoreApplication::translate("PlayerWindow", "...", nullptr));
        label_moo->setText(QCoreApplication::translate("PlayerWindow", "TextLabel", nullptr));
        pb_prev->setText(QCoreApplication::translate("PlayerWindow", "PushButton", nullptr));
        pb_stop->setText(QCoreApplication::translate("PlayerWindow", "PushButton", nullptr));
        pb_next->setText(QCoreApplication::translate("PlayerWindow", "PushButton", nullptr));
        pb_like->setText(QCoreApplication::translate("PlayerWindow", "PushButton", nullptr));
        pb_model->setText(QCoreApplication::translate("PlayerWindow", "PushButton", nullptr));
        pb_conv->setText(QCoreApplication::translate("PlayerWindow", "PushButton", nullptr));
        label_99->setText(QCoreApplication::translate("PlayerWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerWindow: public Ui_PlayerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERWINDOW_H
