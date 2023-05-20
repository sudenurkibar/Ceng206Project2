QT       += core gui \
         multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Enemy.cpp \
    Enemy1.cpp \
    Game.cpp \
    Health.cpp \
    LightItem.cpp \
    MyPlayer1.cpp \
    MyPlayer2.cpp \
    MyRect.cpp \
    Player.cpp \
    Score.cpp \
    main.cpp

HEADERS += \
    Bullet.h \
    Enemy.h \
    Enemy1.h \
    Game.h \
    Health.h \
    LightItem.h \
    MyPlayer1.h \
    MyPlayer2.h \
    MyRect.h \
    Player.h \
    Score.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/background.png \
    images/red.png \
    images/yellow.png

RESOURCES += \
    qre.qrc

