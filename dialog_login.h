#ifndef DIALOG_LOGIN_H
#define DIALOG_LOGIN_H

#include <QDialog>

namespace Ui {
class Dialog_Login;
}

class Dialog_Login : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Login(QWidget *parent = 0);
    ~Dialog_Login();
    QString getinput_name();
    QString getinput_word();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Login *ui;
};

#endif // DIALOG_LOGIN_H
