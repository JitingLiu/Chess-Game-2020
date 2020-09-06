#ifndef DIALOG_REGISTER_H
#define DIALOG_REGISTER_H

#include <QDialog>

namespace Ui {
class Dialog_Register;
}

class Dialog_Register : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Register(QWidget *parent = 0);
    ~Dialog_Register();
    QString getinput_name();
    QString getinput_word();
    QString getinput_mail();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Register *ui;
};

#endif // DIALOG_REGISTER_H
