#ifndef TIMELINE
#define TIMELINE

#include <stdio>

#include "frame.h"

class timeline {

   public:
   timeline();
   ~timeline();
   int deleteFrame();
   int duplicateFrame();
   int selectFrame();
   int moveFrame();
   int modifyFrame();
   int loadFrames();

   private:
   int findFrame();
   timelineFrame newFrame(int id);
   
   struct timelineFrame {
      frame f;  //frame class
      int id;
      struct frame * next;
   }

   typedef struct timelineFrame timelineFrame;

   timelineFrame* head;

};
      
   

#endif
