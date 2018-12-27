#ifndef INFODIALOG_H
#define INFODIALOG_H
#include "person.h"
#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();
    void InfoMessenger();
    int Cmptime(QString a,QString b);
    bool Judge(person* p);
private slots:
    void on_InfoButton_clicked();

private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
