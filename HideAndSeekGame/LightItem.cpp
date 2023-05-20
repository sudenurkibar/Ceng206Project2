#include "LightItem.h"
#include "player.h" // Include Player class header

#include <QPainter>

LightItem::LightItem(Player *player)
    : m_player(player)
{
    setFlag(ItemStacksBehindParent);
}

QRectF LightItem::boundingRect() const
{
    return QRectF(-100, -100, 200, 200);
}

void LightItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(255, 255, 255, 100));
    painter->drawEllipse(-100, -100, 200, 200);
}

void LightItem::advance(int phase)
{
    if (phase == 1 && m_player)
    {
        QPointF playerPos = m_player->pos();
        setPos(playerPos);
    }
}
