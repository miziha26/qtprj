/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_logo;
    QLabel *label_login;
    QLabel *label_pwd;
    QLineEdit *lineEdit_login_id;
    QLineEdit *lineEdit_login_pwd;
    QCheckBox *checkBox_auto;
    QCheckBox *checkBox_remeber;
    QPushButton *pushButton_login;
    QPushButton *pushButton_findback;
    QPushButton *pushButton_reg;
    QWidget *page_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page_5;
    QLabel *label_logo_3;
    QLabel *label_login_3;
    QLabel *label_pwd_3;
    QLineEdit *lineEdit_reg_id;
    QLineEdit *lineEdit_reg_phone;
    QPushButton *pushButton_reg_reg;
    QLabel *label_pwd_4;
    QLineEdit *lineEdit_reg_pwd;
    QPushButton *pushButton_reg_back;
    QLineEdit *lineEdit_reg_pwd2;
    QLabel *label_pwd_7;
    QWidget *page_6;
    QWidget *page_7;
    QLabel *label_login_5;
    QLineEdit *lineEdit_find_id;
    QPushButton *pushButton_find_ok;
    QLineEdit *lineEdit_find_newpwd;
    QLabel *label_logo_5;
    QLineEdit *lineEdit_find_pwd2;
    QLabel *label_pwd_9;
    QPushButton *pushButton_find_back;
    QLabel *label_pwd_10;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        Dialog->setMinimumSize(QSize(400, 300));
        Dialog->setMaximumSize(QSize(400, 300));
        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 400, 300));
        stackedWidget->setMinimumSize(QSize(400, 300));
        stackedWidget->setMaximumSize(QSize(400, 300));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_logo = new QLabel(page);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(150, 10, 101, 91));
        label_login = new QLabel(page);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(110, 110, 20, 20));
        label_login->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_pwd = new QLabel(page);
        label_pwd->setObjectName(QString::fromUtf8("label_pwd"));
        label_pwd->setGeometry(QRect(110, 150, 20, 20));
        label_pwd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_login_id = new QLineEdit(page);
        lineEdit_login_id->setObjectName(QString::fromUtf8("lineEdit_login_id"));
        lineEdit_login_id->setGeometry(QRect(141, 110, 141, 25));
        lineEdit_login_id->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_login_pwd = new QLineEdit(page);
        lineEdit_login_pwd->setObjectName(QString::fromUtf8("lineEdit_login_pwd"));
        lineEdit_login_pwd->setGeometry(QRect(141, 150, 141, 25));
        lineEdit_login_pwd->setEchoMode(QLineEdit::Password);
        checkBox_auto = new QCheckBox(page);
        checkBox_auto->setObjectName(QString::fromUtf8("checkBox_auto"));
        checkBox_auto->setGeometry(QRect(100, 190, 98, 23));
        checkBox_remeber = new QCheckBox(page);
        checkBox_remeber->setObjectName(QString::fromUtf8("checkBox_remeber"));
        checkBox_remeber->setGeometry(QRect(218, 190, 98, 23));
        pushButton_login = new QPushButton(page);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(111, 216, 179, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        pushButton_login->setFont(font);
        pushButton_findback = new QPushButton(page);
        pushButton_findback->setObjectName(QString::fromUtf8("pushButton_findback"));
        pushButton_findback->setGeometry(QRect(298, 270, 93, 28));
        pushButton_reg = new QPushButton(page);
        pushButton_reg->setObjectName(QString::fromUtf8("pushButton_reg"));
        pushButton_reg->setGeometry(QRect(10, 270, 93, 28));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget_2 = new QStackedWidget(page_2);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 0, 400, 300));
        stackedWidget_2->setMinimumSize(QSize(400, 300));
        stackedWidget_2->setMaximumSize(QSize(400, 300));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        label_logo_3 = new QLabel(page_5);
        label_logo_3->setObjectName(QString::fromUtf8("label_logo_3"));
        label_logo_3->setGeometry(QRect(110, 0, 191, 71));
        label_logo_3->setAlignment(Qt::AlignCenter);
        label_login_3 = new QLabel(page_5);
        label_login_3->setObjectName(QString::fromUtf8("label_login_3"));
        label_login_3->setGeometry(QRect(109, 70, 41, 20));
        label_login_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_pwd_3 = new QLabel(page_5);
        label_pwd_3->setObjectName(QString::fromUtf8("label_pwd_3"));
        label_pwd_3->setGeometry(QRect(100, 190, 51, 20));
        label_pwd_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_reg_id = new QLineEdit(page_5);
        lineEdit_reg_id->setObjectName(QString::fromUtf8("lineEdit_reg_id"));
        lineEdit_reg_id->setGeometry(QRect(160, 70, 131, 25));
        lineEdit_reg_id->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_reg_phone = new QLineEdit(page_5);
        lineEdit_reg_phone->setObjectName(QString::fromUtf8("lineEdit_reg_phone"));
        lineEdit_reg_phone->setGeometry(QRect(160, 190, 131, 25));
        lineEdit_reg_phone->setEchoMode(QLineEdit::Normal);
        pushButton_reg_reg = new QPushButton(page_5);
        pushButton_reg_reg->setObjectName(QString::fromUtf8("pushButton_reg_reg"));
        pushButton_reg_reg->setGeometry(QRect(80, 230, 93, 28));
        label_pwd_4 = new QLabel(page_5);
        label_pwd_4->setObjectName(QString::fromUtf8("label_pwd_4"));
        label_pwd_4->setGeometry(QRect(110, 110, 41, 20));
        label_pwd_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_reg_pwd = new QLineEdit(page_5);
        lineEdit_reg_pwd->setObjectName(QString::fromUtf8("lineEdit_reg_pwd"));
        lineEdit_reg_pwd->setGeometry(QRect(160, 110, 131, 25));
        lineEdit_reg_pwd->setEchoMode(QLineEdit::Password);
        pushButton_reg_back = new QPushButton(page_5);
        pushButton_reg_back->setObjectName(QString::fromUtf8("pushButton_reg_back"));
        pushButton_reg_back->setGeometry(QRect(230, 230, 93, 28));
        lineEdit_reg_pwd2 = new QLineEdit(page_5);
        lineEdit_reg_pwd2->setObjectName(QString::fromUtf8("lineEdit_reg_pwd2"));
        lineEdit_reg_pwd2->setGeometry(QRect(160, 150, 131, 25));
        lineEdit_reg_pwd2->setEchoMode(QLineEdit::Password);
        label_pwd_7 = new QLabel(page_5);
        label_pwd_7->setObjectName(QString::fromUtf8("label_pwd_7"));
        label_pwd_7->setGeometry(QRect(80, 150, 71, 20));
        label_pwd_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stackedWidget_2->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        stackedWidget_2->addWidget(page_6);
        stackedWidget->addWidget(page_2);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        label_login_5 = new QLabel(page_7);
        label_login_5->setObjectName(QString::fromUtf8("label_login_5"));
        label_login_5->setGeometry(QRect(109, 80, 41, 20));
        label_login_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_find_id = new QLineEdit(page_7);
        lineEdit_find_id->setObjectName(QString::fromUtf8("lineEdit_find_id"));
        lineEdit_find_id->setGeometry(QRect(160, 80, 131, 25));
        lineEdit_find_id->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_find_ok = new QPushButton(page_7);
        pushButton_find_ok->setObjectName(QString::fromUtf8("pushButton_find_ok"));
        pushButton_find_ok->setGeometry(QRect(80, 240, 93, 28));
        lineEdit_find_newpwd = new QLineEdit(page_7);
        lineEdit_find_newpwd->setObjectName(QString::fromUtf8("lineEdit_find_newpwd"));
        lineEdit_find_newpwd->setGeometry(QRect(160, 130, 131, 25));
        lineEdit_find_newpwd->setEchoMode(QLineEdit::Password);
        label_logo_5 = new QLabel(page_7);
        label_logo_5->setObjectName(QString::fromUtf8("label_logo_5"));
        label_logo_5->setGeometry(QRect(110, 10, 191, 71));
        label_logo_5->setAlignment(Qt::AlignCenter);
        lineEdit_find_pwd2 = new QLineEdit(page_7);
        lineEdit_find_pwd2->setObjectName(QString::fromUtf8("lineEdit_find_pwd2"));
        lineEdit_find_pwd2->setGeometry(QRect(160, 180, 131, 25));
        lineEdit_find_pwd2->setEchoMode(QLineEdit::Password);
        label_pwd_9 = new QLabel(page_7);
        label_pwd_9->setObjectName(QString::fromUtf8("label_pwd_9"));
        label_pwd_9->setGeometry(QRect(90, 130, 61, 20));
        label_pwd_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_find_back = new QPushButton(page_7);
        pushButton_find_back->setObjectName(QString::fromUtf8("pushButton_find_back"));
        pushButton_find_back->setGeometry(QRect(230, 240, 93, 28));
        label_pwd_10 = new QLabel(page_7);
        label_pwd_10->setObjectName(QString::fromUtf8("label_pwd_10"));
        label_pwd_10->setGeometry(QRect(80, 180, 71, 20));
        label_pwd_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stackedWidget->addWidget(page_7);

        retranslateUi(Dialog);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_logo->setText(QCoreApplication::translate("Dialog", "Moo Music", nullptr));
        label_login->setText(QCoreApplication::translate("Dialog", "\350\264\246\345\217\267", nullptr));
        label_pwd->setText(QCoreApplication::translate("Dialog", "\345\257\206\347\240\201", nullptr));
        lineEdit_login_id->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        lineEdit_login_pwd->setText(QString());
        lineEdit_login_pwd->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", "\350\276\223\345\205\245\345\257\206\347\240\201"));
        checkBox_auto->setText(QCoreApplication::translate("Dialog", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBox_remeber->setText(QCoreApplication::translate("Dialog", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Dialog", "\347\231\273\345\275\225", nullptr));
        pushButton_findback->setText(QCoreApplication::translate("Dialog", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        pushButton_reg->setText(QCoreApplication::translate("Dialog", "\346\263\250\345\206\214", nullptr));
        label_logo_3->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#55ff7f;\">\346\254\242\350\277\216\346\263\250\345\206\214Moo\351\237\263\344\271\220</span></p></body></html>", nullptr));
        label_login_3->setText(QCoreApplication::translate("Dialog", "\350\264\246\345\217\267", nullptr));
        label_pwd_3->setText(QCoreApplication::translate("Dialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        lineEdit_reg_id->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        lineEdit_reg_phone->setText(QString());
        lineEdit_reg_phone->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267\347\240\201", "\350\276\223\345\205\245\345\257\206\347\240\201"));
        pushButton_reg_reg->setText(QCoreApplication::translate("Dialog", "\346\263\250\345\206\214", nullptr));
        label_pwd_4->setText(QCoreApplication::translate("Dialog", "\345\257\206\347\240\201", nullptr));
        lineEdit_reg_pwd->setText(QString());
        lineEdit_reg_pwd->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", "\350\276\223\345\205\245\345\257\206\347\240\201"));
        pushButton_reg_back->setText(QCoreApplication::translate("Dialog", "\350\277\224\345\233\236", nullptr));
        lineEdit_reg_pwd2->setText(QString());
        lineEdit_reg_pwd2->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", "\350\276\223\345\205\245\345\257\206\347\240\201"));
        label_pwd_7->setText(QCoreApplication::translate("Dialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_login_5->setText(QCoreApplication::translate("Dialog", "\350\264\246\345\217\267", nullptr));
        lineEdit_find_id->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        pushButton_find_ok->setText(QCoreApplication::translate("Dialog", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        lineEdit_find_newpwd->setText(QString());
        lineEdit_find_newpwd->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", "\350\276\223\345\205\245\345\257\206\347\240\201"));
        label_logo_5->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#55ff7f;\">\346\211\276\345\233\236\345\257\206\347\240\201</span></p></body></html>", nullptr));
        lineEdit_find_pwd2->setText(QString());
        lineEdit_find_pwd2->setPlaceholderText(QCoreApplication::translate("Dialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", "\350\276\223\345\205\245\345\257\206\347\240\201"));
        label_pwd_9->setText(QCoreApplication::translate("Dialog", "\346\226\260\345\257\206\347\240\201", nullptr));
        pushButton_find_back->setText(QCoreApplication::translate("Dialog", "\350\277\224\345\233\236", nullptr));
        label_pwd_10->setText(QCoreApplication::translate("Dialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
