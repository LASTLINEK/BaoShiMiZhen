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
    QWidget *centralWidget;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *musicButton;
    QLabel *Label_Score;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

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
        centralWidget = new QWidget(UIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(1200, 800));
        centralWidget->setMaximumSize(QSize(1200, 800));
        centralWidget->setStyleSheet(QString::fromUtf8("#centralWidget{\n"
"border-image: url(:/UI/background.png);\n"
"}\n"
"#centralWidget *{\n"
"border-image: url();\n"
"}"));
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
        pushButton->setGeometry(QRect(1010, 640, 151, 41));
        musicButton = new QPushButton(centralWidget);
        musicButton->setObjectName(QString::fromUtf8("musicButton"));
        musicButton->setGeometry(QRect(1020, 410, 111, 23));
        Label_Score = new QLabel(centralWidget);
        Label_Score->setObjectName(QString::fromUtf8("Label_Score"));
        Label_Score->setGeometry(QRect(1010, 70, 150, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Goudy Old Style"));
        font.setPointSize(22);
        Label_Score->setFont(font);
        Label_Score->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1010, 30, 151, 131));
        label->setPixmap(QPixmap(QString::fromUtf8("art_2.png")));
        label->setScaledContents(true);
        UIClass->setCentralWidget(centralWidget);
        label->raise();
        progressBar->raise();
        lineEdit->raise();
        pushButton->raise();
        musicButton->raise();
        Label_Score->raise();
        menuBar = new QMenuBar(UIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        UIClass->setMenuBar(menuBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(action_1_0);
        menu_2->addAction(actionlll);

        retranslateUi(UIClass);

        QMetaObject::connectSlotsByName(UIClass);
    } // setupUi

    void retranslateUi(QMainWindow *UIClass)
    {
        UIClass->setWindowTitle(QCoreApplication::translate("UIClass", "UI", nullptr));
        actionlll->setText(QCoreApplication::translate("UIClass", "begin", nullptr));
        action_1_0->setText(QCoreApplication::translate("UIClass", "@1.0", nullptr));
        lineEdit->setText(QCoreApplication::translate("UIClass", "5", nullptr));
        pushButton->setText(QCoreApplication::translate("UIClass", "\346\232\202\345\201\234", nullptr));
        musicButton->setText(QCoreApplication::translate("UIClass", "PushButton", nullptr));
        Label_Score->setText(QCoreApplication::translate("UIClass", "0", nullptr));
        label->setText(QString());
        menu->setTitle(QCoreApplication::translate("UIClass", "\345\205\263\344\272\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("UIClass", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIClass: public Ui_UIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
