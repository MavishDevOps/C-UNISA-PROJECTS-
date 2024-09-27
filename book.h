#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QDate>
#include <QStringList>
class Book
{
  //members private by default in c++
    QString title,isbn;
      QStringList authors;
    QDate publicationDate;


public:
    Book();
    Book(QString t,QStringList a,QString i,QDate p);
    void setTitle(QString t){t=title;}
    void setAuthors(QStringList a){a=authors;}
    void setIsbn(QString i){i=isbn;}
    void setPublicationDate(QDate p){p=publicationDate;}
    QString getTitle()const {return title;}
    QStringList getAuthors()const {return authors;}
    QString getIsbn()const {return isbn;}
    QDate getPublicationDate() const {return publicationDate;}

    void saveBook(Book & b);//BookWriter uses this to save book information to text file
};

#endif // BOOK_H
