#include "registrationfactory.h"
#include "registration.h"
#include "studenttregistration.h"
#include "guestregistration.h"
#include <QDebug>

RegistrationFactory::RegistrationFactory(){

    qDebug()<<"Welcome to Tsogo sun empowered by eagle opendev registration tool \n";

}

//instantiation of RegistrationFactory instance
RegistrationFactory*RegistrationFactory::instance=nullptr;

RegistrationFactory*RegistrationFactory::getInstance()
{
    if(!instance){ instance =new RegistrationFactory();}

    return instance;
}


Registration*RegistrationFactory::createRegistration(QString reg)
{
    if(reg=="Student registration")
    {
        return new StudentRegistration();

    }else if (reg=="Guest Registration")
    {
        return new GuestRegistration();
    }
    else{
        return nullptr;
    }

}
