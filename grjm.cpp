#include "grjm.h"
#include "ui_grjm.h"
#include <QSqlQuery>
#include <QTextCharFormat>
#include <QDebug>
grjm::grjm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grjm)
{
    ui->setupUi(this);
}
void grjm::init(QString sno,QString sname)
{
    ui->label->setText("学号:"+sno);
    ui->label_2->setText("姓名:"+sname);
    QSqlQuery q;
    qDebug()<<q.exec(QString("select * from sssign"
           "where sno=%1 and date_format(signtime'%Y-%m')="
           "date_format(curdate(),'%Y-%m')").arg(sno));
    ui->label_3->setText("签到次数： "+ QString::number(q.size()));
    QTextCharFormat fuck;
    fuck.setForeground(Qt::white);
    fuck.setBackground(Qt::black);

    while(q.next())
    {
        ui->calendarWidget->setDateTextFormat(q.value(0).toDate(),fuck);
    }

}

grjm::~grjm()
{
    delete ui;
}
