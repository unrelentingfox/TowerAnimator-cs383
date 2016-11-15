#include "storagetimeline.h"

storageTimeline::storageTimeline()
{
   // constructor
}

storageTimeline::~storageTimeline()
{
   // use with caution
}

void storageTimeline::addFrame(double duration)
{
    //add new frame to the timeline
    frames.append(storageFrame(duration, currFrame));
}

void storageTimeline::removeFrame(int frameNum)
{
    // iterate through list until correct frame number is found
    QLinkedList<storageFrame>::iterator i = frames.begin();

    while(i != frames.end())
    {
        if(i->frameNum == frameNum){
            frames.erase(i);
            break;
        }
        i++;
    }
}


