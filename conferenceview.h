#ifndef CONFERENCEVIEW_H
#define CONFERENCEVIEW_H
#include "person.h"
#include <QDate>
#include <QString>
#include <QTableWidget>
#include "registration.h"
#include "registrationlist.h"
#include "inputdialog.h"
#include <QDebug>
class ConferenceView:public QWidget
{
    QTableWidget *ViewWidget;
    QList<Registration*> m_AttendeeList;

public:
    ConferenceView();
    void populateTable();

    void ShowDialogue();
    ConferenceView(QList<Registration*> attendeeList, QWidget *parent = nullptr)
        : QWidget(parent), m_AttendeeList(attendeeList)
    {
        ViewWidget = new QTableWidget(this);
        ViewWidget->setColumnCount(6);
        ViewWidget->setHorizontalHeaderLabels(QStringList() << "Name of attendee" << "Affiliation" << "Email" << "Booking date" << "Type of registration"<<"Fees");

    }

signals:
    void registrationCreated(Registration *registration);



};




#endif // CONFERENCEVIEW_H
