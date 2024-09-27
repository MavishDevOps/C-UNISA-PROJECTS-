#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include "book.h"
#include "bookwriter.h"
#include <QDialog>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QLabel>
#include <QStringList>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>


// The purpose of this class is to input user information of a book a reader has recently read
class BookInput : public QDialog
{
    Q_OBJECT

    // All members in C++ are private by default
    QLineEdit *titleEdit, *authorEdit, *isbnEdit;
    QDateEdit *publicationDateEdit;
    QPushButton *saveBookButton,*viewBookButton;
    Book book;
    BookWriter write;

private slots:
    void onSaveClicked();
    void onViewClicked();

public:
    explicit BookInput(QWidget *parent = nullptr);
    Book obtainBookInfo() const; // BookInput uses this to receive input from users
};

#endif // BOOKINPUT_H
