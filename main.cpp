// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <list> //STL链表
#include "mainwindow.h" //前端
#include "gamewindow.h"
#include "gameselectwindow.h"
#include "Player.h" //后端处理
#include "Chess.h"
#include "System.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MainWindow::s->read_file(); //读信息到链表中

    return a.exec();
}
