#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>

class RegistrationListReader
{
public:
    RegistrationListReader();
    void ReadXML();
};

#endif // REGISTRATIONLISTREADER_H
