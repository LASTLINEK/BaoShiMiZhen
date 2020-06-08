/********************************************************************************
** Form generated from reading UI file 'logon.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGON_H
#define UI_LOGON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logon
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *logonBtn;
    QLineEdit *lineEdit;
    QLineEdit *passLine;
    QLineEdit *pass2Line;
    QLabel *w2Label;
    QLabel *r1Label;
    QLabel *w1Label;
    QLabel *r2Label;
    QLabel *w11Lable;
    QLabel *w22Lable;

    void setupUi(QWidget *Logon)
    {
        if (Logon->objectName().isEmpty())
            Logon->setObjectName(QString::fromUtf8("Logon"));
        Logon->resize(357, 238);
        QFont font;
        font.setPointSize(11);
        Logon->setFont(font);
        Logon->setAutoFillBackground(true);
        label = new QLabel(Logon);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 51, 20));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 52, 2);"));
        label_2 = new QLabel(Logon);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 90, 51, 20));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(78, 185, 40);"));
        label_3 = new QLabel(Logon);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 140, 71, 20));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(78, 185, 40);"));
        logonBtn = new QPushButton(Logon);
        logonBtn->setObjectName(QString::fromUtf8("logonBtn"));
        logonBtn->setGeometry(QRect(154, 180, 71, 31));
        logonBtn->setFont(font1);
        logonBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 227, 255);\n"
""));
        lineEdit = new QLineEdit(Logon);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(132, 40, 121, 21));
        passLine = new QLineEdit(Logon);
        passLine->setObjectName(QString::fromUtf8("passLine"));
        passLine->setGeometry(QRect(132, 90, 121, 20));
        passLine->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        passLine->setEchoMode(QLineEdit::Password);
        pass2Line = new QLineEdit(Logon);
        pass2Line->setObjectName(QString::fromUtf8("pass2Line"));
        pass2Line->setGeometry(QRect(132, 140, 121, 20));
        pass2Line->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        pass2Line->setEchoMode(QLineEdit::Password);
        w2Label = new QLabel(Logon);
        w2Label->setObjectName(QString::fromUtf8("w2Label"));
        w2Label->setGeometry(QRect(270, 140, 16, 16));
        w2Label->setPixmap(QPixmap(QString::fromUtf8(":/back/wrong.png")));
        w2Label->setScaledContents(true);
        r1Label = new QLabel(Logon);
        r1Label->setObjectName(QString::fromUtf8("r1Label"));
        r1Label->setGeometry(QRect(270, 90, 16, 16));
        r1Label->setPixmap(QPixmap(QString::fromUtf8(":/back/right.png")));
        r1Label->setScaledContents(true);
        w1Label = new QLabel(Logon);
        w1Label->setObjectName(QString::fromUtf8("w1Label"));
        w1Label->setGeometry(QRect(270, 90, 16, 16));
        w1Label->setPixmap(QPixmap(QString::fromUtf8(":/back/wrong.png")));
        w1Label->setScaledContents(true);
        r2Label = new QLabel(Logon);
        r2Label->setObjectName(QString::fromUtf8("r2Label"));
        r2Label->setGeometry(QRect(270, 140, 16, 16));
        r2Label->setPixmap(QPixmap(QString::fromUtf8(":/back/right.png")));
        r2Label->setScaledContents(true);
        w11Lable = new QLabel(Logon);
        w11Lable->setObjectName(QString::fromUtf8("w11Lable"));
        w11Lable->setGeometry(QRect(290, 90, 54, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(9);
        w11Lable->setFont(font2);
        w22Lable = new QLabel(Logon);
        w22Lable->setObjectName(QString::fromUtf8("w22Lable"));
        w22Lable->setGeometry(QRect(290, 140, 71, 16));
        w22Lable->setFont(font2);

        retranslateUi(Logon);

        logonBtn->setDefault(true);


        QMetaObject::connectSlotsByName(Logon);
    } // setupUi

    void retranslateUi(QWidget *Logon)
    {
        Logon->setWindowTitle(QCoreApplication::translate("Logon", "\346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        label->setText(QCoreApplication::translate("Logon", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Logon", "\345\257\206 \347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Logon", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        logonBtn->setText(QCoreApplication::translate("Logon", "\346\263\250\345\206\214", nullptr));
        w2Label->setText(QString());
        r1Label->setText(QString());
        w1Label->setText(QString());
        r2Label->setText(QString());
        w11Lable->setText(QCoreApplication::translate("Logon", "\350\207\263\345\260\2216\344\275\215", nullptr));
        w22Lable->setText(QCoreApplication::translate("Logon", "\345\257\206\347\240\201\344\270\215\344\270\200\350\207\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Logon: public Ui_Logon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGON_H
