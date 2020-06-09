/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QPushButton *BtnMode1;
    QPushButton *BtnMode2;
    QPushButton *BtnOverview;
    QPushButton *BtnSetting;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(541, 462);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BtnMode1 = new QPushButton(centralwidget);
        BtnMode1->setObjectName(QString::fromUtf8("BtnMode1"));
        BtnMode1->setGeometry(QRect(220, 70, 100, 30));
        BtnMode2 = new QPushButton(centralwidget);
        BtnMode2->setObjectName(QString::fromUtf8("BtnMode2"));
        BtnMode2->setGeometry(QRect(220, 145, 100, 30));
        BtnOverview = new QPushButton(centralwidget);
        BtnOverview->setObjectName(QString::fromUtf8("BtnOverview"));
        BtnOverview->setGeometry(QRect(220, 220, 100, 30));
        BtnSetting = new QPushButton(centralwidget);
        BtnSetting->setObjectName(QString::fromUtf8("BtnSetting"));
        BtnSetting->setGeometry(QRect(220, 295, 100, 30));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 65, 140, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/input.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 140, 140, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/input.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 290, 140, 40));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/input.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 215, 140, 40));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/input.png")));
        label_4->setScaledContents(true);
        Menu->setCentralWidget(centralwidget);
        label_3->raise();
        label_4->raise();
        label_2->raise();
        label->raise();
        BtnMode1->raise();
        BtnMode2->raise();
        BtnOverview->raise();
        BtnSetting->raise();
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 541, 26));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "MainWindow", nullptr));
        BtnMode1->setText(QCoreApplication::translate("Menu", "\344\274\221\351\227\262\346\250\241\345\274\217", nullptr));
        BtnMode2->setText(QCoreApplication::translate("Menu", "\347\253\236\351\200\237\346\250\241\345\274\217", nullptr));
        BtnOverview->setText(QCoreApplication::translate("Menu", "\346\216\222\350\241\214\346\246\234", nullptr));
        BtnSetting->setText(QCoreApplication::translate("Menu", "\344\270\273\351\242\230\350\256\276\347\275\256", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
