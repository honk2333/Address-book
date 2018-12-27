#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include "adddatadialog.h"   //登陆子窗口的头文件
#include "displaydialog.h"
#include "searchdialog.h"
#include "person.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    static List head;

private slots:
    void on_AddButton_clicked();

    void on_DisplayButton_clicked();

    void on_SearchButton_clicked();

private:
    Ui::Widget *ui;
    AddDataDialog AddDialog;
    DisplayDialog DisDialog;
    SearchDialog SeaDialog;
};

#endif // WIDGET_H
