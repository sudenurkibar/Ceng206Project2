#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Score.h"
#include <QMediaPlayer>
#include<QAudioOutput>
Game::Game(QWidget *parent){
    // we write code block  to create a scene
    QGraphicsScene * scene = new QGraphicsScene();


    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,800); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    //background.
    QPixmap backgroundImage(":image/images/picture.jpg");
    QBrush backgroundBrush(backgroundImage);
    scene->setBackgroundBrush(backgroundBrush);

    // create the player
    player = new Player();
    player-> setPixmap(QPixmap(":/image/images/ghost.png"));

    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    //create the score
    score = new Score();
    scene-> addItem(score);

    //creare the health
    health = new Health();
    health -> setPos(health -> x(), health->y()+25);
    scene-> addItem(health);
    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(3000);

    QTimer * timer1 = new QTimer();
    QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn1()));
    timer1->start(3000);

    // play background music
    QMediaPlayer* music = new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput();
    music ->setAudioOutput(audioOutput);
    music->setSource(QUrl("qrc:/musics/sounds.mp3"));
    audioOutput->setVolume(50);
    music->play();


    show();
}

void Game::gameOver()
{
    // Oyun bittiğinde yapılacak işlemler

    // Mevcut sahneyi temizleme
    scene->clear();

    // Game Over mesajını gösterme
    QGraphicsTextItem* gameOverText = new QGraphicsTextItem("Game Over");
    QFont gameOverFont("Arial", 50);
    gameOverText->setFont(gameOverFont);
    gameOverText->setDefaultTextColor(Qt::red);
    int xPos = width() / 2 - gameOverText->boundingRect().width() / 2;
    int yPos = height() / 2 - gameOverText->boundingRect().height() / 2;
    gameOverText->setPos(xPos, yPos);
    scene->addItem(gameOverText);
}

