#include "bookinput.h"

BookInput::BookInput(QWidget *parent) : QDialog(parent), book(new Book(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    titleEdit = new QLineEdit(this);
    authorEdit = new QLineEdit(this);
    isbnEdit = new QLineEdit(this);
    publicationDateEdit = new QDateEdit(this);
    saveBookButton = new QPushButton("Save Book", this);
    viewBookButton = new QPushButton("View Book", this);

    layout->addWidget(new QLabel("Title:", this));
    layout->addWidget(titleEdit);
    layout->addWidget(new QLabel("Author:", this));
    layout->addWidget(authorEdit);
    layout->addWidget(new QLabel("ISBN:", this));
    layout->addWidget(isbnEdit);
    layout->addWidget(new QLabel("Publication Date:", this));
    layout->addWidget(publicationDateEdit);
    layout->addWidget(saveBookButton);
    layout->addWidget(viewBookButton);

    connect(saveBookButton, &QPushButton::clicked, this, &BookInput::onSaveClicked);
    connect(viewBookButton, &QPushButton::clicked, this, &BookInput::onViewClicked);
}

Book* BookInput::obtainBookInfo() const
{
    book->setTitle(titleEdit->text());
    book->setAuthor(authorEdit->text());
    book->setIsbn(isbnEdit->text());
    book->setPublicationDate(publicationDateEdit->date());
    return book;
}

void BookInput::onSaveClicked()
{
    obtainBookInfo();
    QString fileName = QFileDialog::getSaveFileName(this, "Save Book", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        write.writeBook(*book, fileName);
        QMessageBox::information(this, "Success", "Book saved successfully!");
    }
}

void BookInput::onViewClicked()
{
    const QMetaObject *metaObject = book->metaObject();
    QString info;
    for (int i = 0; i < metaObject->propertyCount(); ++i) {
        QMetaProperty property = metaObject->property(i);
        QString propertyName = property.name();
        QVariant value = book->property(property.name());
        info += propertyName + ": " + value.toString() + "\n";
    }
    QMessageBox::information(this, "Book Info", info);
}
