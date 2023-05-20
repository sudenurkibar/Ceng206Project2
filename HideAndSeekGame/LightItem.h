#ifndef LIGHTITEM_H
#define LIGHTITEM_H

#include <QGraphicsItem>
#include "Player.h"

class LightItem : public QGraphicsItem
{
public:
    LightItem(Player *player);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;

private:
    Player *m_player;
};

#endif // LIGHTITEM_H
