#include "bookinput.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

BookInput::BookInput(QWidget *parent) : QDialog(parent) {
    setWindowTitle("COS3711 Book archive");

    QVBoxLayout *layout = new QVBoxLayout(this);

    // Book title input
    QLabel *titleLabel = new QLabel("Enter in the Book title:", this);
    layout->addWidget(titleLabel);
    titleEdit = new QLineEdit(this);
    layout->addWidget(titleEdit);

    // Book author input
    QLabel *authorLabel = new QLabel("Enter in the name of the author:", this);
    layout->addWidget(authorLabel);
    authorEdit = new QLineEdit(this);
    layout->addWidget(authorEdit);

    // ISBN number input
    QLabel *isbnLabel = new QLabel("Enter in the ISBN number of the book you are reading:", this);
    layout->addWidget(isbnLabel);
    isbnEdit = new QLineEdit(this);
    layout->addWidget(isbnEdit);

    // Publication date input
    QLabel *pubdateLabel = new QLabel("Enter in the publication date:", this);
    layout->addWidget(pubdateLabel);
    publicationDateEdit = new QDateEdit(QDate::currentDate(), this);
    publicationDateEdit->setCalendarPopup(true);
    layout->addWidget(publicationDateEdit);

    // Save Book information
    saveBookButton = new QPushButton("Save Book Information", this);
    connect(saveBookButton, &QPushButton::clicked, this, &BookInput::onSaveClicked);
    layout->addWidget(saveBookButton);

    // View Book information
    viewBookButton = new QPushButton("View Book Information", this);
    connect(viewBookButton, &QPushButton::clicked, this, &BookInput::onViewClicked);
    layout->addWidget(viewBookButton);
}

void BookInput::onSaveClicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save Book Information", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        Book book = obtainBookInfo();
        BookWriter::writeBook(book, fileName);
        QMessageBox::information(this, "Success", "Book information saved successfully.");
    }
}

void BookInput::onViewClicked() {
    QFile file("books.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        file.close();

        QMessageBox::information(this, "Book Information", content);
    } else {
        QMessageBox::warning(this, "Error", "Unable to open books.txt");
    }
}

Book BookInput::obtainBookInfo() const {
    QString title = titleEdit->text();
    QStringList authors = authorEdit->text().split(",");
    QString isbn = isbnEdit->text();
    QDate publicationDate = publicationDateEdit->date();

    return Book(title, authors, isbn, publicationDate);
}
