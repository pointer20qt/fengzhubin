#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include "widget.h"
#include "reg_a.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{

    ui->setupUi(this);
    this->setWindowTitle("宁要签到？");
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("qta");
    db.setUserName("root");
    db.setPassword("123456");

    if(db.open())
    {
        qDebug()<< "打开成功" ;
    }
    else
        {
        qDebug() << "打开失败" ;
    }
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString sname=ui->lineEdit->text();
    QString pwd=ui->lineEdit_2->text();
    QSqlQuery q;
    q.exec(QString("select * from ssign where sname='%1'").arg(sname));
    if(q.size()>0)
    {
        q.exec(QString("select * from ssign where sname='%1' and pwd='%2'").arg(sname).arg(pwd));
        if(q.size()>0)
        {
            Widget *w =new Widget(NULL,sname);
            w->sname =sname;
            w->show();
            this->close();
        }
        else
        {
            QMessageBox::warning(this,"warning","密码错了傻逼");
        }
    }
    else
    {
        QMessageBox::warning(this,"warning","操你妈用户不存在");
    }
}

void login::on_pushButton_2_clicked()
{
    reg_a *rea= new reg_a();
    rea->show();


}
