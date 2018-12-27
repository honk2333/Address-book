#include "infodialog.h"
#include "ui_infodialog.h"
#include "widget.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}
int InfoDialog::Cmptime(QString a,QString b){
    QStringList l1=a.split(".");
    QStringList l2=b.split(".");
    //比较年份
    if(l1[0]<l2[0]) return -1;
    if(l1[0]>l2[0]) return 1;
    if(l1[0]==l2[0]){
        //月份相同就比月份
        if(l1[1]<l2[1]) return -1;
        if(l1[1]>l2[1]) return 1;
        if(l1[1]==l1[1]) {
            if(l1[2]<l2[2]) return -1;
            if(l1[2]>l2[2]) return 1;
            if(l1[2]==l1[2]) return 0;
        }
    }
    return 0;
}
bool InfoDialog::Judge(person* p){
    if(!ui->CityEdit->text().isEmpty()){
        if(ui->CityEdit->text()!=p->city) return false;
    }
    if(!ui->TypeEdit->text().isEmpty()){
        if(ui->TypeEdit->text()!=p->type) return false;
    }
    if(!ui->BeginTimeEdit->text().isEmpty()){
        if(Cmptime(ui->BeginTimeEdit->text(),p->Time)==1) return false;
    }
    if(!ui->EndTimeEdit->text().isEmpty()){
        if(Cmptime(ui->EndTimeEdit->text(),p->Time)==-1) return false;
    }
    return true;
}
void InfoDialog::InfoMessenger(){   //根据Linetext中的信息查找联系人
    if(!ui->EndTimeEdit->text().isEmpty()&&!ui->BeginTimeEdit->text().isEmpty()){
        if(Cmptime(ui->EndTimeEdit->text(),ui->BeginTimeEdit->text())==-1)
             QMessageBox::warning(this,"ERROR","时间设置错误!",QMessageBox::Yes);  //如果开始时间比结束时间晚就弹出对话框
    }
    int num=0;
    List p=Widget::head->next;
    while(p){
        if(Judge(p)) {
            num++;
            ui->listWidget->addItem(p->name);
        }
        p=p->next;
    }
    QString n=QString::number(num,10);  //将整型数字转换成字符串型
    ui->NumlineEdit->setText(QString(n));
}

void InfoDialog::on_InfoButton_clicked()
{
    ui->NumlineEdit->clear();
    ui->listWidget->clear();
    InfoMessenger();
}
