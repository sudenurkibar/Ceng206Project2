#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect :public QObject, public QGraphicsRectItem{
    Q_OBJECT
public :
  void keyPressEvent(QKeyEvent *event);

public slots:
  void spawn();
  void spawn1();
};



#endif // MYRECT_H
