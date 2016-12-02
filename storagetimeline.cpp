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
    // call method to get tower contents from frame class
    //add new frame to the timeline
    int frameNum = getNumOfFrames();
    Frame * newFrame = new Frame();
    frames.append(Frame);
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

void storageTimeline::moveFrames(int startFrameNum, int endFrameNum, int newLocation)
{

}
