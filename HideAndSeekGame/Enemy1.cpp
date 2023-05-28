#include "Enemy1.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include "Game.h"

extern Game *game;

Enemy1::Enemy1(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{   //set random position
    int random_number = rand() % 1200;
    setPos(random_number,0);
    //drew the rect
    setPixmap(QPixmap(":/image/images/enemy2.png"));
    QTimer * timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout() ) , this,SLOT(move1()));
    timer1-> start(50);
}


void Enemy1::move1()

{
    QList<QGraphicsItem * > colliding_items = collidingItems();
    for (QGraphicsItem* item : colliding_items) {
        if (typeid(*item) == typeid(Player)) {
            // Player ile çarpışma oldu
            // Sağlık azaltılabilir veya diğer işlemler yapılabilir
            // Enemy'yi sahneden kaldırma
            scene()->removeItem(this);
            delete this;

            return; // Çarpışma durumunda fonksiyondan çık
        }
    }

    //move enemy down
    setPos(x()-5, y()+5);

    if(pos().y() <0){
        //decrease the health

        scene() -> removeItem(this);
        delete this;
    }
}
