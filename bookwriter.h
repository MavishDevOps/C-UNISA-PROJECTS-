#ifndef BOOKWRITER_H
#define BOOKWRITER_H
#include "book.h"
#include <QFile>
#include <QTextStream>
class BookWriter
{
public:
    BookWriter();
    static void writeBook(const Book &book,const QString &fileName="books.txt");
};

#endif // BOOKWRITER_H
