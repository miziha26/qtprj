/********************************************************************************
** Form generated from reading UI file 'calculatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORWINDOW_H
#define UI_CALCULATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorWindow
{
public:
    QWidget *centralwidget;
    QToolButton *toolButton_calo;
    QLineEdit *lineEdit;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *CalculatorWindow)
    {
        if (CalculatorWindow->objectName().isEmpty())
            CalculatorWindow->setObjectName(QString::fromUtf8("CalculatorWindow"));
        CalculatorWindow->resize(381, 588);
        centralwidget = new QWidget(CalculatorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        toolButton_calo = new QToolButton(centralwidget);
        toolButton_calo->setObjectName(QString::fromUtf8("toolButton_calo"));
        toolButton_calo->setEnabled(true);
        toolButton_calo->setGeometry(QRect(281, 137, 80, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(true);
        toolButton_calo->setFont(font);
        toolButton_calo->setCheckable(true);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 341, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(22);
        font1.setBold(true);
        lineEdit->setFont(font1);
        lineEdit->setReadOnly(true);
        pushButton_5 = new QPushButton(centralwidget);
        buttonGroup = new QButtonGroup(CalculatorWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(281, 228, 80, 80));
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_6);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(21, 228, 80, 80));
        pushButton_6->setFont(font);
        pushButton_7 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_7);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(108, 228, 80, 80));
        pushButton_7->setFont(font);
        pushButton_8 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_8);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(194, 228, 80, 80));
        pushButton_8->setFont(font);
        pushButton_9 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_9);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(281, 319, 80, 80));
        pushButton_9->setFont(font);
        pushButton_10 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_10);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(21, 319, 80, 80));
        pushButton_10->setFont(font);
        pushButton_11 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_11);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(108, 319, 80, 80));
        pushButton_11->setFont(font);
        pushButton_12 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_12);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(194, 319, 80, 80));
        pushButton_12->setFont(font);
        pushButton_13 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_13);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(281, 410, 80, 80));
        pushButton_13->setFont(font);
        pushButton_14 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_14);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(21, 410, 80, 80));
        pushButton_14->setFont(font);
        pushButton_15 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_15);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(108, 410, 80, 80));
        pushButton_15->setFont(font);
        pushButton_16 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_16);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(194, 410, 80, 80));
        pushButton_16->setFont(font);
        pushButton_17 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_17);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(108, 500, 80, 80));
        pushButton_17->setFont(font);
        pushButton_18 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_18);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(194, 500, 80, 80));
        pushButton_18->setFont(font);
        pushButton_19 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_19);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(21, 500, 80, 80));
        pushButton_19->setFont(font);
        pushButton_20 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_20);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(281, 500, 80, 80));
        pushButton_20->setFont(font);
        pushButton = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(21, 137, 80, 80));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(108, 137, 80, 80));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        buttonGroup->addButton(pushButton_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(194, 137, 80, 80));
        pushButton_3->setFont(font);
        CalculatorWindow->setCentralWidget(centralwidget);

        retranslateUi(CalculatorWindow);

        QMetaObject::connectSlotsByName(CalculatorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalculatorWindow)
    {
        CalculatorWindow->setWindowTitle(QCoreApplication::translate("CalculatorWindow", "MainWindow", nullptr));
        toolButton_calo->setText(QCoreApplication::translate("CalculatorWindow", "...", nullptr));
        lineEdit->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("CalculatorWindow", "+", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CalculatorWindow", "7", nullptr));
        pushButton_7->setText(QCoreApplication::translate("CalculatorWindow", "8", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CalculatorWindow", "9", nullptr));
        pushButton_9->setText(QCoreApplication::translate("CalculatorWindow", "-", nullptr));
        pushButton_10->setText(QCoreApplication::translate("CalculatorWindow", "4", nullptr));
        pushButton_11->setText(QCoreApplication::translate("CalculatorWindow", "5", nullptr));
        pushButton_12->setText(QCoreApplication::translate("CalculatorWindow", "6", nullptr));
        pushButton_13->setText(QCoreApplication::translate("CalculatorWindow", "*", nullptr));
        pushButton_14->setText(QCoreApplication::translate("CalculatorWindow", "1", nullptr));
        pushButton_15->setText(QCoreApplication::translate("CalculatorWindow", "2", nullptr));
        pushButton_16->setText(QCoreApplication::translate("CalculatorWindow", "3", nullptr));
        pushButton_17->setText(QCoreApplication::translate("CalculatorWindow", ".", nullptr));
        pushButton_18->setText(QCoreApplication::translate("CalculatorWindow", "=", nullptr));
        pushButton_19->setText(QCoreApplication::translate("CalculatorWindow", "0", nullptr));
        pushButton_20->setText(QCoreApplication::translate("CalculatorWindow", "/", nullptr));
        pushButton->setText(QCoreApplication::translate("CalculatorWindow", "%", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CalculatorWindow", "c", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CalculatorWindow", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorWindow: public Ui_CalculatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORWINDOW_H
