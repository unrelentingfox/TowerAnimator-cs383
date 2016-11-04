#ifndef FRAME
#define FRAME

#include <stdio>

#define ABSOLUTE_FRAME_HEIGHT 10
#define ABSOLUTE_FRAME_WIDTH  4

#define MAX_FRAME_HEIGHT 20
#define MAX_FRAME_WIDTH 8

class frame {

   public:
   frame();
   int setColor();
   int setStartTime();
   int setStopTime();
   int getColors();
   int getStartTime();
   int getStopTime();
   

   private:
   struct frame {
      int colors[ABSOLUTE_FRAME_HEIGHT][ABSOLUTE_FRAME_WIDTH];
      int startTime;
      int endTime;
   } 
   
};

#endif
