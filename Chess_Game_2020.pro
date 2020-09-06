#-------------------------------------------------
#
# Project created by QtCreator 2020-06-13T10:16:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess_Game_2020
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    gameselectwindow.cpp \
    Chess.cpp \
    Player.cpp \
    System.cpp \
    dialog_register.cpp \
    dialog_login.cpp \
    player_center.cpp \
    dialog_change.cpp \
    gamewindow.cpp

HEADERS += \
        mainwindow.h \
    gameselectwindow.h \
    Chess.h \
    Player.h \
    System.h \
    dialog_register.h \
    dialog_login.h \
    player_center.h \
    dialog_change.h \
    gamewindow.h

FORMS += \
        mainwindow.ui \
    gameselectwindow.ui \
    dialog_register.ui \
    dialog_login.ui \
    player_center.ui \
    dialog_change.ui \
    gamewindow.ui

DISTFILES +=

RESOURCES += \
    background.qrc
