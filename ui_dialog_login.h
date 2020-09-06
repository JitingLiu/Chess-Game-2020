/********************************************************************************
** Form generated from reading UI file 'dialog_login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_LOGIN_H
#define UI_DIALOG_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Login
{
public:
    QTextBrowser *textBrowser_name;
    QTextBrowser *textBrowser_2;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_word;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_Login)
    {
        if (Dialog_Login->objectName().isEmpty())
            Dialog_Login->setObjectName(QStringLiteral("Dialog_Login"));
        Dialog_Login->resize(538, 316);
        textBrowser_name = new QTextBrowser(Dialog_Login);
        textBrowser_name->setObjectName(QStringLiteral("textBrowser_name"));
        textBrowser_name->setGeometry(QRect(40, 110, 161, 61));
        textBrowser_2 = new QTextBrowser(Dialog_Login);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(40, 190, 171, 61));
        lineEdit_name = new QLineEdit(Dialog_Login);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(240, 110, 181, 61));
        lineEdit_word = new QLineEdit(Dialog_Login);
        lineEdit_word->setObjectName(QStringLiteral("lineEdit_word"));
        lineEdit_word->setGeometry(QRect(240, 190, 181, 61));
        pushButton = new QPushButton(Dialog_Login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 160, 80, 51));

        retranslateUi(Dialog_Login);

        QMetaObject::connectSlotsByName(Dialog_Login);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Login)
    {
        Dialog_Login->setWindowTitle(QApplication::translate("Dialog_Login", "Dialog", Q_NULLPTR));
        textBrowser_name->setHtml(QApplication::translate("Dialog_Login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\347\224\250\346\210\267</span></p></body></html>", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("Dialog_Login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog_Login", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Login: public Ui_Dialog_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_LOGIN_H
