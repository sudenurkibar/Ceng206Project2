#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include "Game.h"

#include<QTimer>
#include <QList>
#include "Enemy.h"
#include <QGraphicsScene>

#include "Game.h"

extern Game *game;
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{   //set random position
    int random_number = rand() % 1200;
    setPos(random_number,0);

    //drew the rect
    setPixmap(QPixmap(":/image/images/enemy1.png"));
    //Alaşağı ediyor fotoğrafı
    /*setTransformOriginPoint(50,50);
    setRotation(180);*/

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout() ) , this,SLOT(move()));



    timer -> start(200);
}


void Enemy::move()

{
    QList<QGraphicsItem * > colliding_items = collidingItems();
    for (QGraphicsItem* item : colliding_items) {
        if (typeid(*item) == typeid(Player)) {
            // Player ile çarpışma oldu
            // Sağlık azaltılabilir veya diğer işlemler yapılabilir
            game->health->decrease();

            // Enemy'yi sahneden kaldırma
            scene()->removeItem(this);
            delete this;

            return; // Çarpışma durumunda fonksiyondan çık
        }
    }

    //move enemy down
    setPos(x(), y()+5);

    if(pos().y() <0){
        //decrease the health
        game->health->decrease();

        scene() -> removeItem(this);
        delete this;
    }
}





