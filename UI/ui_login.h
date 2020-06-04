/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userLine;
    QLineEdit *passLine;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(538, 359);
        Login->setAutoFillBackground(false);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 129, 61, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::RichText);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 190, 41, 31));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::RichText);
        userLine = new QLineEdit(Login);
        userLine->setObjectName(QString::fromUtf8("userLine"));
        userLine->setGeometry(QRect(190, 130, 191, 31));
        userLine->setFrame(false);
        userLine->setDragEnabled(true);
        passLine = new QLineEdit(Login);
        passLine->setObjectName(QString::fromUtf8("passLine"));
        passLine->setGeometry(QRect(190, 190, 191, 31));
        passLine->setFrame(false);
        passLine->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 280, 51, 41));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(Login);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 280, 91, 41));
        pushButton_2->setFlat(true);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 40, 131, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Black"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setTextFormat(Qt::PlainText);
        label_3->setScaledContents(true);
        pushButton_3 = new QPushButton(Login);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(430, 190, 75, 23));
        pushButton_3->setAutoDefault(false);
        pushButton_3->setFlat(false);
        label_4 = new QLabel(Login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 270, 91, 51));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/login.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(Login);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 270, 91, 51));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/login.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(Login);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 120, 101, 51));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/input.png")));
        label_6->setScaledContents(true);
        label_7 = new QLabel(Login);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(80, 180, 101, 51));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/input.png")));
        label_7->setScaledContents(true);
        label_7->raise();
        label_6->raise();
        label_5->raise();
        label_4->raise();
        label->raise();
        label_2->raise();
        userLine->raise();
        passLine->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_3->raise();
        pushButton_3->raise();

        retranslateUi(Login);

        pushButton_3->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
        label->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\345\257\206 \347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\346\254\242\350\277\216\347\231\273\351\231\206\345\256\235\347\237\263\350\277\267\351\230\265\357\274\201", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Login", "\350\267\263\350\277\207", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
