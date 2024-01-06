#include "Health.h"
#include <QFont>
#include <QApplication>
#include <QMessageBox>
Health::Health(int initialHealth ,QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = initialHealth;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    if(health==0){
        QMessageBox::information(nullptr, "Information", "Game Over.");
        QCoreApplication::quit();
        QApplication::exit();
    }
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}
int Health::setHealth(int h){
    health=h;
    return h;
}
