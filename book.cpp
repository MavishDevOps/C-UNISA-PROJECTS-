#include "book.h"

Book::Book(QObject *parent) : QObject(parent)
{
}

QString Book::title() const
{
    return m_title;
}

void Book::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        emit titleChanged();
    }
}

QString Book::author() const
{
    return m_author;
}

void Book::setAuthor(const QString &author)
{
    if (m_author != author) {
        m_author = author;
        emit authorChanged();
    }
}

QString Book::isbn() const
{
    return m_isbn;
}

void Book::setIsbn(const QString &isbn)
{
    if (m_isbn != isbn) {
        m_isbn = isbn;
        emit isbnChanged();
    }
}

QDate Book::publicationDate() const
{
    return m_publicationDate;
}

void Book::setPublicationDate(const QDate &publicationDate)
{
    if (m_publicationDate != publicationDate) {
        m_publicationDate = publicationDate;
        emit publicationDateChanged();
    }
}
