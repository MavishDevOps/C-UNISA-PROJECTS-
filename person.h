#ifndef PERSON_H
#define PERSON_H

#include <QString>
class Person
{    //by default in C++, all attributes are private
    QString m_Name, m_Affiliation, m_Email;
public:
    Person();
    Person(QString n, QString a, QString e);
    QString setName(QString nam){m_Name=nam;}
    QString getName() const { return m_Name; }
    QString setAffiliation(QString aff){m_Affiliation=aff;}
    QString getAffiliation() const { return m_Affiliation; }
    QString setEmail(QString em){m_Email=em;}
    QString getEmail() const { return m_Email; }
    QString toString();

};


#endif // PERSON_H
