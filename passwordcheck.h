#ifndef PASSWORDCHECK_H
#define PASSWORDCHECK_H

#include <QVBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QRegularExpression>
#include <QString>
#include <QLabel>

class PasswordCheck : public QWidget // This program validates if a password entered is correct and meets guidelines for a password
{
    Q_OBJECT
    // All members are private by default
    QCheckBox *passwordRule1, *passwordRule2, *passwordRule3;
    QLineEdit *passwordInput;
    QPushButton *validateButton;
    QString password;
    static QRegularExpression regexRule3;

private slots:
    void validate_Password();
    bool validateRule1(const QString &password);
    bool validateRule2(const QString &password);
    bool validateRule3(const QString &password);
    void showError(const QString &message);

public:

    PasswordCheck(QWidget *parent = 0);
};

#endif // PASSWORDCHECK_H
