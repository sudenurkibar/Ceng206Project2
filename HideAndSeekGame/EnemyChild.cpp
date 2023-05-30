#include "EnemyChild.h"
#include "Player.h"
#include "Game.h"

extern Game *game;

EnemyChild::EnemyChild(QGraphicsItem *parent) : Enemy(parent)
{
    // Farklı bir görsel atanabilir
    setPixmap(QPixmap(":/images/enemy2.png"));
}

void EnemyChild::move()
{
    // Çaprazdan hareket etmek için x ve y pozisyonlarını güncelle
    setPos(x() + 5, y() + 5);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (QGraphicsItem *item : colliding_items) {
        if (typeid(*item) == typeid(Player)) {
            // Player ile çarpışma oldu
            // Sağlık azaltılabilir veya diğer işlemler yapılabilir
            game->health->decrease();
            game->player->decreaseOpacity(0.2);
            // Enemy'yi sahneden kaldırma
            scene()->removeItem(this);
            delete this;
            return; // Çarpışma durumunda fonksiyondan çık
        }
    }
}
