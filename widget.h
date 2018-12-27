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
#include "groupdialog.h"
#include "infodialog.h"
namespace Ui {
class Widget;
}
const int  maxn=5;  //预设五个分组
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void Initgroup();
    static List head;
    static group group[maxn];   //建立maxn个分组
private slots:
    void on_AddButton_clicked();

    void on_DisplayButton_clicked();

    void on_SearchButton_clicked();

    void on_typepushButton_clicked();

    void on_infopushButton_clicked();

private:
    Ui::Widget *ui;
    AddDataDialog AddDialog;
    DisplayDialog DisDialog;
    SearchDialog SeaDialog;
    GroupDialog GroDialog;
    InfoDialog InfDialog;
};

#endif // WIDGET_H
