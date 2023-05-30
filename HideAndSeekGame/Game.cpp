#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Score.h"
#include <QGraphicsOpacityEffect>
//#include <QMediaPlayer>
//#include <QAudioOutput>
#include "Timer.h"

Game::Game(QWidget* parent)
    : QGraphicsView(parent), timer0(nullptr){
    // we write code block  to create a scene
    QGraphicsScene * scene = new QGraphicsScene();


    // create the scene
    scene = new QGraphicsScene();
    //scene->setSceneRect(0,0,1417, 794); // make the scene 800x600 instead of infinity by infinity (default)
    int screenWidth = 1280; // Ekran genişliği
    int screenHeight = 720; // Ekran yüksekliği

    int sceneWidth = 1280; // Sahne genişliği
    int sceneHeight = 720; // Sahne yüksekliği

    // Ekrana sığacak şekilde sahneyi ölçeklendirme
    if (sceneWidth > screenWidth || sceneHeight > screenHeight) {
        float widthScale = static_cast<float>(screenWidth) / sceneWidth;
        float heightScale = static_cast<float>(screenHeight) / sceneHeight;
        float scale = std::min(widthScale, heightScale);
        sceneWidth *= scale;
        sceneHeight *= scale;
    }

    int sceneX = (screenWidth - sceneWidth) / 2; // Sahnenin yatay konumu
    int sceneY = (screenHeight - sceneHeight) / 2; // Sahnenin dikey konumu

    scene->setSceneRect(sceneX, sceneY, sceneWidth, sceneHeight);
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    //background.
    QPixmap backgroundImage(":/images/background2.png");
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(backgroundImage);
    scene->addItem(backgroundItem);

    // create the player
    player = new Player();
    player-> setPixmap(QPixmap(":/images/ghost.png"));

    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    QGraphicsDropShadowEffect* dropShadowEffect = new QGraphicsDropShadowEffect();
    dropShadowEffect->setColor(Qt::yellow);
    dropShadowEffect->setOffset(0, -100);
    dropShadowEffect->setBlurRadius(400);

    // Player ögesine aydınlatma efektini uygulama
    player->setGraphicsEffect(dropShadowEffect);

    // Sahneye player ögesini ekleme
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
   /* QMediaPlayer* music = new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput();
    music ->setAudioOutput(audioOutput);
    music->setSource(QUrl("qrc:/musics/sounds.mp3"));
    audioOutput->setVolume(50);
    music->play();
    */
    // Create  countdown timer
    Timer* timer0 = new Timer();
    timer0->setPos(1050, 0);  // Position the timer at the top right corner
    scene->addItem(timer0);

    // Connect the countdown timer's timeExpired signal to the gameOver slot
    connect(timer0, &Timer::timeExpired, this, &Game::gameOver);


    show();
}

void Game::gameOver()
{
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

