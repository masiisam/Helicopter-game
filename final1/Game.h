// #ifndef GAME_H
// #define GAME_H

// #include <QGraphicsView>
// #include <QGraphicsItem>
// #include <QGraphicsScene>
// #include <QMenu>
// #include <QMenuBar>
// #include "Player.h"
// #include "Score.h"
// #include "Health.h"
// class Game: public QGraphicsView{
// public:
//     Game(QGraphicsItem * parent=0);

//     QGraphicsScene * scene;
//     Player * player;
//     Score * score;
//     Health * health;
// public slots:
//     void newGame();
//     void saveGame();
//     void loadGame();
// };

// #endif // GAME_H
#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
public:
    Game(int initialHealth, int initialScore,QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
private slots:
    void handleButtonClick(const QString& message );

};


#endif // GAME_H
