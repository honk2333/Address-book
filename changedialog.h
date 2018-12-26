#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H

#include <QDialog>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtDebug>

namespace Ui {
class ChangeDialog;
}

class ChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeDialog(QWidget *parent = nullptr);
    ~ChangeDialog();
    void ClearEdit();
    void ChaMessenger(int pos);
    void receivedataslot(int data);
private slots:
    void on_ChangeButton_clicked();

private:
    Ui::ChangeDialog *ui;
    int pos_row;
};

#endif // CHANGEDIALOG_H
