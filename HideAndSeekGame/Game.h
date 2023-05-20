#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include <QGraphicsOpacityEffect>

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent= 0 );


    QGraphicsScene * scene;
    Player * player;
    Score *score;
    Health *health;


    void gameOver();
};

#endif // GAME_H
