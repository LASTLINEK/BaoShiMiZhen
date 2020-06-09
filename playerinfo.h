#ifndef PLAYERINFO_H
#define PLAYERINFO_H
#include<QSql>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>

struct user
{
    QString username;
    QString password;
    int score = 0;
};



class playerInfo
{
public:
    playerInfo();

    void initDatabase();
    void printData();
    bool findUser(QString name,QString pass);
    bool findUser(QString name);

    user getCurrent();
    void addToList();
    bool addUser(QString name,QString pass);
    void updateScore(QString name,int score);

    QList<user> lis;
    user a;
    QSqlDatabase db;


};

#endif // PLAYERINFO_H
