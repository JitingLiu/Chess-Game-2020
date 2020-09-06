#include "gameselectwindow.h"
#include "ui_gameselectwindow.h"
#include "gamewindow.h"
#include "mainwindow.h"

int mood = 0;

GameSelectWindow::GameSelectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSelectWindow)
{
    ui->setupUi(this);
}

GameSelectWindow::~GameSelectWindow()
{
    delete ui;
}

void GameSelectWindow::on_pushAI_clicked()
{
    this->close();
    GameWindow* GW = new GameWindow();
    GW->show();
    mood = 1; //单机模式
}

void GameSelectWindow::on_pushDouble_clicked()
{
    this->close();
    GameWindow* NGW = new GameWindow();
    NGW->show();
    mood = 2; //双人模式
}

void GameSelectWindow::on_pushOut_clicked()
{
    this->close();
    MainWindow w;
    w.show();
}
