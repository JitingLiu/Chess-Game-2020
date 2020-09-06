/********************************************************************************
** Form generated from reading UI file 'dialog_register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_REGISTER_H
#define UI_DIALOG_REGISTER_H

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

class Ui_Dialog_Register
{
public:
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QLineEdit *lineEdit_mail;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit_word;
    QLineEdit *lineEdit_name;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_Register)
    {
        if (Dialog_Register->objectName().isEmpty())
            Dialog_Register->setObjectName(QStringLiteral("Dialog_Register"));
        Dialog_Register->resize(626, 656);
        Dialog_Register->setStyleSheet(QStringLiteral(""));
        textBrowser_2 = new QTextBrowser(Dialog_Register);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(110, 240, 181, 61));
        textBrowser_3 = new QTextBrowser(Dialog_Register);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(110, 330, 181, 71));
        lineEdit_mail = new QLineEdit(Dialog_Register);
        lineEdit_mail->setObjectName(QStringLiteral("lineEdit_mail"));
        lineEdit_mail->setGeometry(QRect(310, 330, 211, 71));
        textBrowser = new QTextBrowser(Dialog_Register);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(110, 150, 181, 61));
        lineEdit_word = new QLineEdit(Dialog_Register);
        lineEdit_word->setObjectName(QStringLiteral("lineEdit_word"));
        lineEdit_word->setGeometry(QRect(310, 240, 211, 61));
        lineEdit_name = new QLineEdit(Dialog_Register);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(310, 150, 211, 61));
        pushButton = new QPushButton(Dialog_Register);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 250, 71, 41));

        retranslateUi(Dialog_Register);

        QMetaObject::connectSlotsByName(Dialog_Register);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Register)
    {
        Dialog_Register->setWindowTitle(QApplication::translate("Dialog_Register", "Dialog", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("Dialog_Register", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        textBrowser_3->setHtml(QApplication::translate("Dialog_Register", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\351\202\256\347\256\261</span></p></body></html>", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Dialog_Register", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog_Register", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Register: public Ui_Dialog_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_REGISTER_H
