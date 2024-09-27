#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QString>
#include <QDate>

class Book : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(QString isbn READ isbn WRITE setIsbn NOTIFY isbnChanged)
    Q_PROPERTY(QDate publicationDate READ publicationDate WRITE setPublicationDate NOTIFY publicationDateChanged)

public:
    explicit Book(QObject *parent = nullptr);

    QString title() const;
    void setTitle(const QString &title);

    QString author() const;
    void setAuthor(const QString &author);

    QString isbn() const;
    void setIsbn(const QString &isbn);

    QDate publicationDate() const;
    void setPublicationDate(const QDate &publicationDate);

signals:
    void titleChanged();
    void authorChanged();
    void isbnChanged();
    void publicationDateChanged();

private:
    QString m_title;
    QString m_author;
    QString m_isbn;
    QDate m_publicationDate;
};

#endif // BOOK_H
