#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "Chess.h"
namespace Ui {
    class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void paintEvent(QPaintEvent* event); //绘图
    void mouseMoveEvent(QMouseEvent *event); //鼠标移动事件
    void mouseReleaseEvent(QMouseEvent* event); // 实际落子
    bool is_win(Position& pos, int player, char flag); //判断具体哪位玩家赢
    Chess* get_game()
    {
        return game;
    }
private:
    Ui::GameWindow *ui;
    Chess* game; // 游戏

};

extern int moveX, moveY, lastx, lasty;

#endif // GAMEWINDOW_H
