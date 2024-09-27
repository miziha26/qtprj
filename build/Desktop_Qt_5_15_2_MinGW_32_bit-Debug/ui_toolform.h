/********************************************************************************
** Form generated from reading UI file 'toolform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLFORM_H
#define UI_TOOLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolForm
{
public:
    QPushButton *pushButton_player;
    QPushButton *pushButton_calo;
    QPushButton *pushButton_rat;
    QPushButton *pushButton_2048;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *ToolForm)
    {
        if (ToolForm->objectName().isEmpty())
            ToolForm->setObjectName(QString::fromUtf8("ToolForm"));
        ToolForm->resize(273, 90);
        pushButton_player = new QPushButton(ToolForm);
        pushButton_player->setObjectName(QString::fromUtf8("pushButton_player"));
        pushButton_player->setGeometry(QRect(1, 0, 60, 60));
        pushButton_calo = new QPushButton(ToolForm);
        pushButton_calo->setObjectName(QString::fromUtf8("pushButton_calo"));
        pushButton_calo->setGeometry(QRect(70, 0, 60, 60));
        pushButton_rat = new QPushButton(ToolForm);
        pushButton_rat->setObjectName(QString::fromUtf8("pushButton_rat"));
        pushButton_rat->setGeometry(QRect(140, 0, 60, 60));
        pushButton_2048 = new QPushButton(ToolForm);
        pushButton_2048->setObjectName(QString::fromUtf8("pushButton_2048"));
        pushButton_2048->setGeometry(QRect(210, 0, 60, 60));
        label = new QLabel(ToolForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(11, 66, 41, 19));
        label_2 = new QLabel(ToolForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(77, 66, 51, 19));
        label_3 = new QLabel(ToolForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(149, 66, 51, 19));
        label_4 = new QLabel(ToolForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 66, 41, 19));

        retranslateUi(ToolForm);

        QMetaObject::connectSlotsByName(ToolForm);
    } // setupUi

    void retranslateUi(QWidget *ToolForm)
    {
        ToolForm->setWindowTitle(QCoreApplication::translate("ToolForm", "Form", nullptr));
        pushButton_player->setText(QCoreApplication::translate("ToolForm", "PushButton", nullptr));
        pushButton_calo->setText(QCoreApplication::translate("ToolForm", "PushButton", nullptr));
        pushButton_rat->setText(QCoreApplication::translate("ToolForm", "PushButton", nullptr));
        pushButton_2048->setText(QCoreApplication::translate("ToolForm", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("ToolForm", "<html><head/><body><p><span style=\" font-weight:700;\">Moo</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ToolForm", "<html><head/><body><p><span style=\" font-weight:700;\">\350\256\241\347\256\227\345\231\250</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ToolForm", "<html><head/><body><p><span style=\" font-weight:700;\">\346\211\223\345\234\260\351\274\240</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ToolForm", "<html><head/><body><p><span style=\" font-weight:700;\">2048</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolForm: public Ui_ToolForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLFORM_H
