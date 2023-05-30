#include "Timer.h"
#include <QTimer>
#include <QFont>

Timer::Timer(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    timeCount = 120;
    setPlainText(QString("Countdown: ") + QString::number(timeCount));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 20));
    timerId = startTimer(1000);  // Store the timer ID

}

void Timer::timerEvent(QTimerEvent *event) {
    decrease();
}

void Timer::decrease() {
    if (timeCount > 0) {
        timeCount--;
        setPlainText(QString("Countdown: ") + QString::number(timeCount));
    } else {
        emit timeExpired();
        killTimer(timerId);  // Stop the timer when time is up using the stored timer ID
    }
}

int Timer::getTime() {
    return timeCount;
}
