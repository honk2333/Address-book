#include "searchdialog.h"
#include "ui_searchdialog.h"
#include "widget.h"
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
void SearchDialog::ClearText(){    //先将输入栏中的信息清空
    ui->NameEdit->clear();
    ui->PhoneEdit->clear();
    ui->CityEdit->clear();
    ui->TypeEdit->clear();
    ui->EmailEdit->clear();
    ui->TimeEdit->clear();
    ui->NamelineEdit->clear();
    ui->PhonelineEdit->clear();
    ui->CitylineEdit->clear();
    ui->TypelineEdit->clear();
    ui->EmaillineEdit->clear();
    ui->TimelineEdit->clear();
}

void SearchDialog::FindMessenger(){   //根据Linetext中的信息查找联系人
    /*QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) return ;
    QTextStream stream(&file);
    stream.setCodec(code);  //设置输出流的字符格式

    QString a;
    a+=stream.readAll();
    QStringList list1=a.split("\n");
    int i=0;
    for(i=0;i<list1.size()-1;i++){
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
   if(i>=list1.size()-1) {  //如果未查找到联系人
   QMessageBox::warning(this,"result","找不到符合信息的联系人!",QMessageBox::Yes);  //如果找不到符合信息的联系人就弹出对话框
   }
    file.close();                 //关闭文件
   */
    List p=Widget::head->next;
    while(p){
        if(!ui->PhoneEdit->text().isEmpty()&&ui->PhoneEdit->text()==p->phone){
            ui->NameEdit->setText(p->name);
            ui->PhoneEdit->setText(p->phone);
            ui->CityEdit->setText(p->city);
            ui->TypeEdit->setText(p->type);
            ui->EmailEdit->setText(p->email);
            ui->TimeEdit->setText(p->Time);
            break;                //找到第一个符合要求的联系人即退出
        }
        if(!ui->CityEdit->text().isEmpty()&&ui->CityEdit->text()==p->city){
            ui->NameEdit->setText(p->name);
            ui->PhoneEdit->setText(p->phone);
            ui->CityEdit->setText(p->city);
            ui->TypeEdit->setText(p->type);
            ui->EmailEdit->setText(p->email);
            ui->TimeEdit->setText(p->Time);
            break;
        }
        if(!ui->NameEdit->text().isEmpty()&&ui->NameEdit->text()==p->name){
            ui->NameEdit->setText(p->name);
            ui->PhoneEdit->setText(p->phone);
            ui->CityEdit->setText(p->city);
            ui->TypeEdit->setText(p->type);
            ui->EmailEdit->setText(p->email);
            ui->TimeEdit->setText(p->Time);
            break;
        }
        if(!ui->TypeEdit->text().isEmpty()&&ui->TypeEdit->text()==p->type){
            ui->NameEdit->setText(p->name);
            ui->PhoneEdit->setText(p->phone);
            ui->CityEdit->setText(p->city);
            ui->TypeEdit->setText(p->type);
            ui->EmailEdit->setText(p->email);
            ui->TimeEdit->setText(p->Time);
            break;
        }
        if(!ui->EmailEdit->text().isEmpty()&&ui->EmailEdit->text()==p->email){
            ui->NameEdit->setText(p->name);
            ui->PhoneEdit->setText(p->phone);
            ui->CityEdit->setText(p->city);
            ui->TypeEdit->setText(p->type);
            ui->EmailEdit->setText(p->email);
            ui->TimeEdit->setText(p->Time);
            break;
        }
        if(!ui->TimeEdit->text().isEmpty()&&ui->TimeEdit->text()==p->Time){
            ui->NameEdit->setText(p->name);
            ui->PhoneEdit->setText(p->phone);
            ui->CityEdit->setText(p->city);
            ui->TypeEdit->setText(p->type);
            ui->EmailEdit->setText(p->email);
            ui->TimeEdit->setText(p->Time);
            break;
        }
        p=p->next;
    }
    if(p==nullptr) {  //如果未查找到联系人
        QMessageBox::warning(this,"result","找不到符合信息的联系人!",QMessageBox::Yes);  //如果找不到符合信息的联系人就弹出对话框
    }
}
void SearchDialog::FindMessenger(int pos){   //根据联系人的位置输出联系人的信息，与上面的同名函数重载
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
    ui->TypeEdit->setText(list2[3]);
    ui->EmailEdit->setText(list2[4]);
    ui->TimeEdit->setText(list2[5]);
    file.close();                 //关闭文件
}

