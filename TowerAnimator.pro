#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T11:48:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerAnimator
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    animationview.cpp \
    frame.cpp \
    pixel.cpp \
    object.cpp \
    timeline.cpp

HEADERS  += mainwindow.h \
    global.h \
    animationview.h \
    frame.h \
    pixel.h \
    object.h \
    timeline.h

FORMS    += mainwindow.ui

DISTFILES += \
    .gitignore
