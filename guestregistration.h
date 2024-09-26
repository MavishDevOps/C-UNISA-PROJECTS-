#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H
#include "registration.h"

class GuestRegistration:public Registration
{

    QString m_Category;
public:
    GuestRegistration();
       GuestRegistration(QString name, QString affiliation, QString email, QDate date, QString registrationType);
    QString registrationType() const override{return "Guest";}
    GuestRegistration(Person a,QString c);
    double  calculateFee() const;
    QString toString()const;
};

#endif // GUESTREGISTRATION_H
