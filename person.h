#ifndef PERSON_H
#define PERSON_H

#include <QDialog>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
typedef struct person{    //联系人类
    QString name;
    QString city;
    QString phone;
    QString type;   //分组类型
    QString email;
    QString Time;

    person *next;   //指针域
    person(){}
    person(QString name, QString phone, QString city, QString email, QString type, QString Time)
    {                       //自定义的构造函数
        this->name = name;
        this->city = city;
        this->phone = phone;
        this->email = email;
        this->type = type;
        this->Time = Time;
    }
}person,ElemType,*List;

void ReadFile();
void SaveFile();

#endif // PERSON_H


