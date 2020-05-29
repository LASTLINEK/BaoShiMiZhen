#ifndef ORDERVIEW_H
#define ORDERVIEW_H

#include <QWidget>
#include "playerinfo.h"

namespace Ui {
class OrderView;
}

class OrderView : public QWidget
{
    Q_OBJECT

public:
    explicit OrderView(QWidget *parent = nullptr);
    ~OrderView();

    void setData(QList<user> lis);

public:
    Ui::OrderView *ui;
};

#endif // ORDERVIEW_H
