#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy1.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event)
{
    int step = 10; // Hareket adımı

    // Yön tuşları ile hareket
    if (event->key() == Qt::Key_Up) {
        setPos(x(), y() - step);
    } else if (event->key() == Qt::Key_Down) {
        setPos(x(), y() + step);
    } else if (event->key() == Qt::Key_Left) {
        setPos(x() - step, y());
    } else if (event->key() == Qt::Key_Right) {
        setPos(x() + step, y());
    } else if (event->key() == Qt::Key_Space) {
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }

}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
void Player::spawn1()
{
    //create an enemy
    Enemy1 * enemy1 = new Enemy1();
    scene() -> addItem(enemy1);

}
