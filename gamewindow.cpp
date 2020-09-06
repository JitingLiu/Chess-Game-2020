//本文件为游戏窗口

#include <iostream>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPalette>
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "Chess.h"
#include "gameselectwindow.h"
#include "mainwindow.h"

using namespace std;

int moveX = 0, moveY = 0, lastx = 0, lasty = 0;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //设置界面大小和背景
    game = new Chess();
    this->setFixedSize(660,660);//设置窗口大小
    setWindowTitle("五子棋");
}

GameWindow::~GameWindow()
{
    delete ui;
}

int tag = 1; //表示当前玩家, 1 电脑/玩家一，0 玩家二

void GameWindow::mouseReleaseEvent(QMouseEvent* event) //下棋动作
{
    Position player1;   //玩家1或电脑
    Position player2;   //玩家2
    if (mood == 1 && tag ==1) //如果是AI模式并且是电脑执棋
    {
        game->AI_chess(player1, chessFlag1);
        // 如果是人机模式，需要调用AI下棋
        vec1.push_back(player1); //添加记录
        vec3.push_back(player1);
        update();//重绘
        lastx = player1.row; //记录最后下棋的位置
        lasty = player1.col;
        // 判断输赢
        if (is_win(player1, 1, chessFlag1)){ //玩家1或电脑
            game->Init_chessboard(); //清空
            update(); //再来一局
        }

    }
    else if (mood == 1 && tag == -1){ //如果是AI模式并且是玩家执棋
        player2.row = moveX;
        player2.col = moveY;
        if (game->judge_postition(player2) == 1){ //判断坐标是否合法
            game->take_step(player2, 2, chessFlag2); //玩家2走
            vec2.push_back(player2); //添加记录
            vec3.push_back(player2);
        }
        update();
        lastx = player2.row; //记录最后下棋的位置
        lasty = player2.col;
        // 判断输赢
        if (is_win(player2, 2, chessFlag2)){ //玩家2
            game->Init_chessboard(); //清空
            update(); //再来一局
        }
    }
    else if (mood == 2 && tag == 1){ //如果是双人模式并且是玩家一执棋
        player1.row = moveX;
        player1.col = moveY;
        if (game->judge_postition(player1) == 1) { //判断坐标是否合法
            game->take_step(player1, 1, chessFlag1); //玩家1走
        }
        update();//重绘
        lastx = player1.row; //记录最后下棋的位置
        lasty = player1.col;
        // 判断输赢
        if (is_win(player1, 1, chessFlag1)){ //玩家1或电脑
            game->Init_chessboard(); //清空
            update(); //再来一局
        }

    }
    else if (mood == 2 && tag == -1){ //如果是双人模式并且是玩家二执棋
        player2.row = moveX;
        player2.col = moveY;
        if (game->judge_postition(player2) == 1){ //判断坐标是否合法
            game->take_step(player2, 2, chessFlag2); //玩家2走
            vec2.push_back(player2); //添加记录
            vec3.push_back(player2);
        }
        update();
        lastx = player2.row; //记录最后下棋的位置
        lasty = player2.col;
        // 判断输赢
        if (is_win(player2, 2, chessFlag2)){ //玩家2
            game->Init_chessboard(); //清空
            update(); //再来一局
        }
    }

    tag = -tag;
}

bool GameWindow::is_win(Position& pos, int player, char flag) //判断具体哪位玩家赢
{
    if (game->judge_victory(pos, flag) != 0)
    {
        //判断有无人获胜
        if (game->judge_victory(pos, flag) == 1)
        {
            QString str;
            //判断是否有人获胜,1表示获胜
            if (player == 1) {
                str = "Black player"; //黑子是玩家1
            }
            else { // player == 2, 是玩家2
                str = "White player"; //白子是玩家2
            }
            //是否再来一局
            QMessageBox msg(this);//对话框设置父组件
            msg.setWindowTitle("Congratulations!");//对话框标题
            msg.setText(str +" win!\nAnother Game or Not?");//对话框提示文本
            msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: No );//对话框上的按钮
            if(msg.exec() == QMessageBox::Ok){ //如果再来一局
               game->Init_chessboard(); //清空
               update();
            }
            else{
                this->close(); //退出
            }
        }
        return true; //有人获胜

    }

    return false; //没人获胜 或者再来一局

}

