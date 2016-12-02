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
    //int frameNum = getNumOfFrames();
    class Frame * newFrame;
    newFrame = new Frame(0, 0);
    frames.append(newFrame);
}

void storageTimeline::removeFrame(int frameNum)
{/*
    // USE i.operator *()->
    // iterate through list until correct frame number is found
    QList<class Frame>::iterator i = frames.begin();

    while(i != frames.end())
    {
        if(i.operator *->frameNumber == frameNum){
            frames.erase(i);
            break;
        }
        i++;
    }*/
}

void storageTimeline::moveFrames(int startFrameNum, int endFrameNum, int newLocation)
{

}
