#ifndef ENEMY1_H
#define ENEMY1_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Enemy.h"

class Enemy1 : public QObject,  public QGraphicsPixmapItem , public Enemy{
    Q_OBJECT
public:
    explicit Enemy1(QGraphicsItem *parent = nullptr);

public slots:
    void move1();
};

#endif // ENEMY1_H
