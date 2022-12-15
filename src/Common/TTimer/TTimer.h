#ifndef TTIMER_H
#define TTIMER_H

#include <QObject>
#include <QEvent>
#include <chrono>
#include <iostream>
#include <thread>

class TTimer : public QObject
{
    Q_OBJECT
public:
    TTimer(QObject *parent = Q_NULLPTR);
    ~TTimer();
    void start(int msec);
    void start();
    void stop();
    void getEvent();
signals:
    void timeout();
private:
    int msec_;
    std::thread t_;
    bool isStart_;
    bool setThreat_;
};


#endif // TTIMER_H
