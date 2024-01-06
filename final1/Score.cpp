#include "Score.h"
#include <QFont>
#include <iostream>
#include <cstdlib>   // Required for rand() and srand()
#include <ctime>     // Required for time()


Score::Score(int initialScore, QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
     score = initialScore;


    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    std::srand(std::time(0));
    int randomNumber = std::rand() % 10 + 1;
    score=score+randomNumber;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
