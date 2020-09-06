#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "System.h"
#include "dialog_login.h"
#include "dialog_register.h"
#include <QMessageBox>
#include "player_center.h"
System* MainWindow::s = new System();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 800, 600 ));
    connect(ui->push_register, &QPushButton::clicked, this, &MainWindow::showDialog_register);
    connect(ui->push_login, &QPushButton::clicked, this, &MainWindow::showDialog_login);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showDialog_register()
{
    Dialog_Register dialog;
    dialog.exec();

    System* system = MainWindow:: s;
    std::string name = dialog.getinput_name().toStdString();
    std::string word = dialog.getinput_word().toStdString();
    std::string mail = dialog.getinput_mail().toStdString();


    if(!name.size() || !word.size() || !mail.size()){ //有信息为空
        QMessageBox msg(this); //对话框设置父组件
        msg.setWindowTitle("Error!"); //对话框标题
        msg.setText("输入不能为空！请重新输入或退出注册"); //对话框提示文本
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::No);//对话框上的按钮
        if(msg.exec() == QMessageBox::No){ //退出注册
            return;
        }
    }

    QMessageBox msg(this); //对话框设置父组件
    msg.setWindowTitle("Hello!"); //对话框标题
    if(system->register_player(name, word, mail)){ //注册成功
        msg.setText("注册成功!请返回登录"); //对话框提示文本
        msg.setStandardButtons(QMessageBox::Ok);//对话框上的按钮
        if(msg.exec() == QMessageBox::Ok){ //退出注册
            return ;
        }
    }
    else{
        msg.setText("注册失败!用户重名...(Y-继续注册)"); //对话框提示文本
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::No);//对话框上的按钮
        if(msg.exec() == QMessageBox::No){ //退出注册
            return ;
        }
    }


}

void MainWindow::showDialog_login()
{
    Dialog_Login dialog;
    dialog.exec();

    System* system = MainWindow:: s;
    std::string name = dialog.getinput_name().toStdString();
    std::string word = dialog.getinput_word().toStdString();


    if(!name.size() || !word.size()){ //有信息为空
        QMessageBox msg(this); //对话框设置父组件
        msg.setWindowTitle("Error!"); //对话框标题
        msg.setText("输入不能为空！请重新输入或退出"); //对话框提示文本
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::No);//对话框上的按钮
        if(msg.exec() == QMessageBox::No){ //退出登录
            this->close();
            return;
        }
    }
    else{
        QMessageBox msg(this); //对话框设置父组件
        msg.setWindowTitle("Hello!"); //对话框标题
        msg.setStandardButtons(QMessageBox::Ok);//对话框上的按钮
        if(system->log_in(name, word)){ //登录成功
            msg.setText("登录成功!"); //对话框提示文本
            if(msg.exec() == QMessageBox::No){ //退出注册
                return ;
            }
            this->close();
            Player_center* p = new Player_center();
            p->show();
            return;
        }
        else {
            msg.setText("登录失败!用户或密码错误"); //对话框提示文本
            this->close();
            if(msg.exec() == QMessageBox::No){ //退出注册
                return ;
            }
        }
    }

}

void MainWindow::on_push_out_clicked()
{
    MainWindow::s->write_file(); //存储信息
    this->close();
}
