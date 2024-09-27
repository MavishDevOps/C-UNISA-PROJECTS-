#include "registration.h"
Registration::Registration(){}
Registration::Registration(Person a):m_Attendee(a){}//instantiation of default constructor
Registration::Registration(QString name, QString affiliation, QString email, QDate date, QString registrationType) {

    m_Attendee.setName(name);
    m_Attendee.setAffiliation(affiliation);
    m_Attendee.setEmail(email);

    m_BookingDate = date;

    registrationType=registrationType;


}


double Registration::calculateFee() const
{
    double fee=STANDARD_FEE;
    return fee;
}


QString Registration::toString(){
    return"";
}
