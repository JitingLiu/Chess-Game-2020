#include "dialog_register.h"
#include "ui_dialog_register.h"

Dialog_Register::Dialog_Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Register)
{
     ui->setupUi(this);
     this->resize( QSize( 800, 600 ));
}

Dialog_Register::~Dialog_Register()
{
    delete ui;
}

QString Dialog_Register::getinput_name()
{
    QString s = ui->lineEdit_name->text();
    return s;
}

QString Dialog_Register::getinput_word()
{
    QString s = ui->lineEdit_word->text();
    return s;
}

QString Dialog_Register::getinput_mail()
{
    QString s = ui->lineEdit_mail->text();
    return s;
}
void Dialog_Register::on_pushButton_clicked()
{
    this->close();
}
