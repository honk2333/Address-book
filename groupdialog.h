#ifndef GROUPDIALOG_H
#define GROUPDIALOG_H

#include <QDialog>
#include "displaydialog.h"
namespace Ui {
class GroupDialog;
}

class GroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupDialog(QWidget *parent = nullptr);
    ~GroupDialog();
    void showgroup();

private slots:
    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::GroupDialog *ui;
    DisplayDialog DisDialog;
};

#endif // GROUPDIALOG_H
