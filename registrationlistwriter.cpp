#include "registrationlistwriter.h"

RegistrationListWriter::RegistrationListWriter() {}

void RegistrationListWriter::writeRegistrationList() {
    // Creation of the XML file and its root element
    QDomDocument RegistrationXmldoc;
    QDomElement rootelement = RegistrationXmldoc.createElement("registrationlist");
    RegistrationXmldoc.appendChild(rootelement);

    for (const Registration *reg : m_AttendeeList) {
        QDomElement regelement = RegistrationXmldoc.createElement("registration");
        regelement.setAttribute("type", reg->registrationType());

        QDomElement attendeelement = RegistrationXmldoc.createElement("attendee");
        attendeelement.appendChild(RegistrationXmldoc.createTextNode(reg->getAttendee().getName()));

        QDomElement namelement = RegistrationXmldoc.createElement("name");
        namelement.appendChild(RegistrationXmldoc.createTextNode(reg->getAttendee().getName()));

        QDomElement affiliationelement = RegistrationXmldoc.createElement("affiliation");
        affiliationelement.appendChild(RegistrationXmldoc.createTextNode(reg->getAttendee().getAffiliation()));

        QDomElement emailElement = RegistrationXmldoc.createElement("email");
        emailElement.appendChild(RegistrationXmldoc.createTextNode(reg->getAttendee().getEmail()));

        QDomElement bookingDateElement = RegistrationXmldoc.createElement("bookingdate");
        bookingDateElement.appendChild(RegistrationXmldoc.createTextNode(reg->getBookingDate().toString()));

        QDomElement feeElement = RegistrationXmldoc.createElement("fees");
        feeElement.appendChild(RegistrationXmldoc.createTextNode(QString::number(reg->calculateFee())));

        // Append child elements to the registration element
        regelement.appendChild(attendeelement);
        regelement.appendChild(namelement);
        regelement.appendChild(affiliationelement);
        regelement.appendChild(emailElement);
        regelement.appendChild(bookingDateElement);
        regelement.appendChild(feeElement);

        // Append the registration element to the root element
        rootelement.appendChild(regelement);
    }


    QString xmlfilename = QFileDialog::getSaveFileName(0, "Save RegistrationList", "", "XML Files (*.xml);;All Files(*)");
    if (xmlfilename.isEmpty()) {
        qDebug() << "No file name provided..";
        return;
    }

    QFile file(xmlfilename);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Error opening file for writing.";
        return;
    }

    QTextStream out(&file);
    out << RegistrationXmldoc.toString(); // Write the XML content
    file.close(); // Close the file

    qDebug() << "XML file written successfully.";
    qDebug() << "Attendee list size:" << m_AttendeeList.size();


}
