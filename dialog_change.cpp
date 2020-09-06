#include "dialog_change.h"
#include "ui_dialog_change.h"

Dialog_Change::Dialog_Change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Change)
{
    ui->setupUi(this);
}

Dialog_Change::~Dialog_Change()
{
    delete ui;
}

QString Dialog_Change::getinput_word()
{
    QString s = ui->lineEdit_word->text();
    return s;
}

void Dialog_Change::on_pushButton_clicked()
{
    this->close();
}
