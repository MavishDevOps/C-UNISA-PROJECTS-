#include "widget.h"

#include <QApplication>
#include "book.h"
#include "bookinput.h"
#include "bookwriter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Book book;
    BookInput input;
    BookWriter readOut;
    if (input.exec()==QDialog::Accepted)
    {
        book=input.obtainBookInfo();
        //readout.writeBook(book)
    }

    w.show();
    return a.exec();
}
