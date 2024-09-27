#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include <QString>
#include "registrationlist.h"
#include "person.h"
#include <QFileDialog>
#include <QObject>


class RegistrationList;

class RegistrationList;

class RegistrationListWriter: public QObject {
    Q_OBJECT

    QList<Registration*> m_AttendeeList;
    Person *registrant = new Person("Robyn Banks", "Bank manager ", "robbank@barclays.co.za");

public:
    RegistrationListWriter();
    QDomDocument doc;
    void writeRegistrationList();

};



#endif // REGISTRATIONLISTWRITER_H
