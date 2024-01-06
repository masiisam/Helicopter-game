#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "Game.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
extern Game * game;
void MainWindow::on_pushButton_clicked()
{
    game = new Game(3,0);
    game->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString filename = "./SaveGame.txt";

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "Button Clicked", "Failed to open file for reading");
        return;
    }

    QTextStream inStream(&file);
    QString line;
    int healthValue=0;
    int scoreValue=0;
    while (!inStream.atEnd())
    {
        line = inStream.readLine();
        // Process the line as needed
        QStringList tokens = line.split(" ");

        healthValue = tokens[0].toInt();
        scoreValue = tokens[1].toInt();
    }

    file.close();
    game = new Game(healthValue,scoreValue);
    game->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    qApp->quit();
}


void MainWindow::on_actionNew_Game_triggered()
{
    game = new Game(3,0);
    game->show();
}


void MainWindow::on_actionLoad_Game_triggered()
{
    QString filename = "./SaveGame.txt";

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "Button Clicked", "Failed to open file for reading");
        return;
    }

    QTextStream inStream(&file);
    QString line;
    int healthValue=0;
    int scoreValue=0;
    while (!inStream.atEnd())
    {
        line = inStream.readLine();
        // Process the line as needed
        QStringList tokens = line.split(" ");

        healthValue = tokens[0].toInt();
        scoreValue = tokens[1].toInt();
    }

    file.close();
    game = new Game(healthValue,scoreValue);
    game->show();
}


void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

