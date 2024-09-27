#ifndef STUDENTTREGISTRATION_H
#define STUDENTTREGISTRATION_H
#include "registration.h"

class StudentRegistration:public Registration
{
    QString m_Qualification;

public:
    StudentRegistration();
    QString registrationType()const override {return "Student";}
    StudentRegistration(QString name, QString affiliation, QString email, QDate date, QString registrationType);
    StudentRegistration(Person a, QString q);
    double   calculateFee() const;// This is an inherited function which will calculate the fees the student pays i.e half  the standard fee which may be calculated as R137.5*0.5=R68.75
    QString toString() const;
};

#endif // STUDENTTREGISTRATION_H