void SearchDialog::on_FindButton_clicked()
{
    FindMessenger();
}

void SearchDialog::DeleteMessenger(){
    /*QTextCodec* code=QTextCodec::codecForName("utf8");
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
        QMessageBox::warning(this,"错误","文件无法打开!",QMessageBox::Yes);  //如果文件无法打开，弹出对话框
    QTextStream sstream(&file);
    sstream.setCodec(code);  //设置输出流的字符格式
    sstream<<b;             //向文件流中输出内容
    file.close();
    //删除该联系人后搜索结果栏中的内容清空
    ClearText();*/

    List p=Widget::head->next,pp=Widget::head;
    while(p){
        if(ui->PhoneEdit->text()==p->phone&&ui->NameEdit->text()==p->name&&ui->CityEdit->text()==p->city&&ui->TypeEdit->text()==p->type&&ui->EmailEdit->text()==p->email&&ui->TimeEdit->text()==p->Time){
            break;
        }
        else {
            pp=p;
            p=p->next;
        }
    }
    if(p==nullptr) {  //如果未查找到联系人
        QMessageBox::warning(this,"result","找不到符合信息的联系人!",QMessageBox::Yes);  //如果找不到符合信息的联系人就弹出对话框
    }
    List tmp=p;
    pp->next=tmp->next;
    free(tmp);
    //删除该联系人后搜索结果栏中的内容清空
    ClearText();
}
void SearchDialog::on_DeleteButton_clicked()
{
    DeleteMessenger();
    this->close();
}

void SearchDialog::ChangeMessenger(){   //修改联系人的信息
    /*QTextCodec* code=QTextCodec::codecForName("utf8");
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
    */
    List p=Widget::head->next;
    while(p){
        if(ui->PhoneEdit->text()==p->phone&&ui->NameEdit->text()==p->name&&ui->CityEdit->text()==p->city&&ui->TypeEdit->text()==p->type&&ui->EmailEdit->text()==p->email&&ui->TimeEdit->text()==p->Time){
            break;
        }
        else p=p->next;
    }
    if(p==nullptr) {  //如果未查找到联系人
        QMessageBox::warning(this,"result","找不到符合信息的联系人!",QMessageBox::Yes);  //如果找不到符合信息的联系人就弹出对话框
    }
    if(!ui->NamelineEdit->text().isEmpty())  //如果姓名信息需要修改
        p->name=ui->NamelineEdit->text().toUtf8();
    if(!ui->PhonelineEdit->text().isEmpty())  //如果电话信息需要修改
        p->phone=ui->PhonelineEdit->text().toUtf8();
    if(!ui->CitylineEdit->text().isEmpty())  //如果地址信息需要修改
        p->city=ui->CitylineEdit->text().toUtf8();
    if(!ui->TypelineEdit->text().isEmpty())  //如果分组信息需要修改
        p->type=ui->TypelineEdit->text().toUtf8();
    if(!ui->EmaillineEdit->text().isEmpty())  //如果邮箱信息需要修改
        p->email=ui->EmaillineEdit->text().toUtf8();
    if(!ui->TimelineEdit->text().isEmpty())  //如果地址信息需要修改
        p->Time=ui->TimelineEdit->text().toUtf8();
    SaveFile();
}

void SearchDialog::on_ChangeButton_clicked()
{
    ChangeMessenger();
    this->close();   //改变信息后关闭该对话框
}
