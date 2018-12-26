#ifndef DISPLAYDIALOG_H
#define DISPLAYDIALOG_H

#include <QDialog>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QAction>
#include "adddatadialog.h"
#include "changedialog.h"
#include "searchdialog.h"
#include <QMenu>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QtDebug>

namespace Ui {
class DisplayDialog;
}

class DisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayDialog(QWidget *parent = nullptr);
    ~DisplayDialog();
    void showMessage();

private slots:
    void showContextMenuSlot(const QPoint& pos);  //显示右键菜单的槽函数
    void addItemSlot();          //添加联系人的槽函数
    void delItemSlot();          //删除联系人的槽函数
    void chaItemSlot();          //修改联系人信息的槽函数
    void on_listWidget_doubleClicked(const QModelIndex &index);

signals:
    void SentdataSignal(int data);
private:
    Ui::DisplayDialog *ui;
    AddDataDialog AddDialog;    //新建联系人的子窗口
    SearchDialog SeaDialog;     //显示联系人详细信息的窗口
    ChangeDialog *ChaDialog;     //修改联系人的子窗口
    QListWidgetItem* SelectedItem;    //鼠标所指条目
    int pos_row;             //记录鼠标所指条目是第几行的条目便于进行修改和删除操作
    //菜单控件
    QMenu *Menu;
    QAction *AddAction;
    QAction *DelAction;
    QAction *ChaAction;    //修改信息的action
};

#endif // DISPLAYDIALOG_H
