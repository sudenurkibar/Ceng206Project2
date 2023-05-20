 #include "Health.h"
#include <QFont>
#include "QMessageBox"
#include "Game.h"
extern Game *game;

Health :: Health (QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initialize the score to 0
    health = 3  ;

    //draw the text
    setPlainText(QString("Health : " + QString:: number(health) )); // Score : 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 20));
}

void Health :: checkGameOver(int currentHealth){
 if (currentHealth <= 0) {
        // Oyunu bitirme işlemleri
        QMessageBox::information(nullptr, "Game Over", "Health became 0 !");
        game->gameOver(); // Oyunu sıfırlama işlemi
    }
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health : ") + QString::number(health)); // Health: 1
    checkGameOver(health);
}


int Health::getHealth()
{
    return health;
}

