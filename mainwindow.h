#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "System.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static System* s;
private slots:
    void on_push_out_clicked();

private:
    Ui::MainWindow *ui;
    void showDialog_register();
    void showDialog_login();

};



#endif // MAINWINDOW_H
