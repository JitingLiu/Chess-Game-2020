/********************************************************************************
** Form generated from reading UI file 'dialog_change.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CHANGE_H
#define UI_DIALOG_CHANGE_H

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

class Ui_Dialog_Change
{
public:
    QLineEdit *lineEdit_word;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_Change)
    {
        if (Dialog_Change->objectName().isEmpty())
            Dialog_Change->setObjectName(QStringLiteral("Dialog_Change"));
        Dialog_Change->resize(400, 300);
        lineEdit_word = new QLineEdit(Dialog_Change);
        lineEdit_word->setObjectName(QStringLiteral("lineEdit_word"));
        lineEdit_word->setGeometry(QRect(200, 140, 191, 61));
        textBrowser = new QTextBrowser(Dialog_Change);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 140, 151, 61));
        pushButton = new QPushButton(Dialog_Change);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 220, 80, 41));

        retranslateUi(Dialog_Change);

        QMetaObject::connectSlotsByName(Dialog_Change);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Change)
    {
        Dialog_Change->setWindowTitle(QApplication::translate("Dialog_Change", "Dialog", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Dialog_Change", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">\346\226\260\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog_Change", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Change: public Ui_Dialog_Change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CHANGE_H
