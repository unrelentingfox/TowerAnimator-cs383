#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T11:48:43
#
#-------------------------------------------------

QT       += core gui
QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerAnimator
TEMPLATE = app

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animationgraphicsview.cpp

HEADERS  += mainwindow.h \
    animationgraphicsview.h \
    global.h

FORMS    += mainwindow.ui

DISTFILES += \
    .gitignore
