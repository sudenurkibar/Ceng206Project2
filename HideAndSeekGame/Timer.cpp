#include "Timer.h"
#include <QTimer>
#include <QFont>
#include "Game.h"
#include <QMessageBox>
#include <QEventLoop>

extern Game *game;

Timer::Timer(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    timeCount = 5;
    setPlainText(QString("Countdown: ") + QString::number(timeCount));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 20));
    timerId = startTimer(1000);  // Store the timer ID
}


void Timer::timerEvent(QTimerEvent *event) {
    decrease();
}

void Timer::checkTime(int timeCount1){
    if (timeCount1 <= 0) {
        // Oyunu bitirme işlemleri
        QMessageBox::information(nullptr, "Game Over", "Oyunu Bitirdiniz");
        game->gameOver(); // Oyunu sıfırlama işlemi
    }
}

void Timer::decrease() {
    if (timeCount > 0) {
        timeCount--;
        setPlainText(QString("Countdown: ") + QString::number(timeCount));
    } else {
        emit timeExpired();
        killTimer(timerId);  // Stop the timer when time is up using the stored timer ID
        checkTime(timeCount)
    }
}


int Timer::getTime() {
    return timeCount;
}
