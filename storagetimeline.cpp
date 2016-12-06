#include "storagetimeline.h"

storageTimeline::storageTimeline()
{
   // add initial frame with default duration
    class Frame * newFrame;
    newFrame = new Frame(getNumOfFrames(), 0);
    frames.append(newFrame);
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
    // need to use getTowerContents from frame class (think keyframing)
    // need a place to set duration, if not defined use default from globals
    class Frame * newFrame;
    newFrame = new Frame(getNumOfFrames(), duration);
    frames.append(newFrame);
}

void storageTimeline::addFrame(Frame* frame)
{
    frames.append(frame);
}

void storageTimeline::removeFrame(int frameNum)
{
    // iterate through list until correct frame number is found

    int timelineSize = frames.size();

    for(int index=0; index<timelineSize; index++)
    {
       if(frames[index]->frameNumber==frameNum)
       {
           frames.removeAt(index);
       }
    }
}

void storageTimeline::moveFrames(int startFrameNum, int endFrameNum, int newLocation)
{

}

int storageTimeline::getNumOfFrames()
{
    // increment numOfFrames after, so return value before increment
    return numOfFrames++;
}

