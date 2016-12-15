#include "read.h"
#include "struct.h"


readfile::readfile()
{
    loading = false;
}

int readfile::read(QString F_Name)
{
  QTextStream out(stdout);
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
    int ver1, ver2;
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

        int* MS = new int[grid.Frame_ct];
        MS[0] = 0;

        //Int to place frame number in each pixel
        int frame_ct = 0;
        line=stream.readLine();//initial frame start time
        MS[frame_ct] = 0;
        frame_ct++;
        do
        {
          loading = true;
          int ms_1;
          int duration = 0;

          //printf("duration: = %d\n", duration);

          //Create the Linked List that will store the individual frames.
          QLinkedList<Pixel_N> p_frame;

          //This loop will iterate through the frame and populate the linked list based on the height and width of the input file
          //Skip the first 5 lines of empty pixels from the file
          line=stream.readLine();
          line=stream.readLine();
          line=stream.readLine();
          line=stream.readLine();
          line=stream.readLine();
          int pix_y_val = 0; //y position value for linked list

          //Each frame consists of 10 lines
          for(int j = 0; j < grid.Height; j++)
          {
            int r, g, b; //integer values for the red, green and blue values of pixels
            int pix_x_val = 0;  //x value to be passed for position
            line=stream.readLine();
            QByteArray lin = line.toLatin1();
            char *c_str = lin.data();
            char *pt = NULL;
            pt = strtok(c_str, " ");
            int width = 0;
            while(pt != NULL)
            {
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

                /* Insert info into the pixel struct */
                Pixel_N pix;
                pix.R = r;
                pix.G = g;
                pix.B = b;
                pix.X = pix_x_val;
                pix.Y = pix_y_val;
                pix.CT = frame_ct;
                p_frame.append(pix);

                //increment the X position value
                pix_x_val++;
              }
              //discard the last 4 pixels in the line
              for(width = 0; width < grid.Width; width++)
              {
                pt = strtok(NULL, " ");
                pt = strtok(NULL, " ");
                pt = strtok(NULL, " ");
              }
            }
            //increment the y value of the pixel
            pix_y_val++;

          }
          //skip the last 5 lines of the frame
          line=stream.readLine();
          line=stream.readLine();
          line=stream.readLine();
          line=stream.readLine();
          line=stream.readLine();

          //Read in the frame time stamp
          line=stream.readLine();
          QByteArray time_1 = line.toLatin1();
          char *time1_str = time_1.data();
          char *ms_pt = NULL;
          ms_pt = strtok(time1_str, " ");
          if(ms_pt != NULL)
          {
            ms_1 = atoi(ms_pt);
            //printf("milliseconds: %d\n", ms_1);
          }
          //Set the frame duration
          MS[frame_ct] = ms_1;
          /* Frame duration = current timestamp - previous timestamp */
          duration =( MS[frame_ct] - MS[frame_ct - 1] );

          /*Print out the frame of 40 pixels*/
          //out << "Pixels contained in Frame# " << frame_ct+1 << endl;
          /* Create the frames of 40 pixels*/
          Frame* frame = new Frame(0, duration);
          for (Pixel_N pixel_n : p_frame)
          {
                 // out << "R:" << pixel_n.getRval() << ", "
                 //     << "G:" << pixel_n.getGval() << ", "
                 //     << "B:" << pixel_n.getBval() << ", "
                 //     << "X:" << pixel_n.getXval() << ", "
                 //     << "Y:" << pixel_n.getYval() << ", "
                 //     << endl;
              QColor color;
              color.setRed(pixel_n.getRval());
              color.setGreen(pixel_n.getGval());
              color.setBlue(pixel_n.getBval());

              if(!(color.red() == 0 && color.green() == 0 && color.blue() == 0 )){
                Pixel* p = new Pixel(pixel_n.getXval() * Globals::GRID_SIZE + Globals::TOWER_POSITION_X, pixel_n.getYval() * Globals::GRID_SIZE + Globals::TOWER_POSITION_Y, Globals::PIXEL_SIZE, color);
                frame->addPixel(p);
              }
           }
           emit loadFrame(frame);
           //increment the frame number counter

           if(frame_ct % 100 == 0)
               QTest::qWait(1);
           frame_ct++;
       }while(!line.isNull());
       loading = false;
     }
      file.close();
      return 0;
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

     int frame_ct = 0;  //total number of frames
     int totalMS = 0;
     int duration = 0;   
     int* MS = new int[grid.Frame_ct];
     MS[0] = 0;
     MS[frame_ct] = totalMS;
     line=stream.readLine();//initial frame start time
     MS[frame_ct] = 0;
     frame_ct++;

     do
     {
       loading = true;
      //Create the Linked List that will store the individual frames.
      QLinkedList<Pixel_N> p_frame;
      int pix_y_val = 0; //y position value for linked list
      //populate the pixel struct with info
      for(int j = 0; j < 10; j++) //Each frame consists of 10 lines
      {
        int r, g, b; //integer values for the red, green and blue values of pixels
        int pix_x_val = 0;  //x value to be passed for position
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

          /* Insert info into the pixel struct */

          Pixel_N pix;
          pix.R = r;
          pix.G = g;
          pix.B = b;
          pix.X = pix_x_val;
          pix.Y = pix_y_val;
          pix.CT = frame_ct;
          p_frame.append(pix);

          //increment the X position value
          pix_x_val++;
       }
       //increment the y value
       pix_y_val++;
      }
      //Print out the frame of 40 pixels

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
       //printf("min: %d", min);
       min_pt = strtok(NULL, ":.");
       sec = atoi(min_pt);
       //printf(", sec: %d", sec);
       min_pt = strtok(NULL, ".");
       ms = atoi(min_pt);
       //printf(", ms: %d\n", ms);
     }
     duration = totalMS;
     totalMS = min * 60000 + sec * 1000 + ms;
     duration = totalMS - duration;
     //printf("duration: = %d\n", duration);


     //printf("total milliseconds = %d\n", MS[frame_ct]);
     // out << "Pixels contained in Frame# " << frame_ct << endl;
      /*Printing out the linked list of 40 pixels that represents
      a frame...Used to confirm the linked list was created properly */
      Frame* frame = new Frame(0, duration);
      for (Pixel_N pixel_n : p_frame)
      {
//         qDebug() << "R:" << pixel_n.getRval() << ", "
//                  << "G:" << pixel_n.getGval() << ", "
//                  << "B:" << pixel_n.getBval() << ", "
//                  << "X:" << pixel_n.getXval() << ", "
//                  << "Y:" << pixel_n.getYval() << ", "
//                  << endl;
         QColor color;
         color.setRed(pixel_n.getRval());
         color.setGreen(pixel_n.getGval());
         color.setBlue(pixel_n.getBval());

         if(!(color.red() == 0 && color.green() == 0 && color.blue() == 0 )){
            Pixel* p = new Pixel(pixel_n.getXval() * Globals::GRID_SIZE + Globals::TOWER_POSITION_X, pixel_n.getYval() * Globals::GRID_SIZE + Globals::TOWER_POSITION_Y, Globals::PIXEL_SIZE, color);
            frame->addPixel(p);
         }

       }
       emit loadFrame(frame);

       if(frame_ct % 100 == 0)
           QTest::qWait(1);
        frame_ct++; //increment the frame counter
     }//while(frame_ct < 100);
     while(!line.isNull());
     loading = false;
   }

 }
  file.close();
  qDebug() << "Reading finished";
  return 0;
}
