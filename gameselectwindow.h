#ifndef GAMESELECTWINDOW_H
#define GAMESELECTWINDOW_H

#include <QMainWindow>

namespace Ui {
class GameSelectWindow;
}

class GameSelectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSelectWindow(QWidget *parent = 0);
    ~GameSelectWindow();

private slots:
    void on_pushAI_clicked();

    void on_pushDouble_clicked();

    void on_pushOut_clicked();

private:
    Ui::GameSelectWindow *ui;
};

extern int mood;

#endif // GAMESELECTWINDOW_H
