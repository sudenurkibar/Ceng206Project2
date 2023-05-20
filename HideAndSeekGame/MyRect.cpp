#include "MyRect.h"
#include "qevent.h"
#include <QKeyEvent>
#include <Bullet.h>
#include <QDebug>
#include <QGraphicsScene>
#include <Enemy.h>
#include <Enemy1.h>

void MyRect::keyPressEvent(QKeyEvent *event)
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

void MyRect::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene() -> addItem(enemy);

}

void MyRect::spawn1()
{
    //create an enemy
    Enemy1 * enemy1 = new Enemy1();
    scene() -> addItem(enemy1);

}
