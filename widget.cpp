#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
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
