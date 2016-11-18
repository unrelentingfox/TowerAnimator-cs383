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
/*Parser for TAN2 filetype */

//Path to  the tan file on your local machine
QString F_Name = "C:/Users/Alex/Documents/parser (2)/title2012.tan";

//declarations
int LIST_InsertHeadNode(Pixel_List_N **, int, int, int, int, int);
int ver2 = 0;

void write(Pixel_List_N *head)
{
    QString filename = "out.txt";
    QFile file(filename);
    int arr[3][6] = {{1,2,43,6,7,4},{2,3,5,43,3,4},{6,7,2,1,63,24}};
    /*for(int p = 0; p < 3; p++){
        for(int q = 0; q < 6; q++){
            arr[height][width] = height + width;
        }
    }*/
    int height = 798, width = 12;
    int headarr[height][width];
    for(int y = 0; y < height; y++){
        for(int z = 0; z < width; z++){
            headarr[y][z] = y + z;
        }
    }
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // We're going to streaming text to the file
        QTextStream stream( &file );
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                stream << headarr[i][j] << " ";
            }
            stream << endl;
            if((i+1) % 10 == 0){
                stream << endl;
            }
        }
        file.close();
    }
    //qDebug() << "Writing finished";
}

void read()
{

    QFile file(F_Name);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        //Create struct to store height, width and frame count
       Layout_N grid;
       // Stream the file into text
       QTextStream stream(&file);

       QString line = NULL;
       //Deal with first four lines of input
       //Version number will tell us what format of timestamp to expect
       line = stream.readLine();
       QByteArray first_line = line.toLatin1();
       int ver1;
       char *version = first_line.data();
       char *ver_pt = NULL;
       ver_pt = strtok(version, ".");
     if(ver_pt != NULL)
       {
           ver1 = atoi(ver_pt);
           ver_pt = strtok(NULL, " ");
           ver2 = atoi(ver_pt);
           printf("Version Number: %d.%d\n", ver1, ver2);
       }
       //disregard the 3 lines of color pallete info
        line = stream.readLine();
        line = stream.readLine();
        line = stream.readLine();

    if(ver2 == 4){
        //frame count and window dimentions need to split up the 3 pieces of information to pass on
        line = stream.readLine()+ '\n';

        QByteArray lin = line.toLatin1();
        char *i_str = lin.data();
        char *frame_pt = NULL;
        frame_pt = strtok(i_str, " ");

        if(frame_pt != NULL)
             {
                int a, b, c;

                //Get the number of frames
                a = atoi(frame_pt);
                grid.Frame_ct = a;
                printf ("this should be frame_ct %s\n", frame_pt);

                //Get the height of input file
                frame_pt = strtok(NULL, " ");
                b = atoi(frame_pt);
                grid.Height= b;
                printf ("this should be height %s\n", frame_pt);

                //Get the width of the input file
                frame_pt = strtok(NULL, " ");
                c = atoi(frame_pt);
                grid.Width= c;
                printf ("this should be width %s\n", frame_pt);

             }


        int* MS = new int[grid.Frame_ct];
        int ct = 0;  //Int to place frame number in each pixel
        do {
            line=stream.readLine(); //frame start time

                //Read in the frame time stamp
                QByteArray time_1 = line.toLatin1();
                int ms_1;
                char *time1_str = time_1.data();
                char *ms_pt = NULL;
                ms_pt = strtok(time1_str, " ");

                if(ms_pt != NULL)
                {
                    ms_1 = atoi(ms_pt);
                    printf("milliseconds: %d\n", ms_1);
                }
                //int* MS_1 = new int[grid.Frame_ct];
                MS[ct] = ms_1;


            //This loop will iterate through the frame and populate the linked list based on the height and width of the input file
            //Skip the first 5 lines of empty pixels from the file
                line=stream.readLine();
                line=stream.readLine();
                line=stream.readLine();
                line=stream.readLine();
                line=stream.readLine();
                int y = 0; //y position value for linked list
            for(int j = 0; j < grid.Height; j++){  //Each frame consists of 10 lines
                int r, g, b; //integer values for the red, green and blue values of pixels
                int x = 0;  //x value to be passed for position

                line=stream.readLine();

                QByteArray lin = line.toLatin1();
                char *c_str = lin.data();
                char *pt = NULL;
                pt = strtok(c_str, " ");
                int width = 0;
            while(pt != NULL){
                //skip first 4 pixels in each row
              for(width = 0; width < grid.Width; width++)
              {
                  pt = strtok(NULL, " ");
                  pt = strtok(NULL, " ");
                  pt = strtok(NULL, " ");
              }
                //save the next 4 pixels in the line
                for(width = 0; width < grid.Width; width++)
                {

                r = atoi(pt);  //Red color value
                pt = strtok(NULL, " ");

                g = atoi(pt);  //Green color value
                pt = strtok(NULL, " ");

                b = atoi(pt); //Blue color value
                pt = strtok(NULL, " ");


               /* Insert info into new pixel linked-list node. */
                Pixel_List_N *listHead = NULL;
                LIST_InsertHeadNode(&listHead, r, g, b, x, y, ct+1);
                PrintPixels(listHead);
                x++; //increment the X position value
                }
                //discard the last 4 pixels in the line
                for(width = 0; width < grid.Width; width++)
                {
                    pt = strtok(NULL, " ");
                    pt = strtok(NULL, " ");
                    pt = strtok(NULL, " ");
                }
            }
                y++; //increment the y value of the pixel

          }
            //skip the last 5 lines of the frame
            line=stream.readLine();
            line=stream.readLine();
            line=stream.readLine();
            line=stream.readLine();
            line=stream.readLine();

            ct++; //increment the frame number counter
            }while(!line.isNull());

       }
else{
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
        Pixel_List_N *listHead = NULL;
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

            //int *a;
            //Pixel_List_N *listHead = NULL;
            LIST_InsertHeadNode(&listHead, r, g, b, x, y, ct+1);

            //printf("test");
            //a = PrintPixels(listHead);
            PrintPixels(listHead);
            //getR(listHead);

            /*QString filename = "out.txt";
            QFile file(filename);
            if(file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                // We're going to streaming text to the file

                QTextStream stream( &file );
                for(int i = 0; i < 1000; i++){
                    stream << a[i] << endl;
                    //printf("a[i]: %d", a[i]);
                }
                file.close();
                //qDebug() << "Writing finished";
            }*/
            x++; //increment the X position value
        }
            y++; //increment the y value
      }
            write(listHead);
            ct++; //increment the frame counter
            }while(!line.isNull());

   }



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

    //write();
    read();


    return a.exec();
}



