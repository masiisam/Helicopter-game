#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(int initialScore,QGraphicsItem * parent=0);
    void increase();
    int getScore();
    int score;
};

#endif // SCORE_H
