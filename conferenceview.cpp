#include "conferenceview.h"


ConferenceView::ConferenceView() {}

 void ConferenceView::populateTable()


{
     qDebug()<<"Registration table printed"<<Qt::endl;


     for(int i = 0; i < m_AttendeeList.size(); ++i)
     {
         Registration *r = m_AttendeeList.at(i);
         Person attendee = r->getAttendee();
         QDate bookingDate = r->getBookingDate();
         QString className = r->metaObject()->className();
         double fee = r->calculateFee();

         QTableWidgetItem *nameItem = new QTableWidgetItem(attendee.getName());
         QTableWidgetItem *affiliationItem = new QTableWidgetItem(attendee.getAffiliation());
         QTableWidgetItem *emailItem = new QTableWidgetItem(attendee.getEmail());
         QTableWidgetItem *dateItem = new QTableWidgetItem(bookingDate.toString("dd.MM.yyyy"));
         QTableWidgetItem *typeItem = new QTableWidgetItem(className);
         QTableWidgetItem *feeItem = new QTableWidgetItem(QString::number(fee));

         ViewWidget->insertRow(i);
         ViewWidget->setItem(i, 0, nameItem);
         ViewWidget->setItem(i, 1, affiliationItem);
         ViewWidget->setItem(i, 2, emailItem);
         ViewWidget->setItem(i, 3, dateItem);
         ViewWidget->setItem(i, 4, typeItem);
         ViewWidget->setItem(i, 5, feeItem);
     }



 }
void ConferenceView::registrationCreated(Registration* registration) {
    m_AttendeeList.append(registration);
    populateTable();
}
void ConferenceView::ShowDialogue() {
    InputDialog* dialog = new InputDialog(this);
    connect(dialog, &InputDialog::registrationCreated, this, &ConferenceView::populateTable);

    dialog->show();
}
