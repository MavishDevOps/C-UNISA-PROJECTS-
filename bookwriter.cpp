#include "bookwriter.h"

BookWriter::BookWriter() {}
void BookWriter::writeBook(const Book &book, const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        const QMetaObject *metaObject = book.metaObject();
        for (int i = 0; i < metaObject->propertyCount(); ++i) {
            QMetaProperty property = metaObject->property(i);
            QString propertyName = property.name();
            QVariant value = book.property(propertyName.toUtf8());
            out << propertyName << ": " << value.toString() << "\n";
        }
        out << "-------------------------\n";
        file.close();
    }
}


