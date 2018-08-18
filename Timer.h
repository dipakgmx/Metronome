//
// Created by dipak on 18.08.18.
//

#ifndef METRONOME_TIMER_H
#define METRONOME_TIMER_H


#include <QObject>
#include <QtCore/QTimer>
#include "Ticker.h"
class Timer : public QObject
{
Q_OBJECT
public:
    explicit Timer(QObject *parent = 0);

public slots:
    void start();
    void stop();
    void setTickingValue(int val);
    void timerEvent();

signals:
    // sent when the timer finishes to count
    void timeout();


private:
    QTimer *timer;
    int tickingValue;
    bool buttonClicked;
};


#endif //METRONOME_TIMER_H
