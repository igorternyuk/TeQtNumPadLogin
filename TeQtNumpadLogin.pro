#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T19:03:22
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++1z
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeQtNumpadLogin
TEMPLATE = app


SOURCES += main.cpp\
        numpadlogindialog.cpp \
    mainwindow.cpp \
    button.cpp

HEADERS  += numpadlogindialog.hpp \
    mainwindow.hpp \
    button.hpp

FORMS    += numpadlogindialog.ui \
    mainwindow.ui
