#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "UI.h"


namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Login *ui;
    UI* play;
    playerInfo info;
};

#endif // LOGIN_H
