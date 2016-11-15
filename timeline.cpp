#include "timeline.h"

Timeline::Timeline()
{
   // constructor
}

Timeline::~Timeline()
{
   // use with caution
}

void Timeline::addFrame(double duration)
{
    //add new frame to the timeline
    frames.append(Frame(duration, currFrame));
}

void Timeline::removeFrame(int frameNum)
{
    // iterate through list until correct frame number is found
    QLinkedList<Frame>::iterator i = frames.begin();

    while(i != frames.end())
    {
        if(i->frameNum == frameNum){
            frames.erase(i);
            break;
        }
        i++;
    }
}


