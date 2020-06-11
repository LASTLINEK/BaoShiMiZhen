/********************************************************************************
** Form generated from reading UI file 'choosedif.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEDIF_H
#define UI_CHOOSEDIF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ChooseDif
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *ChooseDif)
    {
        if (ChooseDif->objectName().isEmpty())
            ChooseDif->setObjectName(QString::fromUtf8("ChooseDif"));
        ChooseDif->resize(399, 258);
        ChooseDif->setAutoFillBackground(false);
        ChooseDif->setStyleSheet(QString::fromUtf8("border-image: url(:/back/orderBg .jpg);"));
        groupBox = new QGroupBox(ChooseDif);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(80, 30, 221, 161));
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 0);"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(50, 40, 89, 16));
        radioButton->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 0);"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(50, 80, 89, 16));
        radioButton_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 255);"));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(50, 120, 89, 16));
        radioButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        pushButton = new QPushButton(ChooseDif);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 200, 75, 23));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 127);"));

        retranslateUi(ChooseDif);

        QMetaObject::connectSlotsByName(ChooseDif);
    } // setupUi

    void retranslateUi(QDialog *ChooseDif)
    {
        ChooseDif->setWindowTitle(QCoreApplication::translate("ChooseDif", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ChooseDif", "\350\257\267\351\200\211\346\213\251\344\275\240\350\246\201\345\260\235\350\257\225\347\232\204\351\232\276\345\272\246\357\274\232", nullptr));
        radioButton->setText(QCoreApplication::translate("ChooseDif", "\351\232\276\345\272\2461", nullptr));
        radioButton_2->setText(QCoreApplication::translate("ChooseDif", "\351\232\276\345\272\2462", nullptr));
        radioButton_3->setText(QCoreApplication::translate("ChooseDif", "\351\232\276\345\272\2463", nullptr));
        pushButton->setText(QCoreApplication::translate("ChooseDif", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseDif: public Ui_ChooseDif {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEDIF_H
