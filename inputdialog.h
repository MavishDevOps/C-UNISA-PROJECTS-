#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QDateEdit>
#include "registration.h"
#include "person.h"
#include <QComboBox>
#include <QDebug>
#include "studentregistration.h"
#include"guestregistration.h"


class InputDialog:public QDialog
{
    Q_OBJECT
private:
    QLineEdit *nameLineEdit;
    QLineEdit *affiliationLineEdit;
    QComboBox *type_registrationComboBox;
    QLineEdit *emailLineEdit;
    QDateEdit *dateEdit;
    QDate m_BookingDate;
    QString m_Qualification,m_Category;
    Registration registration;
public:


    explicit InputDialog(QWidget*parent=0);

    void accept();
    Person getPerson() const {
        return Person(nameLineEdit->text(), affiliationLineEdit->text(), emailLineEdit->text());
    }

    QDate getDate() const {
        return dateEdit->date();
    }

    QString getType() const {
        return type_registrationComboBox->currentText();
    }

signals:
    void registrationCreated(Registration* registration);



};

#endif // INPUTDIALOG_H
