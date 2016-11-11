#include "mainwindow.h"
#include "struct.h"
#include <QApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <stdio.h>
#include <errno.h>
#include <string>
#include <QString>


//Path to  the tan file on your local machine
QString F_Name = "C:/Users/colton/Documents/parser/title2012.tan";

//declarations
int LIST_InsertHeadNode(Pixel_List_N **, int, int, int, int, int);



void write()
{
    QFile file("C:/Test/simple.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // We're going to streaming text to the file

        file.close();
        qDebug() << "Writing finished";
    }
}

void read()
{

    QFile file(F_Name);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
       Layout_N grid;
       // Stream the file into text
       QTextStream stream(&file);

       QString line = NULL;
       int i = 0;
       for(i = 0; i < 4; i++ )
       {
          line = stream.readLine()+ '\n';
          //printf ("%s\n", line);

        }
        //frame count and window dimentions need to split up the 3 pieces of information to pass on
        line = stream.readLine()+ '\n';

        QByteArray lin = line.toLatin1();
        char *i_str = lin.data();
        char *frame_pt = NULL;
        frame_pt = strtok(i_str, " ");

        if(frame_pt != NULL)
             {
                int a, b, c;

                a = atoi(frame_pt);
                grid.Frame_ct = a;
                printf ("this should be frame_ct %s\n", frame_pt);

                frame_pt = strtok(NULL, " ");
                b = atoi(frame_pt);
                grid.Height= b;
                printf ("this should be height %s\n", frame_pt);

                frame_pt = strtok(NULL, " ");
                c = atoi(frame_pt);
                grid.Width= c;
                printf ("this should be width %s\n", frame_pt);

             }



        int ct = 0;  //total number of frames
        do {
            line=stream.readLine(); //frame start time

            //Convert the old style time to the new format in milliseconds
            //Delimit the old time by ":" "."
            QByteArray time = line.toLatin1();
            int min, sec, ms;
            char *time_str = time.data();
            char *min_pt = NULL;
            min_pt = strtok(time_str, ":");

            if(min_pt != NULL)
            {
                min = atoi(min_pt);
                printf("min: %d", min);
                min_pt = strtok(NULL, ":.");
                sec = atoi(min_pt);
                printf(", sec: %d", sec);
                min_pt = strtok(NULL, ".");
                ms = atoi(min_pt);
                printf(", ms: %d\n", ms);
            }
            int totalMS = min * 60000 + sec * 1000 + ms;

            int* MS = new int[grid.Frame_ct];
            MS[ct] = totalMS;
            printf("total milliseconds = %d\n", MS[ct]);


            //populate the pixel struct with info
            int y = 0; //y position value for linked list
            //pixel count in each frame
            for(int j = 0; j < 10; j++){  //Each frame consists of 10 lines
            int r, g, b; //integer values for the red, green and blue values of pixels
            int x = 0;  //x value to be passed for position
            line=stream.readLine();

            QByteArray lin = line.toLatin1();
            char *c_str = lin.data();
            char *pt = NULL;
            pt = strtok(c_str, " ");

            while(pt != NULL)
            {         
                r = atoi(pt);  //Red color value
                pt = strtok(NULL, " ");

                g = atoi(pt);  //Green color value
                pt = strtok(NULL, " ");

                b = atoi(pt); //Blue color value
                pt = strtok(NULL, " ");


               /* Insert a linked-list node. */

                Pixel_List_N *listHead = NULL;
                LIST_InsertHeadNode(&listHead, r, g, b, x, y, ct);
                PrintPixels(listHead);
                x++; //increment the X position value
            }
                y++; //increment the y value
          }
                ct++; //increment the frame counter
                }while(!line.isNull());

       }

    file.close();
    qDebug() << "Reading finished";
}


int main(int argc, char *argv[])
{
    //pixel frame[4][10];

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // write();
     read();


    return a.exec();
}



