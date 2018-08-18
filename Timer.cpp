//
// Created by dipak on 18.08.18.
//

#include "Timer.h"
#include "Ticker.h"
Timer::Timer(QObject *parent)
    : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Timer::timerEvent);
    buttonClicked = false;
}

void Timer::start()
{
    timer->start(this->tickingValue);
    buttonClicked = true;
}

void Timer::setTickingValue(int val)
{
    this->tickingValue = 60000/ val;
    if (buttonClicked) {
        timer->start(this->tickingValue);
    }
}
void Timer::stop()
{
    timer->stop();
    buttonClicked = false;

}
void Timer::timerEvent()
{
    emit timeout();
}




