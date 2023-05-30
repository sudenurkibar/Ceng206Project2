#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Timer.h"
#include <QGraphicsOpacityEffect>
#include <QPushButton>

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent= 0 );


    QGraphicsScene * scene;
    Player * player;
    Score *score;
    Health *health;

    void gameOver();
    void startSecondPlayer();
    void handleKeyPress();


private:
    // ...
    Timer* timer0;

private slots:
    void handleTimerExpired();
};

#endif // GAME_H
