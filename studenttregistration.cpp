#include "studenttregistration.h"
StudentRegistration::StudentRegistration() {}

StudentRegistration::StudentRegistration(QString name, QString affiliation, QString email, QDate date, QString registrationType):Registration(name,affiliation,email,date,registrationType){}

StudentRegistration::StudentRegistration(Person a, QString q):Registration(a),m_Qualification(q){

}

double StudentRegistration::calculateFee()const
{
    return (0.5*STANDARD_FEE);


}

QString StudentRegistration::toString() const
{
    return "";
}

