#include "inputdialog.h"


InputDialog::InputDialog(QWidget *parent):QDialog(parent){
    QVBoxLayout *layout = new QVBoxLayout(this);//setting up the inputdialog widget

    setWindowTitle("Eagle Registration Tool opendev");
    // Name input
    QLabel *nameLabel = new QLabel("Enter Name:", this);
    layout->addWidget(nameLabel);
    nameLineEdit = new QLineEdit(this);
    layout->addWidget(nameLineEdit);

    // Affiliation input
    QLabel *affiliationLabel = new QLabel("Enter in your affiliation:", this);
    layout->addWidget(affiliationLabel);
    affiliationLineEdit = new QLineEdit(this);
    layout->addWidget(affiliationLineEdit);

    // Type of registration input
    QLabel *type_registrationLabel = new QLabel("Please indicate which category type you belong to", this);
    layout->addWidget(type_registrationLabel);
    type_registrationComboBox = new QComboBox(this);
    type_registrationComboBox->addItem("Guest"); // we have 3 types of users
    type_registrationComboBox->addItem("Student");
    type_registrationComboBox->addItem("Standard attendee");
    layout->addWidget(type_registrationComboBox);
    QString type=type_registrationComboBox->currentText();

    if(type=="Student")
    {
        m_Qualification=affiliationLineEdit->text();

    }
    else if(type=="Guest")
    {
        m_Category=affiliationLineEdit->text();
    }
    // Email input
    QLabel *emailLabel = new QLabel("Enter in your email:", this);
    layout->addWidget(emailLabel);
    emailLineEdit = new QLineEdit(this);
    layout->addWidget(emailLineEdit);

    // Date input
    QLabel *dateLabel = new QLabel("Select Booking Date :", this);
    layout->addWidget(dateLabel);
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    dateEdit->setCalendarPopup(true);
    m_BookingDate=dateEdit->date();
    layout->addWidget(dateEdit);

    // OK Button
    QPushButton *okButton = new QPushButton("Enter", this);
    connect(okButton, &QPushButton::clicked, this, &InputDialog::accept);
    layout->addWidget(okButton);

    // Cancel Button
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, &QPushButton::clicked, this, &InputDialog::reject);
    layout->addWidget(cancelButton);

}

void InputDialog::accept() {
    QString name = nameLineEdit->text();
    QString affiliation = affiliationLineEdit->text();
    QString registrationType = type_registrationComboBox->currentText();
    QDate date = dateEdit->date();
    QString email = emailLineEdit->text();
    double fee=0;

    Registration* registration = new Registration(name, affiliation, email, date, registrationType);
    if (registrationType == "Student") {
        registration = new StudentRegistration(name, affiliation, email, date, registrationType);
    } else if (registrationType == "Guest") {
        registration = new GuestRegistration(name, affiliation, email, date, registrationType);
    } else {
        registration = new Registration(name, affiliation, email, date, registrationType);
    }

    fee=registration->calculateFee();


    qDebug()<<"Name:"<<name<<Qt::endl;
    qDebug()<<"Affiliation:"<<affiliation<<Qt::endl;
    qDebug()<<"Email:"<<email<<Qt::endl;
    qDebug()<<"Date: "<<date<<Qt::endl;
    qDebug()<<"Type of Registration:"<<registrationType<<Qt::endl;
    qDebug()<<"Fees owed:"<<fee<<Qt::endl;


    emit registrationCreated(registration);

    QDialog::accept();
}


