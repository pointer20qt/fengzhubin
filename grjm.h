#ifndef GRJM_H
#define GRJM_H

#include <QWidget>

namespace Ui {
class grjm;
}

class grjm : public QWidget
{
    Q_OBJECT

public:
    explicit grjm(QWidget *parent = 0);
    ~grjm();
    void init(QString sno,QString sname);

private:
    Ui::grjm *ui;
};

#endif // GRJM_H
