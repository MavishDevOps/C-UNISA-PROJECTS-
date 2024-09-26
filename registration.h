#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "person.h"
#include <QDate>
#include <QObject>


class Registration:public QObject//contains information for student or guest to register for

{
    Q_OBJECT
    Person m_Attendee;
    QDate m_BookingDate;
    double m_Fee;

public:
    Registration();
    virtual QString registrationType()const {return "Standard Registration";}//Metaobject pointer to registration
    double const STANDARD_FEE=1370.5;//The standard fee for this conference is R 1370.50 , this will be a static variable
    Registration(Person a);
    Registration(QString name, QString affiliation, QString email, QDate date, QString registrationType);
    double setFee(double fe){m_Fee=fe;}//setter for fee
    Person getAttendee() const {return m_Attendee;}
    QDate getBookingDate() const { return m_BookingDate;}//This getter method has been modified to allow user selected date from Qcalendar to be used
    virtual double calculateFee() const;//Calculates the fee a guest or student has to pay
    virtual QString toString();

};

#endif // REGISTRATION_H
