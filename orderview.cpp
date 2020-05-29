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
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Score")));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(int i=0;i<lis.length();i++)
    {
        model->setItem(i, 0, new QStandardItem(lis[i].username));
        model->setItem(i, 1, new QStandardItem(QString::number(lis[i].score)));
    }
    model->sort(1, Qt::AscendingOrder);
}

