#ifndef DIALOG_CHANGE_H
#define DIALOG_CHANGE_H

#include <QDialog>

namespace Ui {
class Dialog_Change;
}

class Dialog_Change : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Change(QWidget *parent = 0);
    ~Dialog_Change();
    QString getinput_word();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Change *ui;
};

#endif // DIALOG_CHANGE_H
