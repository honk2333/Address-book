#ifndef OUTPUTDIALOG_H
#define OUTPUTDIALOG_H

#include <QDialog>

namespace Ui {
class OutputDialog;
}

class OutputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OutputDialog(QWidget *parent = nullptr);
    ~OutputDialog();
    void Outputmyadressbook();
private slots:
    void on_pushButton_clicked();

private:
    Ui::OutputDialog *ui;
};

#endif // OUTPUTDIALOG_H
