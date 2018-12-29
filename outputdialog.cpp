#include "outputdialog.h"
#include "ui_outputdialog.h"
#include "widget.h"

OutputDialog::OutputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutputDialog)
{
    ui->setupUi(this);
}

OutputDialog::~OutputDialog()
{
    delete ui;
}
void OutputDialog::Outputmyadressbook(){
    //导出通讯录
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::warning(this,"ERROR","请输入文件名!",QMessageBox::Yes);
    }
    QString FileName=ui->lineEdit->text();   //获取用户输入的文件名
    ElemType *p=Widget::head->next;
    QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/"+FileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
        QMessageBox::warning(this,"ERROR","this file can't open!",QMessageBox::Yes);  //如果文件无法打开，弹出对话框
    QTextStream stream(&file);
    stream.setCodec(code);  //设置输出流的字符格式
    while(p){
        stream<<p->name<<" "<<p->phone<<" "<<p->city<<" "<<p->type<<" "<<p->email<<" "<<p->Time<<"\n";
        p=p->next;
    }
    file.close();
}
void OutputDialog::on_pushButton_clicked()
{
    Outputmyadressbook();
    this->close();
}
