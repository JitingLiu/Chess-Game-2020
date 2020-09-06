#ifndef PLAYER_CENTER_H
#define PLAYER_CENTER_H

#include <QMainWindow>

namespace Ui {
class Player_center;
}

class Player_center : public QMainWindow
{
    Q_OBJECT

public:
    explicit Player_center(QWidget *parent = 0);
    ~Player_center();

private slots:
    void on_pushButton_Game_clicked();

    void on_pushButton_know_clicked();

    void on_pushButton_clicked();

private:
    Ui::Player_center *ui;
    void showDialog_change();
};

#endif // PLAYER_CENTER_H
