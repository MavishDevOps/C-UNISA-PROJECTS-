#include "primenumgui.h"

PrimeNumGui::PrimeNumGui(QWidget *parent) : QMainWindow(parent) {
    setupUI();
}

void PrimeNumGui::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    startInput = new QLineEdit(this);
    endInput = new QLineEdit(this);
    threadsInput = new QLineEdit(this);

    layout->addWidget(new QLabel("Start Number:"));
    layout->addWidget(startInput);
    layout->addWidget(new QLabel("End Number:"));
    layout->addWidget(endInput);
    layout->addWidget(new QLabel("Number of Threads:"));
    layout->addWidget(threadsInput);

    for (int i = 0; i < 4; ++i) {
        threadResults[i] = new QTextEdit(this);
        threadResults[i]->setReadOnly(true);
        layout->addWidget(new QLabel(QString("Thread %1 results:").arg(i + 1)));
        layout->addWidget(threadResults[i]);
    }

    QPushButton *startButton = new QPushButton("Start", this);
    layout->addWidget(startButton);
    connect(startButton, &QPushButton::clicked, this, &PrimeNumGui::onStartClicked);

    setCentralWidget(centralWidget);
}

void PrimeNumGui::onStartClicked() {
    int start = startInput->text().toInt();
    int end = endInput->text().toInt();
    bool ok;
    int threadCount = threadsInput->text().toInt(&ok);

    if (!ok || threadCount < 1 || threadCount > 4) {
        QMessageBox::warning(this, "Error", "Number of threads must be a valid number between 1 and 4.");
        return;
    }

    clearResults();
    int range = (end - start + 1) / threadCount;

    for (int i = 0; i < threadCount; ++i) {
        int threadStart = start + i * range;
        int threadEnd = (i == threadCount - 1) ? end : threadStart + range - 1;

        primeThreads[i] = new PrimeFinder(threadStart, threadEnd, this);

        connect(primeThreads[i], &PrimeFinder::primeFound, this, [this, i](int result) {

        });



        primeThreads[i]->start();
    }
}

void PrimeNumGui::closeEvent(QCloseEvent *event) {
    for (int i = 0; i < 4; ++i) {
        if (primeThreads[i]) {
            primeThreads[i]->quit();
            primeThreads[i]->wait();
        }
    }
    event->accept();
}

void PrimeNumGui::clearResults() {
    for (int i = 0; i < 4; ++i) {
        threadResults[i]->clear();
    }
}

void PrimeNumGui::displayPrime(int threadIndex, int prime) {
    threadResults[threadIndex]->append(QString::number(prime));
}
