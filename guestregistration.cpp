#include "guestregistration.h"

GuestRegistration::GuestRegistration() {}

GuestRegistration::GuestRegistration(QString name, QString affiliation, QString email, QDate date, QString registrationType):Registration(name,affiliation,email,date,registrationType){}

GuestRegistration::GuestRegistration(Person a, QString c):Registration(a),m_Category(c){}

double GuestRegistration::calculateFee()const
{
    return (0.1*STANDARD_FEE);
}

QString GuestRegistration::toString() const
{
    return "";

}
