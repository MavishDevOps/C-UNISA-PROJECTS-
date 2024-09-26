#include "person.h"

Person::Person() {}

Person::Person(QString n, QString a, QString e):m_Name(n),m_Affiliation(a),m_Email(e)
//initialisation of default constructor
{

}

QString Person::toString(){
    return" Name of Attendee  ";
    return"Affiliation:      ";
    return "Email address:  ";
}

