#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H


#include <QThread>
class PrimeFinder : public QThread {
    Q_OBJECT

public:
    PrimeFinder(int start, int end, QObject *parent = nullptr);

signals:
    void primeFound(int prime);

public slots:
    void run();

private:
    bool isPrime(int number);
    int n_start;
    int n_finish;
};

#endif // PRIMEFINDER_H
