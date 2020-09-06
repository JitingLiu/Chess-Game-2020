#include "dialog_login.h"
#include "ui_dialog_login.h"

Dialog_Login::Dialog_Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Login)
{
    ui->setupUi(this);
}

Dialog_Login::~Dialog_Login()
{
    delete ui;
}


QString Dialog_Login::getinput_name()
{
    QString s = ui->lineEdit_name->text();
    return s;
}

QString Dialog_Login::getinput_word()
{
    QString s = ui->lineEdit_word->text();
    return s;
}

void Dialog_Login::on_pushButton_clicked()
{
    this->close();
}
