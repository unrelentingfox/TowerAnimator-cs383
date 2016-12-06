#include "mainwindow.h"
#include "read.h"
#include <QApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <QString>
#include<QTCore>




int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //write();
    //read();


    return a.exec();
}



