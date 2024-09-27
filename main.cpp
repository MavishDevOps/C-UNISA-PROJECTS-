#include "widget.h"

#include <QApplication>
#include "bookinput.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    BookInput BookInput;
    BookInput.show();
    w.show();
    return a.exec();
}
