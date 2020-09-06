#include "player_center.h"
#include "ui_player_center.h"
#include "gameselectwindow.h"
#include "dialog_change.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "System.h"
#include <QString>
#include "gamewindow.h"
Player_center::Player_center(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player_center)
{
    ui->setupUi(this);
    this->resize( QSize( 800, 600 ));
    connect(ui->pushButton_word, &QPushButton::clicked, this, &Player_center::showDialog_change);
}

Player_center::~Player_center()
{
    delete ui;
}

void Player_center::on_pushButton_Game_clicked()
{
    this->close();
    GameSelectWindow* GW = new GameSelectWindow;
    GW->show();
}

void Player_center::showDialog_change()
{
    Dialog_Change dialog;
    dialog.exec();

    System* system = MainWindow:: s;
    std::string word = dialog.getinput_word().toStdString();


    if( !word.size()){ //有信息为空
        QMessageBox msg(this); //对话框设置父组件
        msg.setWindowTitle("Error!"); //对话框标题
        msg.setText("输入不能为空！请重新输入或退出"); //对话框提示文本
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::No);//对话框上的按钮
        if(msg.exec() == QMessageBox::No){ //退出
            return;
        }
    }
    else{
        QMessageBox msg(this); //对话框设置父组件
        msg.setWindowTitle("Hello!"); //对话框标题
        msg.setStandardButtons(QMessageBox::Ok);//对话框上的按钮
        if(system->change_Info(word, CMD_PASSWD)){ //登录成功
            msg.setText("成功!"); //对话框提示文本
            return;
        }
        else {
            msg.setText("失败!"); //对话框提示文本
            return;
        }
    }
}

void Player_center::on_pushButton_know_clicked()
{
    QMessageBox msg(this); //对话框设置父组件
    msg.setWindowTitle("规则!"); //对话框标题
    msg.setText("同色五子连在一起即获得胜利！"); //对话框提示文本
    msg.setStandardButtons(QMessageBox::Ok);//对话框上的按钮
    if(msg.exec() == QMessageBox::Ok){ //退出
        return;
    }
}

void Player_center::on_pushButton_clicked()
{
    this->close();
}



