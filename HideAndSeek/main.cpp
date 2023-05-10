//Umut Şenol

#include <QApplication>
#include <MyPlayer1.h>
#include <MyPlayer2.h>
#include <QGraphicsRectItem>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    MyPlayer * player1 = new MyPlayer();
    player1->setRect(0,0,100,100);

    MyPlayer2 * player2 = new MyPlayer2();
    player2->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    // make player focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFlag(QGraphicsItem::ItemIsFocusable);

    player1->setFocus();
    player2->setFocus();

    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    //show the view
    view->show();
    view->setFixedSize(1200,750);
    scene->setSceneRect(0,0,1200,750);

    player1-> setPos(view->width()/2 - 30 , view->height() - player1->rect().height());
    player2-> setPos(view->width()/2 - 30, 0);

    return a.exec();
}
