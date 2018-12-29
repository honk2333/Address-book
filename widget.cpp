#include "widget.h"
#include "ui_widget.h"
#include "person.h"

//全局变量
List Widget::head;
group Widget::group[];

//主界面
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Initgroup();
    ReadFile();  //从文件中读取信息
}

Widget::~Widget()
{
    delete ui;
}
void Widget::Initgroup(){
    for(int i=0;i<maxn;i++){
        group[i].num=0;    //初始时联系人数目为0
    }
    //分组名称初始化；
    group[0].groupname="亲人";
    group[1].groupname="朋友";
    group[2].groupname="同学";
    group[3].groupname="同事";
    group[4].groupname="其他";

}
void Widget::on_AddButton_clicked()
{
    AddDialog.ClearEdit();
    AddDialog.show();
}

void Widget::on_DisplayButton_clicked()
{
    DisDialog.showMessage();
    DisDialog.show();
}

void Widget::on_SearchButton_clicked()
{
    SeaDialog.ClearText();
    SeaDialog.show();
}

void Widget::on_typepushButton_clicked()
{
    GroDialog.showgroup();
    GroDialog.show();
}

void Widget::on_infopushButton_clicked()
{
    InfDialog.show();
}

void Widget::on_OutputButton_clicked()
{
    OutDialog.show();
}
