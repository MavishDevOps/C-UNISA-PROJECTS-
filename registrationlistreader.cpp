#include "registrationlistreader.h"


RegistrationListReader::RegistrationListReader() {}

void RegistrationListReader::ReadXML() {
    QFile file("registrationlist.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening file for reading.";
        return;
    }

    QXmlStreamReader readregistrationlist;
    readregistrationlist.setDevice(&file);

    while (!readregistrationlist.atEnd()) {
        readregistrationlist.readNext();

        if (readregistrationlist.isStartElement()) {
            QString elementName = readregistrationlist.name().toString();
            if (elementName == "registration") {
                qDebug() << "Registration Type:";
                // If there's an attribute you want to read, you can add code here
            } else if (elementName == "name") {
                qDebug() << "Name:" << readregistrationlist.readElementText();
            } else if (elementName == "affiliation") {
                qDebug() << "Affiliation:" << readregistrationlist.readElementText();
            } else if (elementName == "email") {
                qDebug() << "Email:" << readregistrationlist.readElementText();
            } else if (elementName == "bookingdate") {
                qDebug() << "Booking Date:" << readregistrationlist.readElementText();
            } else if (elementName == "fees") {
                qDebug() << "Fees:" << readregistrationlist.readElementText();
            }
        }
    }

    if (readregistrationlist.hasError()) {
        qDebug() << "Error processing XML document:" << readregistrationlist.errorString();
    }

    file.close();
}
