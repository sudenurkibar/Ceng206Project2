#ifndef CIRCLEITEM_H
#define CIRCLEITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>

class circleItem : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit circleItem();

signals:

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsPixmapItem * redCircle;
    QGraphicsPixmapItem * yellowCircle;
};

#endif // CIRCLEITEM_H
