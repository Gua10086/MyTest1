#include "mydialog.h"
#include "mydialog1.h"
#include <QApplication>
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>
using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyDialog1 *dlg = new MyDialog1();
    dlg->setPicture1();
    dlg->show();





    /*
    MyDialog w;
    w.show();
    */
    return a.exec();
}
