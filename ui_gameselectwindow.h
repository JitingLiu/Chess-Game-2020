/********************************************************************************
** Form generated from reading UI file 'gameselectwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESELECTWINDOW_H
#define UI_GAMESELECTWINDOW_H

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

class Ui_GameSelectWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushDouble;
    QPushButton *pushAI;
    QPushButton *pushOut;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameSelectWindow)
    {
        if (GameSelectWindow->objectName().isEmpty())
            GameSelectWindow->setObjectName(QStringLiteral("GameSelectWindow"));
        GameSelectWindow->resize(526, 408);
        centralwidget = new QWidget(GameSelectWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 521, 381));
        label->setAutoFillBackground(true);
        label->setPixmap(QPixmap(QString::fromUtf8("background.jpg")));
        label->setScaledContents(true);
        pushDouble = new QPushButton(centralwidget);
        pushDouble->setObjectName(QStringLiteral("pushDouble"));
        pushDouble->setGeometry(QRect(120, 220, 141, 41));
        pushAI = new QPushButton(centralwidget);
        pushAI->setObjectName(QStringLiteral("pushAI"));
        pushAI->setGeometry(QRect(120, 150, 141, 51));
        pushOut = new QPushButton(centralwidget);
        pushOut->setObjectName(QStringLiteral("pushOut"));
        pushOut->setGeometry(QRect(120, 280, 141, 41));
        GameSelectWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameSelectWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 526, 18));
        GameSelectWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GameSelectWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GameSelectWindow->setStatusBar(statusbar);

        retranslateUi(GameSelectWindow);

        QMetaObject::connectSlotsByName(GameSelectWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameSelectWindow)
    {
        GameSelectWindow->setWindowTitle(QApplication::translate("GameSelectWindow", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        pushDouble->setText(QApplication::translate("GameSelectWindow", "\347\216\251\345\256\266\346\250\241\345\274\217", Q_NULLPTR));
        pushAI->setText(QApplication::translate("GameSelectWindow", "\344\272\272\346\234\272\345\257\271\346\210\230", Q_NULLPTR));
        pushOut->setText(QApplication::translate("GameSelectWindow", "\351\200\200\345\207\272\346\270\270\346\210\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameSelectWindow: public Ui_GameSelectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESELECTWINDOW_H
