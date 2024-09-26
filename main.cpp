#include "widget.h"

#include <QApplication>
#include"registration.h"
#include "registrationlist.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "conferenceview.h"
#include "inputdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    InputDialog dialogue;
    QDate date(2024,7,4);
    StudentRegistration student("Kayleigh Genevieve Kavanaugh","Bachelor in Science in Maths and Computer Science","kaygenkan1@outlook.com",date,"student");
    GuestRegistration guest("Thabo Nhlanhla Mvelase","Financial Manager at Barclays","Thabnmvelas1212@ybarclays.com",date,"guest");

    QList<Registration*> attendeelist;
  ConferenceView view(attendeelist);


    view.show();

    QObject::connect(&dialogue, &InputDialog::registrationCreated, &view, &ConferenceView::registrationCreated);

    if (dialogue.exec() == QDialog::Accepted) {



    }
 view.populateTable();
    w.show();
    return a.exec();
}
