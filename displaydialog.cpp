#include "displaydialog.h"
#include "ui_displaydialog.h"
#include "widget.h"

DisplayDialog::DisplayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayDialog)
{
    ui->setupUi(this);
    ChaDialog=new ChangeDialog();
    AddAction = new QAction(QString::fromUtf8("新增"), this);
    DelAction = new QAction(QString::fromUtf8("删除"), this);
    ChaAction = new QAction(QString::fromUtf8("修改"), this);
    connect(AddAction, SIGNAL(triggered()), this, SLOT(addItemSlot()));
    connect(DelAction, SIGNAL(triggered()), this, SLOT(delItemSlot()));
    connect(ChaAction, SIGNAL(triggered()), this, SLOT(chaItemSlot()));
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenuSlot(const QPoint&)));
}

DisplayDialog::~DisplayDialog()
{
    delete ui;
}

void DisplayDialog::showMessage(){
    ui->listWidget->clear();
    /*  QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) return ;
    QTextStream stream(&file);
    stream.setCodec(code);  //设置输出流的字符格式
    QString a;
    a+=stream.readAll();  //将流中的全部内容存入a中
    file.close();
    QStringList list1=a.split("\n");  //以换行符来分隔不同联系人的信息
    for(int i=0;i<list1.size();i++){  //对于每个联系人的操作
        QStringList list2=list1[i].split(" ");  //用空格来分割同个联系人的不同信息
        ui->listWidget->addItem(list2[0]);
    }*/

    List p=Widget::head->next;
    while(p!=nullptr){
        ui->listWidget->addItem(p->name);
        p=p->next;
    }
}
void DisplayDialog::showMessage(int groupindex){
    ui->listWidget->clear();
    List p=Widget::head->next;
    while(p!=nullptr){
        if(p->type == Widget::group[groupindex].groupname)
            ui->listWidget->addItem(p->name);
        p=p->next;
    }
}
void DisplayDialog::addItemSlot(){      //添加联系人的槽函数
    AddDialog.ClearEdit();
    AddDialog.show();
    this->close();
}
void DisplayDialog::chaItemSlot(){   //修改联系人信息
    //emit SentdataSignal(pos_row);
    ChaDialog->receivedataslot(pos_row);
    ChaDialog->ClearEdit();
    ChaDialog->show();
    this->close();
}
void DisplayDialog::delItemSlot(){    //删除联系人
    /*QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))  //以只读模式打开文件
        QMessageBox::warning(this,"sdf","can't open!",QMessageBox::Yes);  //如果文件无法打开，弹出对话框
    QTextStream stream(&file);   //将文件中的内容存到流中
    stream.setCodec(code);  //设置流的字符格式

    QString a;             //将从流中读取的内容存放在a中
    QString b;             //将文件中除了要删除的内容之外的信息存放在b中
    a+=stream.readAll();
    QStringList list1=a.split("\n");
    for(int i=0;i<list1.size();i++){
        if(i!=pos_row) {   //不是要删除的联系人所在行，将该信息存储到b中
            b+=list1[i];
            if(i!=list1.size()-1) b+="\n";
        }
    }
    file.close();   //关闭文件之后才能对文件进行操作
    file.remove();   //删除原来的文件
    file.setFileName("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");   //使file重新指向数据的文件
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))  //这次以写入模式打开文件
        QMessageBox::warning(this,"sdf","can't open!",QMessageBox::Yes);  //如果文件无法打开，弹出对话框
    QTextStream sstream(&file);
    sstream.setCodec(code);  //设置输出流的字符格式
    sstream<<b;             //向文件流中输出内容
    file.close();*/
    int j=0;
    List p=Widget::head;
    while(p&&j<pos_row){
        j++;
        p=p->next;
    }
    List tmp=p->next;
    p->next=p->next->next;
    free(tmp);
    SaveFile();
    showMessage();
}

void DisplayDialog::showContextMenuSlot(const QPoint& pos)   //右键菜单槽函数
{
    Menu = new QMenu;    //菜单控件
    if (ui->listWidget->itemAt(pos))   //如果鼠标在条目上
    {
        //记录鼠标所指条目的信息
        SelectedItem = ui->listWidget->itemAt(pos);
        pos_row=ui->listWidget->row(SelectedItem);
        //生成菜单内容
        Menu->addAction(DelAction);
        Menu->addAction(ChaAction);
    }
    else   //若鼠标指在了空白处
    {
        Menu->addAction(AddAction);
    }
    Menu->exec(QCursor::pos());
}

void DisplayDialog::on_listWidget_doubleClicked(const QModelIndex &index)  //双击条目的槽函数
{
    SeaDialog.show();
    SeaDialog.FindMessenger(index.row());
    this->close();
}
