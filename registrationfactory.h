#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H
//RegistrationFactory.h
#include "registration.h"
#pragma once
class RegistrationFactory{

    RegistrationFactory();
    static RegistrationFactory *getInstance();//singleton instantiation of factory method RegistrationFactory


public:


    Registration* createRegistration(QString reg);
    static RegistrationFactory*instance;
};
#endif // REGISTRATIONFACTORY_H
