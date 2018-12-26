#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}
void SearchDialog::ClearText(){
    ui->NameEdit->clear();   //先将输入栏中的信息清空
    ui->PhoneEdit->clear();
    ui->CityEdit->clear();
    ui->NamelineEdit->clear();
    ui->PhonelineEdit->clear();
    ui->CitylineEdit->clear();
}

void SearchDialog::FindMessenger(){
    QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) return ;
    QTextStream stream(&file);
    stream.setCodec(code);  //设置输出流的字符格式

    QString a;
    a+=stream.readAll();
    QStringList list1=a.split("\n");
    for(int i=0;i<list1.size();i++){
        QStringList list2=list1[i].split(" ");

        if(!ui->PhoneEdit->text().isEmpty()&&ui->PhoneEdit->text()==list2[1]){
            ui->NameEdit->setText(list2[0]);
            ui->PhoneEdit->setText(list2[1]);
            ui->CityEdit->setText(list2[2]);
            break;                //找到第一个符合要求的联系人即退出
        }
        if(!ui->CityEdit->text().isEmpty()&&ui->CityEdit->text()==list2[2]){
            ui->NameEdit->setText(list2[0]);
            ui->PhoneEdit->setText(list2[1]);
            ui->CityEdit->setText(list2[2]);
            break;
        }
        if(!ui->NameEdit->text().isEmpty()&&ui->NameEdit->text()==list2[0]){
            ui->NameEdit->setText(list2[0]);
            ui->PhoneEdit->setText(list2[1]);
            ui->CityEdit->setText(list2[2]);
            break;
        }
    }
    file.close();                 //关闭文件
}
void SearchDialog::FindMessenger(int pos){
    ClearText();     //先清空显示栏
    QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) return ;
    QTextStream stream(&file);
    stream.setCodec(code);  //设置输出流的字符格式

    QString a;
    a+=stream.readAll();
    QStringList list1=a.split("\n");
    QStringList list2=list1[pos].split(" ");
    ui->NameEdit->setText(list2[0]);
    ui->PhoneEdit->setText(list2[1]);
    ui->CityEdit->setText(list2[2]);
    file.close();                 //关闭文件
}

void SearchDialog::on_FindButton_clicked()
{
    FindMessenger();
}

void SearchDialog::DeleteMessenger(){
    QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))  //以只读模式打开文件
        QMessageBox::warning(this,"sdf","can't open!",QMessageBox::Yes);  //如果文件无法打开，弹出对话框
    QTextStream stream(&file);   //将文件中的内容存到流中
    stream.setCodec(code);  //设置流的字符格式
    QString mystring;    //存储要删除的联系人的信息
    mystring+=ui->NameEdit->text().toUtf8();
    mystring+=" ";
    mystring+=ui->PhoneEdit->text().toUtf8();
    mystring+=" ";
    mystring+=ui->CityEdit->text().toUtf8();

    QString a;             //将从流中读取的内容存放在a中
    QString b;             //将文件中除了要删除的内容之外的信息存放在b中
    a+=stream.readAll();
    QStringList list1=a.split("\n");
    for(int i=0;i<list1.size();i++){
        if(list1[i]!=mystring) {
            b+=list1[i];
            if(i!=list1.size()-1) b+="\n";
        }
    }
    file.close();   //关闭文件之后才能对文件进行操作
    file.remove();
    file.setFileName("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");   //使file重新指向数据的文件
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))  //这次以写入模式打开文件
        QMessageBox::warning(this,"sdf","can't open!",QMessageBox::Yes);  //如果文件无法打开，弹出对话框
    QTextStream sstream(&file);
    sstream.setCodec(code);  //设置输出流的字符格式
    sstream<<b;             //向文件流中输出内容
    file.close();
    //删除该联系人后搜索结果栏中的内容清空
    ClearText();
}
void SearchDialog::on_DeleteButton_clicked()
{
    DeleteMessenger();
}

void SearchDialog::ChangeMessenger(){
    QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))  //以只读模式打开文件
        QMessageBox::warning(this,"sdf","can't open!",QMessageBox::Yes);  //如果文件无法打开，弹出对话框
    QTextStream stream(&file);   //将文件中的内容存到流中
    stream.setCodec(code);  //设置流的字符格式
    QString mystring;    //存储要删除的联系人的信息
    mystring+=ui->NameEdit->text().toUtf8();
    mystring+=" ";
    mystring+=ui->PhoneEdit->text().toUtf8();
    mystring+=" ";
    mystring+=ui->CityEdit->text().toUtf8();

    QString newstring;   //存储新的联系人信息
    if(!ui->NamelineEdit->text().isEmpty())  //如果姓名信息需要修改
        newstring+=ui->NamelineEdit->text().toUtf8();
    else newstring+=ui->NameEdit->text().toUtf8();
    newstring+=" ";
    if(!ui->PhonelineEdit->text().isEmpty())  //如果姓名信息需要修改
        newstring+=ui->PhonelineEdit->text().toUtf8();
    else newstring+=ui->PhoneEdit->text().toUtf8();
    newstring+=" ";
    if(!ui->CitylineEdit->text().isEmpty())  //如果姓名信息需要修改
        newstring+=ui->CitylineEdit->text().toUtf8();
    else newstring+=ui->CityEdit->text().toUtf8();

    QString a;             //将从流中读取的内容存放在a中
    QString b;             //将文件中除了要删除的内容之外的信息存放在b中
    a+=stream.readAll();
    QStringList list1=a.split("\n");
    for(int i=0;i<list1.size();i++){
        if(list1[i]!=mystring)
            b+=list1[i];
        else  //到被修改的元素时
            b+=newstring;
        if(i!=list1.size()-1) b+="\n";
    }
    file.close();   //关闭文件之后才能对文件进行操作
    file.remove();
    file.setFileName("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");   //使file重新指向数据的文件
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))  //这次以写入模式打开文件
        QMessageBox::warning(this,"sdf","can't open!",QMessageBox::Yes);  //如果文件无法打开，弹出对话框
    QTextStream sstream(&file);
    sstream.setCodec(code);  //设置输出流的字符格式
    sstream<<b;             //向文件流中输出内容
    file.close();
    //删除该联系人后搜索结果栏中的内容清空
    ClearText();
}

void SearchDialog::on_ChangeButton_clicked()
{
    ChangeMessenger();
    this->close();
}
