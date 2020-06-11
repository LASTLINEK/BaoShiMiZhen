#ifndef CHOOSEDIF_H
#define CHOOSEDIF_H

#include <QDialog>
#include "UI.h"

namespace Ui {
class ChooseDif;
}

class ChooseDif : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseDif(QWidget *parent = nullptr);
    ~ChooseDif();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChooseDif *ui;

signals:
    void sendGoal(int);
};

#endif // CHOOSEDIF_H
