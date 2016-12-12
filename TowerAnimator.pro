#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T11:48:43
#
#-------------------------------------------------

QT       += core gui \
            testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerAnimator
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    animationview.cpp \
    storagetimeline.cpp \
    timelinegraphics.cpp \
    pixel.cpp \
    object.cpp \
    algorithms.cpp \
    frame.cpp \
    timelineview.cpp \
    read.cpp \
    write.cpp
    read.cpp

HEADERS  += mainwindow.h \
    global.h \
    animationview.h \
    storagetimeline.h \
    timelinegraphics.h \
    pixel.h \
    object.h \
    algorithms.h \
    frame.h \
    struct.h \
    timelineview.h \
    read.h \
    write.h
    read.h

FORMS    += mainwindow.ui

DISTFILES += \
    .gitignore

QMAKE_CXXFLAGS += -fpermissive
