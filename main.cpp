#include <QApplication>
#include "primenumgui.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PrimeNumGui window;
    window.show();

    return app.exec();
}
