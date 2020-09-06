/********************************************************************************
** Form generated from reading UI file 'player_center.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_CENTER_H
#define UI_PLAYER_CENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player_center
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_Game;
    QPushButton *pushButton_word;
    QPushButton *pushButton_know;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Player_center)
    {
        if (Player_center->objectName().isEmpty())
            Player_center->setObjectName(QStringLiteral("Player_center"));
        Player_center->resize(800, 600);
        centralwidget = new QWidget(Player_center);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 791, 551));
        label->setAutoFillBackground(true);
        label->setPixmap(QPixmap(QString::fromUtf8("background.jpg")));
        label->setScaledContents(true);
        pushButton_Game = new QPushButton(centralwidget);
        pushButton_Game->setObjectName(QStringLiteral("pushButton_Game"));
        pushButton_Game->setGeometry(QRect(150, 220, 161, 51));
        pushButton_word = new QPushButton(centralwidget);
        pushButton_word->setObjectName(QStringLiteral("pushButton_word"));
        pushButton_word->setGeometry(QRect(150, 290, 161, 51));
        pushButton_know = new QPushButton(centralwidget);
        pushButton_know->setObjectName(QStringLiteral("pushButton_know"));
        pushButton_know->setGeometry(QRect(150, 360, 161, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(369, 290, 171, 51));
        Player_center->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Player_center);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 18));
        Player_center->setMenuBar(menubar);
        statusbar = new QStatusBar(Player_center);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Player_center->setStatusBar(statusbar);

        retranslateUi(Player_center);

        QMetaObject::connectSlotsByName(Player_center);
    } // setupUi

    void retranslateUi(QMainWindow *Player_center)
    {
        Player_center->setWindowTitle(QApplication::translate("Player_center", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        pushButton_Game->setText(QApplication::translate("Player_center", "\350\277\233\345\205\245\346\270\270\346\210\217", Q_NULLPTR));
        pushButton_word->setText(QApplication::translate("Player_center", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        pushButton_know->setText(QApplication::translate("Player_center", "\351\230\205\350\257\273\350\257\264\346\230\216", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Player_center", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Player_center: public Ui_Player_center {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_CENTER_H
