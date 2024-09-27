#include "bookwriter.h"

BookWriter::BookWriter() {}

void BookWriter::writeBook(const Book &book, const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Title: " << book.getTitle() << "\n";
        out << "Authors: " << book.getAuthors().join(", ") << "\n";
        out << "ISBN: " << book.getIsbn() << "\n";
        out << "Publication Date: " << book.getPublicationDate().toString() << "\n";
        out << "-------------------------\n";
        file.close();
    }
}

