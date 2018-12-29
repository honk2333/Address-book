#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "person.h"
namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();
    void ClearText();
    List FindMessenger();
    List FindNextMessenger();
    void FindMessenger(int pos);   //显示第pos行的联系人的详细信息，与上面的FindMessenger()构成重载函数
    void DeleteMessenger();
    void ChangeMessenger();
private slots:
    void on_FindButton_clicked();

    void on_DeleteButton_clicked();

    void on_ChangeButton_clicked();

    void on_FindNextButton_clicked();

private:
    Ui::SearchDialog *ui;
    List L;
};

#endif // SEARCHDIALOG_H
