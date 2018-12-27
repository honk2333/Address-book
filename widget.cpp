#include "widget.h"
#include "ui_widget.h"
#include "person.h"

List Widget::head;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ReadFile();  //从文件中读取信息
}

Widget::~Widget()
{
    delete ui;
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
