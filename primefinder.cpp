#include "primefinder.h"
#include <cmath>
#include <QDebug>

PrimeFinder::PrimeFinder(int start, int end, QObject *parent)
    : QThread(parent), n_start(start), n_finish(end) {
}

void PrimeFinder::run() {
    for (int i = n_start; i <= n_finish; ++i) {
        if (isPrime(i)) {
            emit primeFound(i); // Emit the signal when a prime number is found
            qDebug() << i << "is a prime number";
        }
    }
}

bool PrimeFinder::isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i <= std::sqrt(number); ++i) {
        if (number % i == 0) return false;
    }
    return true;
}