void GameWindow::mouseMoveEvent(QMouseEvent *event) //鼠标移动事件
{

    moveX = (event->y()-40)/40;
    moveY = (event->x()-20)/40;
    update(); //更新后就重画
}

void GameWindow::paintEvent(QPaintEvent* event)
{
    //绘制棋盘边界边框，棋盘内颜色
    QPainter painter(this); //画板
    painter.setRenderHint(QPainter::Antialiasing,true); //抗锯齿

    this->setAutoFillBackground(true);
    QPalette palette ; //画背景色
    palette.setColor(QPalette::Background,QColor("#B1723C"));
    this->setPalette(palette);

    centralWidget()->setMouseTracking(true);//接受鼠标的移动
    setMouseTracking(true);

    QPen pen = painter.pen(); //画笔
    pen.setColor(QColor("#8D5822")); //棋盘边界边框
    pen.setWidth(7);
    painter.setPen(pen);

    QBrush brush; //画刷,棋盘内颜色
    brush.setColor(QColor("#EEC085"));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(20,40,600,600);

    //绘制棋盘
    pen.setColor(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen); //黑线
    for(int i = 0; i < 15; ++i)
    {
        painter.drawLine(40+i*40,60,40+i*40,620);//纵线，QT的坐标60最上，620最下
        painter.drawLine(40,60+i*40,600,60+i*40);//横线，QT的坐标40最左，600最右
    }

    //绘制棋盘中间的五个黑点
    brush.setColor(Qt::black); //五个小黑点
    painter.setBrush(brush);
    painter.drawRect(115,175,10,10);
    painter.drawRect(475,175,10,10);
    painter.drawRect(155,495,10,10);
    painter.drawRect(475,495,10,10);
    painter.drawRect(315,335,10,10);

    //循环遍历，画棋子
    painter.setPen(Qt::NoPen);  //去掉pen，避免画出的棋子边缘带线条
    for(int i=0; i < 15; ++i)
    {
        for(int j=0; j <15; ++j)
        {
            if(game->get_coordinate(i,j) == chessFlag1)//黑子,电脑或玩家1
            {
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                //在第i行，第j列画一个圆形
                painter.drawEllipse(QPoint((j+1)*40,(i+1)*40+20), 18, 18);
            }
            else if(game->get_coordinate(i,j) == chessFlag2)//白子，玩家2
            {
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(QPoint((j+1)*40,(i+1)*40+20), 18, 18);
            }
        }
    }

    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);
    //鼠标移动后，当前红方框标识
    if((moveX*40+40)>=20 && (moveX*40+40)<=620 && (moveY*40+20)>=40 && (moveY*40+20)<=640)
    {
        painter.drawLine((moveY+1)*40-20,(moveX+1)*40,(moveY+1)*40-10,(moveX+1)*40);
        painter.drawLine((moveY+1)*40+20,(moveX+1)*40,(moveY+1)*40+10,(moveX+1)*40);
        painter.drawLine((moveY+1)*40-20,(moveX+1)*40+40,(moveY+1)*40-10,(moveX+1)*40+40);
        painter.drawLine((moveY+1)*40+20,(moveX+1)*40+40,(moveY+1)*40+10,(moveX+1)*40+40);
        painter.drawLine((moveY+1)*40-20,(moveX+1)*40,(moveY+1)*40-20,(moveX+1)*40+10);
        painter.drawLine((moveY+1)*40+20,(moveX+1)*40,(moveY+1)*40+20,(moveX+1)*40+10);
        painter.drawLine((moveY+1)*40-20,(moveX+1)*40+40,(moveY+1)*40-20,(moveX+1)*40+30);
        painter.drawLine((moveY+1)*40+20,(moveX+1)*40+40,(moveY+1)*40+20,(moveX+1)*40+30);

    }
    //lastx,lasty记录最后一个落子的位置
    //画最后一个落子位置

    painter.drawLine((lasty+1)*40-6,(lastx+1)*40+20,(lasty+1)*40-1,(lastx+1)*40+20);
    painter.drawLine((lasty+1)*40+1,(lastx+1)*40+20,(lasty+1)*40+6,(lastx+1)*40+20);
    painter.drawLine((lasty+1)*40,(lastx+1)*40+14,(lasty+1)*40,(lastx+1)*40+19);
    painter.drawLine((lasty+1)*40,(lastx+1)*40+21,(lasty+1)*40,(lastx+1)*40+26);


}
