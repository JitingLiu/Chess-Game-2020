/********************************************************************************
** Form generated from reading UI file 'dialog_1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_1_H
#define UI_DIALOG_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_1
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dialog_1)
    {
        if (Dialog_1->objectName().isEmpty())
            Dialog_1->setObjectName(QStringLiteral("Dialog_1"));
        Dialog_1->resize(800, 600);
        menubar = new QMenuBar(Dialog_1);
        menubar->setObjectName(QStringLiteral("menubar"));
        Dialog_1->setMenuBar(menubar);
        centralwidget = new QWidget(Dialog_1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Dialog_1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Dialog_1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Dialog_1->setStatusBar(statusbar);

        retranslateUi(Dialog_1);

        QMetaObject::connectSlotsByName(Dialog_1);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog_1)
    {
        Dialog_1->setWindowTitle(QApplication::translate("Dialog_1", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_1: public Ui_Dialog_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_1_H
