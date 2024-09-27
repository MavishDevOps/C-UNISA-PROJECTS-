#ifndef PRIMENUMGUI_H
#define PRIMENUMGUI_H
#include "mainwindow.h"
#include <QObject>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLabel>
#include "primefinder.h"

class PrimeNumGui:public QMainWindow

{
    Q_OBJECT

    QLineEdit *startInput,*endInput,*threadsInput;
    QTextEdit *threadResults[4];
    PrimeFinder *primeThreads[4];

public:
    PrimeNumGui(QWidget*parent=0);
    void setupUI();
    void clearResults();
    void displayPrime(int threadIndex,int prime_num);//displays prime numbers

private slots:
    void onStartClicked();
protected:
    void closeEvent(QCloseEvent *event)override;//Handles window close events


};



#endif // PRIMENUMGUI_H
