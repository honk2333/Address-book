#include "groupdialog.h"
#include "ui_groupdialog.h"
#include "widget.h"

GroupDialog::GroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupDialog)
{
    ui->setupUi(this);
}

GroupDialog::~GroupDialog()
{
    delete ui;
}

void GroupDialog::showgroup(){
    ui->listWidget->clear();   //先清空画布
    /*  QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) return ;
    QTextStream stream(&file);
    stream.setCodec(code);  //设置输出流的字符格式
    QString a;
    a+=stream.readAll();  //将流中的全部内容存入a中
    file.close();
    QStringList list1=a.split("\n");  //以换行符来分隔不同联系人的信息
    for(int i=0;i<list1.size();i++){  //对于每个联系人的操作
        QStringList list2=list1[i].split(" ");  //用空格来分割同个联系人的不同信息
        ui->listWidget->addItem(list2[0]);
    }*/
    for(int i=0;i<maxn;i++){
        ui->listWidget->addItem(Widget::group[i].groupname);   //将组名添加到画布中
    }
}

void GroupDialog::on_listWidget_doubleClicked(const QModelIndex &index)  //双击分组名弹出列表
{
    DisDialog.showMessage(index.row());
    DisDialog.show();
}
