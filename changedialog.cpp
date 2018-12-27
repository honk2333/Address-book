#include "changedialog.h"
#include "ui_changedialog.h"
#include "widget.h"
ChangeDialog::ChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeDialog)
{
    ui->setupUi(this);
}

ChangeDialog::~ChangeDialog()
{
    delete ui;
}
void ChangeDialog::ClearEdit(){
    ui->NamelineEdit->clear();
    ui->PhonelineEdit->clear();
    ui->CitylineEdit->clear();
    ui->TypelineEdit->clear();
    ui->EmaillineEdit->clear();
    ui->TimelineEdit->clear();
}
void ChangeDialog::receivedataslot(int data){  //将传来的数据赋值给记录位置的变量
    pos_row=data;
}
void ChangeDialog::ChaMessenger(int pos){
    /*QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");  //文件
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) return ;  //若文件无法打开则返回

    QTextStream stream(&file);
    stream.setCodec(code);
    QString newstring;   //存取修改的信息

    QString a;             //将从流中读取的内容存放在a中
    QString b;             //将文件中除了要删除的内容之外的信息存放在b中
    a+=stream.readAll();
    QStringList list1=a.split("\n");
    int num=list1.size();
    for(int i=0;i<num;i++){
        if(i!=pos)    //不是要修改的元素
            b+=list1[i];
        else { //到被修改的元素时
            QStringList list2=list1[i].split(" ");   //将该联系人的各项信息分开
            if(!ui->NamelineEdit->text().isEmpty())  //如果姓名信息需要修改
                newstring+=ui->NamelineEdit->text().toUtf8();
            else newstring+=list2[0];
            newstring+=" ";
            if(!ui->PhonelineEdit->text().isEmpty())  //如果姓名信息需要修改
                newstring+=ui->PhonelineEdit->text().toUtf8();
            else newstring+=list2[1];
            newstring+=" ";
            if(!ui->CitylineEdit->text().isEmpty())  //如果姓名信息需要修改
                newstring+=ui->CitylineEdit->text().toUtf8();
            else newstring+=list2[2];
            b+=newstring;
        }
        if(i!=num-1) b+="\n";   //不是最后一个联系人就加换行符
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
    //删除该联系人后结果栏中的内容清空
    ClearEdit();
    */
    int j=0;
    List p=Widget::head->next;
    while(j<pos&&p){   //定位到要修改的联系人
        j++;
        p=p->next;
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

void ChangeDialog::on_ChangeButton_clicked()
{
    ChaMessenger(pos_row);
}
