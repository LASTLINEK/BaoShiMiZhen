/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QRadioButton *RBtn5;
    QRadioButton *RBtn6;
    QPushButton *BtnConfirm;
    QPushButton *BtnCancel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QRadioButton *RBtn1;
    QRadioButton *RBtn2;
    QRadioButton *RBtn3;
    QRadioButton *RBtn4;

    void setupUi(QWidget *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QString::fromUtf8("Setting"));
        Setting->resize(445, 378);
        RBtn5 = new QRadioButton(Setting);
        RBtn5->setObjectName(QString::fromUtf8("RBtn5"));
        RBtn5->setGeometry(QRect(160, 200, 80, 20));
        RBtn6 = new QRadioButton(Setting);
        RBtn6->setObjectName(QString::fromUtf8("RBtn6"));
        RBtn6->setGeometry(QRect(260, 200, 80, 20));
        BtnConfirm = new QPushButton(Setting);
        BtnConfirm->setObjectName(QString::fromUtf8("BtnConfirm"));
        BtnConfirm->setGeometry(QRect(120, 280, 93, 28));
        BtnConfirm->setAutoFillBackground(false);
        BtnCancel = new QPushButton(Setting);
        BtnCancel->setObjectName(QString::fromUtf8("BtnCancel"));
        BtnCancel->setGeometry(QRect(250, 280, 93, 28));
        label = new QLabel(Setting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 190, 100, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/input.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(Setting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 100, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/input.png")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Setting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 200, 60, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Setting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 50, 60, 20));
        label_4->setAlignment(Qt::AlignCenter);
        RBtn1 = new QRadioButton(Setting);
        RBtn1->setObjectName(QString::fromUtf8("RBtn1"));
        RBtn1->setGeometry(QRect(150, 50, 115, 19));
        RBtn2 = new QRadioButton(Setting);
        RBtn2->setObjectName(QString::fromUtf8("RBtn2"));
        RBtn2->setGeometry(QRect(260, 50, 115, 19));
        RBtn3 = new QRadioButton(Setting);
        RBtn3->setObjectName(QString::fromUtf8("RBtn3"));
        RBtn3->setGeometry(QRect(150, 120, 115, 19));
        RBtn4 = new QRadioButton(Setting);
        RBtn4->setObjectName(QString::fromUtf8("RBtn4"));
        RBtn4->setGeometry(QRect(260, 120, 115, 19));

        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QWidget *Setting)
    {
        Setting->setWindowTitle(QCoreApplication::translate("Setting", "Form", nullptr));
        RBtn5->setText(QCoreApplication::translate("Setting", "Bgm1", nullptr));
        RBtn6->setText(QCoreApplication::translate("Setting", "Bgm2", nullptr));
        BtnConfirm->setText(QCoreApplication::translate("Setting", "\347\241\256\345\256\232", nullptr));
        BtnCancel->setText(QCoreApplication::translate("Setting", "\345\217\226\346\266\210", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("Setting", "\350\203\214\346\231\257\351\237\263\344\271\220", nullptr));
        label_4->setText(QCoreApplication::translate("Setting", "\344\270\273\351\242\230", nullptr));
        RBtn1->setText(QCoreApplication::translate("Setting", "\351\273\230\350\256\244", nullptr));
        RBtn2->setText(QCoreApplication::translate("Setting", "\346\265\267\346\264\213", nullptr));
        RBtn3->setText(QCoreApplication::translate("Setting", "\346\230\237\347\251\272", nullptr));
        RBtn4->setText(QCoreApplication::translate("Setting", "\346\234\250\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
