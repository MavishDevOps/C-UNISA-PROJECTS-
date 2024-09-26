#include "registrationlist.h"

RegistrationList::RegistrationList() {}

//The purpose of this class is to list each registration and describe the type of each registration


bool RegistrationList::addRegistration(Registration *r)//adds registration if unique

{
    bool isUnique = true;
    foreach (Registration* b, m_AttendeeList)
    {
        if(b->getAttendee().getEmail() == r->getAttendee().getEmail() &&
            b->getAttendee().getName() == r->getAttendee().getName())
        {
            isUnique = false;
            break;
        }
    }
    if(isUnique)
        m_AttendeeList.append(r);
}


//implementation of destructor

RegistrationList::~RegistrationList() //removes registration

{
    qDeleteAll(m_AttendeeList);

}

bool RegistrationList::isRegistered(QString n)// checks if registrant is registered
{

    foreach (Registration* b,m_AttendeeList) {
        if(b->getAttendee().getName()==n)
            return true;
    }

    return false;
}

double RegistrationList::totalFee(QString t)// calculates total fees of each registration based on type of registration
{
    double Total_reg=0;


    foreach(Registration *r,m_AttendeeList){

        QString ClassName= r->metaObject()->className();
        if(t=="All registrations")//for all types

            Total_reg+=r->calculateFee();
        else {




            //do the following if not all

            if(ClassName=="GuestRegistration")

            Total_reg+=r->calculateFee();

            if (ClassName=="StudentRegistration")
                Total_reg+=r->calculateFee();

            if(ClassName=="Registration")
                Total_reg+=r->calculateFee();

        }
    }

    return Total_reg;
}

int RegistrationList::totalRegistrations(QString a)//counts how many registrations per attendee and type of registration
{    int count_registrations=0;


    foreach(Registration *r,m_AttendeeList){
        QString ClassName= r->metaObject()->className();
        if(a=="All registrations")
            count_registrations++;
        else {




            if(ClassName=="Registrations")
                count_registrations++;
            if(ClassName=="StudentRegistrations")
                count_registrations++;
            if(ClassName=="GuestRegistrations")
                count_registrations++;


        }
    }

    return count_registrations;
}

