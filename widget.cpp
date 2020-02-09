#include "widget.h"
#include "ui_widget.h"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlQuery>
#include <QCheckBox>
#include <QDatetime>
#include <QString>
#include <QMessageBox>
#include "grjm.h"
Widget::Widget(QWidget *parent ,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("宁配吗中学签到系统");
    datatotable("select * from ssign");
    displayclass();
    displaysno();
    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c){
        grjm* p =new grjm();
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());
        p->show();
    });

    this->sname=sname;
}
void Widget::displaysno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){

        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warning","操你妈，输歪来");
        }
        else
        {
            datatotable(QString("select * from ssign where sno = '%1'").arg(ui->lineEdit->text()));
        }
    });


}

void Widget::displayclass()
{
    QSqlQuery q4;
    q4.exec("select distinct class from ssign");
    ui->comboBox->addItem("全部班级");
    while(q4.next())
    {
        ui->comboBox->addItem(q4.value(0).toString());
    }
    connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
        if(text=="全部班级")
        {
            datatotable("select * from ssign");
        }
        else
        {
             datatotable(QString("select * from ssign where class='%1'").arg(text));
        }
    });
}

void Widget::datatotable(QString sql)
{
    QSqlQuery q;
    q.exec(QString("select sno from ssign where sname ='%1'").arg(this->sname));
    q.next();
    QString cursno=q.value(0).toString();


    if(q.exec(sql))
    {
        ui->tableWidget->setRowCount(q.size());
        int i=0;
        while(q.next())
        {
           QCheckBox *c= new QCheckBox("未签到");
           QString sno =q.value(0).toString();
           QSqlQuery q3;
           q3.exec(QString("select signtime from sssign "
                           "where sno = %1 and date(signtime) = curdate() "
                           "order by signtime desc").arg(sno));
           q3.next();
           if(sno!=cursno)
           {
               c->setDisabled(true);
           }
           if(q3.size())
           {
               c->setText("已签到");
               c->setDisabled(true);
               c->setChecked(true);
               ui->tableWidget->setItem(i,4,new QTableWidgetItem(q3.value(0).toString()));
           }



           ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
           ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));
           ui->tableWidget->setCellWidget(i,3,c);


           connect(c,QCheckBox::clicked,[=](){
               c->setText("已签到");
               c->setDisabled(true);
               ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
               QSqlQuery q1;
               q1.exec(QString("insert into sssign values(%1,now())").arg(sno));
           });
           i++;



        }
    }

}


Widget::~Widget()
{
    delete ui;
}
