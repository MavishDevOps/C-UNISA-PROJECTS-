#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"
#include <QList>
#include <QString>
#include <QMetaObject>

class RegistrationList
{
     QList<Registration*>m_AttendeeList;//used again for doing the views
public:
    RegistrationList();
    bool addRegistration(Registration*r);
    ~RegistrationList();
    bool isRegistered(QString n);
    double totalFee(QString t);
    int totalRegistrations(QString a);
};

#endif // REGISTRATIONLIST_H
