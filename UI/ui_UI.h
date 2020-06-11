/********************************************************************************
** Form generated from reading UI file 'UI.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_H
#define UI_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIClass
{
public:
    QAction *actionlll;
    QAction *action_1_0;
    QAction *actionhelp;
    QAction *actionhelp_2;
    QAction *action_H;
    QWidget *centralWidget;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *musicButton;
    QLabel *Label_Score;
    QLabel *label;
    QPushButton *restart;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_current;
    QPushButton *HintButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *UIClass)
    {
        if (UIClass->objectName().isEmpty())
            UIClass->setObjectName(QString::fromUtf8("UIClass"));
        UIClass->resize(1200, 826);
        UIClass->setLayoutDirection(Qt::LeftToRight);
        UIClass->setStyleSheet(QString::fromUtf8(""));
        actionlll = new QAction(UIClass);
        actionlll->setObjectName(QString::fromUtf8("actionlll"));
        action_1_0 = new QAction(UIClass);
        action_1_0->setObjectName(QString::fromUtf8("action_1_0"));
        actionhelp = new QAction(UIClass);
        actionhelp->setObjectName(QString::fromUtf8("actionhelp"));
        actionhelp_2 = new QAction(UIClass);
        actionhelp_2->setObjectName(QString::fromUtf8("actionhelp_2"));
        action_H = new QAction(UIClass);
        action_H->setObjectName(QString::fromUtf8("action_H"));
        centralWidget = new QWidget(UIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(1200, 800));
        centralWidget->setMaximumSize(QSize(1200, 800));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 20, 530, 30));
        progressBar->setValue(25);
        progressBar->setTextVisible(false);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(590, 20, 120, 30));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(780, 20, 151, 41));
        musicButton = new QPushButton(centralWidget);
        musicButton->setObjectName(QString::fromUtf8("musicButton"));
        musicButton->setGeometry(QRect(1050, 630, 71, 71));
        Label_Score = new QLabel(centralWidget);
        Label_Score->setObjectName(QString::fromUtf8("Label_Score"));
        Label_Score->setGeometry(QRect(1010, 180, 150, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Goudy Old Style"));
        font.setPointSize(22);
        Label_Score->setFont(font);
        Label_Score->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1010, 140, 151, 131));
        label->setPixmap(QPixmap(QString::fromUtf8("art_2.png")));
        label->setScaledContents(true);
        restart = new QPushButton(centralWidget);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setGeometry(QRect(410, 310, 101, 101));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(930, 80, 81, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 0);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(930, 170, 81, 41));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("\343\200\201\343\200\201\n"
"color: rgb(85, 0, 127);"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1040, 80, 54, 41));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/back/art_2.png")));
        label_4->setScaledContents(true);
        label_current = new QLabel(centralWidget);
        label_current->setObjectName(QString::fromUtf8("label_current"));
        label_current->setGeometry(QRect(1050, 90, 71, 16));
        QFont font2;
        font2.setPointSize(16);
        label_current->setFont(font2);
        HintButton = new QPushButton(centralWidget);
        HintButton->setObjectName(QString::fromUtf8("HintButton"));
        HintButton->setGeometry(QRect(1050, 320, 61, 41));
        UIClass->setCentralWidget(centralWidget);
        label->raise();
        progressBar->raise();
        lineEdit->raise();
        pushButton->raise();
        musicButton->raise();
        Label_Score->raise();
        restart->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_current->raise();
        HintButton->raise();
        menuBar = new QMenuBar(UIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        UIClass->setMenuBar(menuBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(action_1_0);
        menu_2->addAction(actionlll);
        menu_3->addAction(action_H);

        retranslateUi(UIClass);

        QMetaObject::connectSlotsByName(UIClass);
    } // setupUi

    void retranslateUi(QMainWindow *UIClass)
    {
        UIClass->setWindowTitle(QCoreApplication::translate("UIClass", "UI", nullptr));
        actionlll->setText(QCoreApplication::translate("UIClass", "begin", nullptr));
        action_1_0->setText(QCoreApplication::translate("UIClass", "@1.0", nullptr));
        actionhelp->setText(QCoreApplication::translate("UIClass", "help", nullptr));
        actionhelp_2->setText(QCoreApplication::translate("UIClass", "help", nullptr));
        action_H->setText(QCoreApplication::translate("UIClass", "\345\270\256\345\212\251(&H)", nullptr));
        lineEdit->setText(QCoreApplication::translate("UIClass", "60", nullptr));
        pushButton->setText(QString());
        musicButton->setText(QString());
        Label_Score->setText(QCoreApplication::translate("UIClass", "0", nullptr));
        label->setText(QString());
        restart->setText(QString());
        label_2->setText(QCoreApplication::translate("UIClass", "\347\233\256\346\240\207\345\210\206\346\225\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("UIClass", "\345\275\223\345\211\215\345\210\206\346\225\260\357\274\232", nullptr));
        label_4->setText(QString());
        label_current->setText(QCoreApplication::translate("UIClass", "0", nullptr));
        HintButton->setText(QCoreApplication::translate("UIClass", "\346\217\220\347\244\272", nullptr));
        menu->setTitle(QCoreApplication::translate("UIClass", "\345\205\263\344\272\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("UIClass", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        menu_3->setTitle(QCoreApplication::translate("UIClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIClass: public Ui_UIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
