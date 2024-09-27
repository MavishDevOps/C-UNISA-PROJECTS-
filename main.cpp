#include "widget.h"
#include"passwordcheck.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    PasswordCheck validate;
    validate.show();
    w.show();
    return a.exec();
}
