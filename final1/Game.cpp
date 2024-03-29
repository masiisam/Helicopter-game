#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QBrush>
#include <QImage>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Game::Game(int initialHealth, int initialScore,QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score(initialScore);
    scene->addItem(score);
    health = new Health(initialHealth);

    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    QPushButton *button = new QPushButton("SaveGame", this);
    button->setGeometry(100, 0, 150, 30);
    QObject::connect(button, &QPushButton::clicked, [this, button]() {
        handleButtonClick(QString::number(health->getHealth())+" "+QString::number(score->getScore()));
    });
    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
    QTimer * timer1 = new QTimer();
    QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn1()));
    timer1->start(1000);

    show();
}

void Game::handleButtonClick(const QString& message) {
    // add your code here to handle the button click event
    QMessageBox::information(this, "Button Clicked", "save game");
    QFile file("./SaveGame.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << message;
        file.close();
    }
}
