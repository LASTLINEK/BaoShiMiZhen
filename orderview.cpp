#include "orderview.h"
#include "ui_orderview.h"
#include <QStandardItemModel>

OrderView::OrderView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderView)
{
    ui->setupUi(this);

}

OrderView::~OrderView()
{
    delete ui;
}

void OrderView::setData(QList<user> lis)
{
    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("用户名")));      //设置表头
    model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("积分")));

    ui->tableView->setGridStyle(Qt::DotLine);                   //虚线表格

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //不可修改

//    ui->tableView->setStyleSheet("QTableView { border: none;"
//                                     "selection-background-color: #8EDE21;"
//                                     "color: red}");

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    for(int i=0;i<lis.length();i++)
    {
        model->setItem(i, 0, new QStandardItem(lis[i].username));
        model->setItem(i, 1, new QStandardItem(QString::number(lis[i].score)));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);       //居中
        model->item(i,1)->setTextAlignment(Qt::AlignCenter);       //居中
        model->item(i,0)->setForeground(QBrush(QColor(0,0,155)));   //颜色
        model->item(i,1)->setForeground(QBrush(QColor(155,0,0)));
    }

    model->sort(1, Qt::AscendingOrder);
}

