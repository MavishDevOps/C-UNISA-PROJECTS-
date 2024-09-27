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

class BookInput : public QDialog
{
    Q_OBJECT

public:
    explicit BookInput(QWidget *parent = nullptr);
    Book* obtainBookInfo() const;

private slots:
    void onSaveClicked();
    void onViewClicked();

private:
    QLineEdit *titleEdit, *authorEdit, *isbnEdit;
    QDateEdit *publicationDateEdit;
    QPushButton *saveBookButton, *viewBookButton;
    Book *book;
    BookWriter write;
};

#endif // BOOKINPUT_H
