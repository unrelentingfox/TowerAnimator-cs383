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
QString F_Name = "C:/Users/colton/Documents/parser/title2012.tan";

//Declarations
int LIST_InsertHeadNode(Pixel_List_N **, int, int, int, int, int);
int ver2 = NULL;

void write()
{
  QFile file("C:/Test/simple.txt");
  if(file.open(QIODevice::WriteOnly | QIODevice::Text))
 {
   file.close();
   qDebug() << "Writing finished";
 }
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
     //Version number determines how to parse the file
     if(ver2 == 4)
     {
       //Populate a frame struct with the frame count and dimensions
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
      do
      {
        //Read in the frame time stamp
        line=stream.readLine();
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

        MS[ct] = ms_1;
        int y = 0; //y position value for linked list
        /*This loop will iterate through the frame and populate the linked list
        based on the height and width of the input file */
        for(int j = 0; j < 20; j++)//Each frame consists of 10 lines
        {
          int r, g, b; //integer values for the red, green and blue values of pixels
          int x = 0;  //x value to be passed for position
          line=stream.readLine();
          QByteArray lin = line.toLatin1();
          char *c_str = lin.data();
          char *pt = NULL;
          pt = strtok(c_str, " ");
          //printf("pt before loop: %s", pt);
          int width = 0;
          //Get RGB value for 12 pixel structs in each line
          while(pt != NULL)
          {
            for(width = 0; width < 12; width++)
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

         }
           y++; //increment the y value of the pixel

        }
          ct++; //increment the frame number counter
       }while(!line.isNull());

      }

   else
   {
     line = stream.readLine()+ '\n';
     QByteArray lin = line.toLatin1();
     char *i_str = lin.data();
     char *frame_pt = NULL;
     frame_pt = strtok(i_str, " ");
     if(frame_pt != NULL)
     {
       int a, b, c;
       //Read in the frame dimentions and count
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
     do
     {
       line=stream.readLine(); //frame start time
       /*Convert the old style time to the new format in milliseconds
       using ":" and "." as the respective delimiters */
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
      int y = 0; //y position value for linked list
      //populate the pixel struct with info
      for(int j = 0; j < 10; j++) //Each frame consists of 10 lines
      {
        int r, g, b; //integer values for the red, green and blue values of pixels
        int x = 0;  //x value to be passed for position
        line=stream.readLine();
        QByteArray lin = line.toLatin1();
        char *c_str = lin.data();
        char *pt = NULL;
        pt = strtok(c_str, " ");
        while(pt != NULL) //Populate the RGB values for the 4 pixel structs in the line
        {
          r = atoi(pt);  //Red color value
          pt = strtok(NULL, " ");
          g = atoi(pt);  //Green color value
          pt = strtok(NULL, " ");
          b = atoi(pt); //Blue color value
          pt = strtok(NULL, " ");
          /* Insert a linked-list node. */
          Pixel_List_N *listHead = NULL;
          LIST_InsertHeadNode(&listHead, r, g, b, x, y, ct+1);
          PrintPixels(listHead);
          x++; //increment the X position value
       }
         y++; //increment the y value
      }
        ct++; //increment the frame counter
     }while(!line.isNull());

   }



 }
   file.close();
   qDebug() << "Reading finished";
}



int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  // write();
  read();

  return a.exec();
}



