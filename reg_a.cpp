#include "reg_a.h"
#include "ui_reg_a.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>

reg_a::reg_a(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reg_a)
{
    ui->setupUi(this);
    this->setWindowTitle("老子要签到");
}

reg_a::~reg_a()
{
    delete ui;
}

void reg_a::on_pushButton_clicked()
{
    this->close();
}

void reg_a::on_pushButton_2_clicked()
{
    QString sno=ui->lineEdit->text();
    QString sname=ui->lineEdit_2->text();
    QString cla=ui->lineEdit_3->text();
    QString pwd=ui->lineEdit_4->text();
    QSqlQuery q;
    q.exec(QString("select * from ssign where sno='%1'").arg(sno));
    if(q.size()>0)
    {
        QMessageBox::warning(this,"盗号狗司马","用户名已存在");
    }
    else
    {
         if(sno==NULL||sname==NULL||cla==NULL||pwd==NULL)
         {
             QMessageBox::warning(this,"????","脑瘫，瞅瞅有啥没写全");
         }
         else
         {
             q.exec(QString("insert into ssign values(%1,'%2','%3','%4')").arg(sno).arg(sname).arg(cla).arg(pwd));
             QMessageBox::warning(this,"注册成功","签到gkd");
         }

    }

}
