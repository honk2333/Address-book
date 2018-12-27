#include "person.h"
#include "widget.h"

void ReadFile(){
    //从文件中读取信息
    ElemType *p1=nullptr,*p2=nullptr;
    Widget::head=new ElemType;  //为头指针申请空间建立头节点
    QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) return ;
    QTextStream stream(&file);
    stream.setCodec(code);  //设置输出流的字符格式
    QString Name;
    QString City;
    QString Phone;
    QString Email;
    QString Type;
    QString Time;
    bool tag=true;   //第一次读入文件
    while(!stream.atEnd()){  //当文件不为空
        stream>>Name>>Phone>>City>>Email>>Type>>Time;
        //p2=(person*)malloc(sizeof(ElemType));
        p2=new ElemType;
        *p2=person(Name,Phone,City,Email,Type,Time);//用构造函数给新申请的节点赋值
        p2->next=nullptr;   //最后一个节点的指针域置空
        if(tag){
            Widget::head->next=p2;  //设置第一个节点
            p1=p2;
            tag=false;
        }
        else{
            p1->next=p2;
            p1=p2;
        }
        //qDebug()<<p2->name<<p2->city<<p2->phone;
    }
    //最后一个换行符之后也占用了一个节点，会造成输出空行的情况
    p1=Widget::head;
    while(p1->next!=p2){
        p1=p1->next;
    }
    p1->next=nullptr;
    delete(p2);  //将换行符占用的空节点释放掉
    file.close();  //关闭文件
}
void SaveFile(){
    //向文件中存入信息
    ElemType *p=Widget::head->next;
    QTextCodec* code=QTextCodec::codecForName("utf8");
    QFile file("C:/Users/honk/Desktop/Qt/MyAddressBook/Messenger.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)) return ;
    QTextStream stream(&file);
    stream.setCodec(code);  //设置输出流的字符格式
    while(p){
        stream<<p->name<<" "<<p->phone<<" "<<p->city<<" "<<p->type<<" "<<p->email<<" "<<p->Time<<"\n";
        p=p->next;
    }
    file.close();
}
