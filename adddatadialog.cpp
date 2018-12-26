#include "adddatadialog.h"
#include "ui_adddatadialog.h"

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
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");  //文件
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
    file.close();
}

void AddDataDialog::on_YesButton_clicked()
{
    AddMessenger();
}
