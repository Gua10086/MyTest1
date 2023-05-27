#ifndef MYDIALOG1_H
#define MYDIALOG1_H

#include <QDialog>

namespace Ui {
class MyDialog1;
}

class MyDialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog1(QWidget *parent = nullptr);
    ~MyDialog1();
    void setPicture1();
    void MakeChoice();

private slots:

    void on_NexSenBtn_clicked();
    void on_BtnC1_clicked();
    void on_BtnC2_clicked();
    void on_BtnC3_clicked();

private:
    Ui::MyDialog1 *ui;
};

#endif // MYDIALOG1_H
