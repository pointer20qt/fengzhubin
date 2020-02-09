#ifndef REG_A_H
#define REG_A_H

#include <QWidget>

namespace Ui {
class reg_a;
}

class reg_a : public QWidget
{
    Q_OBJECT

public:
    explicit reg_a(QWidget *parent = 0);
    ~reg_a();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::reg_a *ui;
};

#endif // REG_A_H
