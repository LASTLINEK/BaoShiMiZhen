/********************************************************************************
** Form generated from reading UI file 'orderview.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERVIEW_H
#define UI_ORDERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderView
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *OrderView)
    {
        if (OrderView->objectName().isEmpty())
            OrderView->setObjectName(QString::fromUtf8("OrderView"));
        OrderView->resize(297, 434);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        OrderView->setFont(font);
        OrderView->setAutoFillBackground(true);
        gridLayout = new QGridLayout(OrderView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(OrderView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        tableView->setFont(font1);
        tableView->setStyleSheet(QString::fromUtf8("border-image:url(:/UI/background.png)"));
        tableView->setShowGrid(true);
        tableView->setSortingEnabled(true);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(OrderView);

        QMetaObject::connectSlotsByName(OrderView);
    } // setupUi

    void retranslateUi(QWidget *OrderView)
    {
        OrderView->setWindowTitle(QCoreApplication::translate("OrderView", "\346\216\222\350\241\214\346\246\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderView: public Ui_OrderView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERVIEW_H
