#ifndef LOGON_H
#define LOGON_H

#include <QWidget>

namespace Ui {
class Logon;
}

class Logon : public QWidget
{
    Q_OBJECT

public:
    explicit Logon(QWidget *parent = nullptr);
    ~Logon();

private slots:
    void on_passLine_textChanged(const QString &arg1);

    void on_pass2Line_textChanged(const QString &arg1);

    void on_logonBtn_clicked();

private:
    Ui::Logon *ui;

signals:
    void sendMessage(QString name,QString pass);
};

#endif // LOGON_H
