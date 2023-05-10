#include "circleitem.h"
#include <QKeyEvent>

circleItem::circleItem():
    redCircle(new QGraphicsPixmapItem(QPixmap(":/images/red.png"))),
    yellowCircle(new QGraphicsPixmapItem(QPixmap(":/images/yellow.png")))
{

    redCircle->setPos(QPointF(10,0) - QPointF(redCircle->boundingRect().width()/2,
                                              redCircle->boundingRect().height() + 60));

    yellowCircle->setPos(QPointF(0,0) - QPointF(-yellowCircle->boundingRect().width()/2,60));

    addToGroup(redCircle);
    addToGroup(yellowCircle);

}
void circleItem::keyPressEvent(QKeyEvent *event)
{
/*
    if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }else if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }else if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
*/
    qreal x = 0;
    qreal y = 0;
    qreal step = 10;

    switch (event->key()) {
    case Qt::Key_Up:
        y = -step;
        break;
    case Qt::Key_Down:
        y = step;
        break;
    case Qt::Key_Left:
        x = -step;
        break;
    case Qt::Key_Right:
        x = step;
        break;
    case Qt::Key_A:
        yellowCircle->moveBy(-step, 0);
        break;
    case Qt::Key_D:
        yellowCircle->moveBy(step, 0);
        break;
    case Qt::Key_W:
        yellowCircle->moveBy(0, -step);
        break;
    case Qt::Key_S:
        yellowCircle->moveBy(0, step);
        break;
    }

    if (x || y) {
        QPointF pos = redCircle->pos();
        pos += QPointF(x, y);
        redCircle->setPos(pos);
    }
}
