#include "mainwindow.h"
#include "struct.h"
#include "read.h"
#include "write.h"
#include <QApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <QString>
#include<QList>
#include<QTCore>








int main(int argc, char *argv[])
{
    //pixel frame[4][10];

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //write();
    read();


    return a.exec();
}



