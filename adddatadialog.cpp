#include "adddatadialog.h"
#include "ui_adddatadialog.h"
#include "person.h"
#include "widget.h"

AddDataDialog::AddDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);
    ClearEdit();
}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::ClearEdit(){
    ui->NameEdit->clear();   //先将输入栏中的信息清空
    ui->PhoneEdit->clear();
    ui->CityEdit->clear();
}
void AddDataDialog::AddMessenger(){
    /*QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");  //文件
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)) return ;  //若文件无法打开则返回
    QTextStream stream(&file);
    QString mystring;
    if(stream.readAll()!= ""){  //若文件中已有存储的信息
        mystring+="\n";     //在字符串的开头加一个换行符
    }
    mystring+=ui->NameEdit->text().toUtf8();
    mystring+=" ";
    mystring+=ui->PhoneEdit->text().toUtf8();
    mystring+=" ";
    mystring+=ui->CityEdit->text().toUtf8();
    mystring+="\n";
    QTextCodec *code=QTextCodec::codecForName("utf8");
    stream.setCodec(code);
    stream<<mystring;
    file.close();*/
    List p=Widget::head->next;
    while(p->next!=nullptr){
        p=p->next;   //找到尾节点
    }
    List tmp=new person;
    tmp->name=ui->NameEdit->text().toUtf8();
    tmp->phone=ui->PhoneEdit->text().toUtf8();
    tmp->city=ui->CityEdit->text().toUtf8();
    tmp->type=ui->TypeEdit->text().toUtf8();
    tmp->email=ui->EmailEdit->text().toUtf8();
    tmp->Time=ui->TimeEdit->text().toUtf8();
    tmp->next=nullptr;
    p->next=tmp;
}

void AddDataDialog::on_YesButton_clicked()
{
    AddMessenger();
    SaveFile();   //保存到文件里
}
