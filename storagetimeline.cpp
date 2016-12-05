#include "storagetimeline.h"

storageTimeline::storageTimeline()
{
   // add initial frame with default duration
    class Frame * newFrame;
    newFrame = new Frame(getNumOfFrames(), 0);
    frames.append(newFrame);
    numOfFrames = 1;
}

storageTimeline::~storageTimeline()
{
   // use with caution
}

void storageTimeline::addFrame(double duration)
{
    // add new frame to the timeline
    // need to use getTowerContents from frame class (think keyframing)
    // need a place to set duration, if not defined use default from globals
    class Frame * newFrame;
    newFrame = new Frame(getNumOfFrames(), duration);
    frames.append(newFrame);
    numOfFrames++;
    qDebug("Frame is added to storage timeline.");

}

void storageTimeline::getFrameTower()
// return type should be a list of pixel not void
{
    // call getTowerContents
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
    // increment numOfFrames in addFrame
    return numOfFrames;
}

