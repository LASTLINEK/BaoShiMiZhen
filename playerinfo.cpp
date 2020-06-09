﻿#include "playerinfo.h"

playerInfo::playerInfo()
{
    initDatabase();
    addToList();
}

void playerInfo::initDatabase()
{
    db = QSqlDatabase::addDatabase("QODBC");            //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("ds1");        //数据源名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("user_b");                           //登录用户
    db.setPassword("2331");                             //密码
    if(!db.open())                                      //打开数据库
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
        exit(1);                                        //打开失败
    }
    else
    {
        qDebug()<<"database open success!";
    }
}

void playerInfo::printData()
{
    for(int i=0;i<lis.length();i++)
    {
        qDebug()<<lis[i].username<<lis[i].password<<lis[i].score;
    }
}

bool playerInfo::findUser(QString name, QString pass)
{
    for(int i=0;i<lis.length();i++)
    {
        a = lis[i];
        if(a.username==name && a.password == pass)
        {
            return true;
        }
    }
    return false;
}

bool playerInfo::findUser(QString name)
{
    for(int i=0;i<lis.length();i++)
    {
        a = lis[i];
        if(a.username==name)
        {
            return true;
        }
    }
    return false;
}

user playerInfo::getCurrent()
{
    return a;
}

void playerInfo::addToList()
{
    lis.clear();
    QSqlQuery query(db);
    query.exec("SELECT * FROM playerInfo order by score desc");
    while(query.next())
    {
        a.username = query.value(0).toString();
        a.password = query.value(1).toString();
        a.score = query.value(2).toInt();
        lis.append(a);
    }
}

bool playerInfo::addUser(QString name, QString pass)
{
    if(!findUser(name))
    {
        QSqlQuery query(db);
        query.prepare("insert playerInfo(userName,password,score) values(?,?,?)");
        query.bindValue(0,name);
        query.bindValue(1,pass);
        query.bindValue(2,0);
        query.exec();
        addToList();
        return true;
    }
    else
    {
        return false;
    }

}

void playerInfo::updateScore(QString name, int score)
{
    QSqlQuery query(db);
    query.prepare("update playerInfo set score = ? where userName = ?");
    query.addBindValue(score);
    query.addBindValue(name);

    query.exec();
    addToList();
}
