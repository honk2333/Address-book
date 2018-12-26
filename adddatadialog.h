#ifndef ADDDATADIALOG_H
#define ADDDATADIALOG_H

#include <QDialog>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
namespace Ui {
class AddDataDialog;
}

class AddDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDataDialog(QWidget *parent = nullptr);
    ~AddDataDialog();
    void ClearEdit();
    void AddMessenger();

private slots:
    void on_YesButton_clicked();

private:
    Ui::AddDataDialog *ui;
};

#endif // ADDDATADIALOG_H
