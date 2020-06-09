#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();
    int select_1;
    int select_2;
private slots:
    void on_BtnCancel_clicked();
    void on_BtnConfirm_clicked();
signals:
    void sendData(QString);   //用来传递数据的信号
private:
    Ui::Setting *ui;
    QButtonGroup *groupButton1;
    QButtonGroup *groupButton2;
};

#endif // SETTING_H
