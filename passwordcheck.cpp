#include "passwordcheck.h"

// Define the regexRule3
QRegularExpression PasswordCheck::regexRule3("^[1-9][0-9]{3,5}$");


PasswordCheck::PasswordCheck(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("COS3711 Password Validity program");
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *messageLabel = new QLabel("Enter in password: ", this);
    layout->addWidget(messageLabel);

    passwordRule1 = new QCheckBox("1: Minimum 5 characters, no spaces", this);
    passwordRule2 = new QCheckBox("2: The third character should be a digit (1-9) or lowercase (a-f) or uppercase (A-F) alphabet", this);
    passwordRule3 = new QCheckBox("3: 4-6 digits permitted only, cannot start with 0", this);
    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password); // To hide the password input, displays as asterisks and dots

    validateButton = new QPushButton("Validate", this);

    layout->addWidget(passwordRule1);
    layout->addWidget(passwordRule2);
    layout->addWidget(passwordRule3);
    layout->addWidget(passwordInput);
    layout->addWidget(validateButton);

    connect(validateButton, &QPushButton::clicked, this, &PasswordCheck::validate_Password);
}

void PasswordCheck::validate_Password()
{
    password = passwordInput->text();
    if (passwordRule1->isChecked() && !validateRule1(password))
    {
        showError("😢 Password exceeded 5 characters, enter a password of 5 characters long");
    }
    else if (passwordRule2->isChecked() && !validateRule2(password))
    {
        showError("😢 Password does not meet the requirements, please ensure the third character is a digit (1-9)");
    }
    else if (passwordRule3->isChecked() && !validateRule3(password))
    {
        showError("😢 Password exceeds 6 digits or starts with 0. Ensure password has 4-6 digits, no 0's allowed");
    }
    else
    {
        QMessageBox::information(this, "Success", "😊 Your password meets the requirements. Password created.");
    }
}

bool PasswordCheck::validateRule1(const QString &password)
{
    return password.length() == 5 && !password.contains(' ');
}

bool PasswordCheck::validateRule2(const QString &password)
{
    if (password.length() != 5) return false;
    QChar thirdChar = password[2];
    return thirdChar.isDigit() || (thirdChar >= 'a' && thirdChar <= 'f') || (thirdChar >= 'A' && thirdChar <= 'F');
}

bool PasswordCheck::validateRule3(const QString &password)
{
    return regexRule3.match(password).hasMatch();
}

void PasswordCheck::showError(const QString &message)
{
    QMessageBox::critical(this, "Error", message);
}
