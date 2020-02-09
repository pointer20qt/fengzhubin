#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0, QString sname=NULL);
    ~Widget();
    void datatotable(QString sql);
    void displayclass();
    void displaysno();
    QString sname;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
