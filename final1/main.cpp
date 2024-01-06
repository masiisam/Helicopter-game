#include "mainwindow.h"
#include <QApplication>
#include "Game.h"
/*
Tutorial Topics:
-QGraphicsPixmapItem, QPixmap, QImage
*/

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
