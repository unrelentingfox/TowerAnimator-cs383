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
    // call method to get tower contents from frame class
    //add new frame to the timeline
    //int frameNum = getNumOfFrames();
    // need to use getTowerContents from frame class (think keyframing)
    // need a place to set duration, if not defined use default from globals
    class Frame * newFrame;
    newFrame = new Frame(getNumOfFrames(), duration);
    frames.append(newFrame);
    numOfFrames++;
}

void storageTimeline::addFrame(Frame* frame)
{
    frames.append(frame);
    numOfFrames++;
}

void storageTimeline::removeFrame(int frameNum)
{
    // iterate through list until correct frame number is found

//    int timelineSize = frames.size();

//    for(int index=0; index<timelineSize; index++)
//    {
//       if(frames[index]->frameNumber==frameNum)
//       {
//           frames.removeAt(index);
//       }
//    }
    frames.removeAt(frameNum);
    numOfFrames--;
}

void storageTimeline::moveFrames(int startFrameNum, int endFrameNum, int newLocation)
// if startFrameNum and endFrameNum are the same, function will move one frame
{
    int timelineSize = frames.size();
    int i = 0;

    while (i<timelineSize && frames[i]->frameNumber != newLocation)
        i++;

    for(int j=0; j<timelineSize; j++)
    {
        if (frames[j]->frameNumber == startFrameNum)
        {
            // move frame from current location, append after newLocation
            do{
                // move( from, to)
                frames.move(j, i);
                i++;
            }while(frames[j]->frameNumber != endFrameNum);
        }
    }
}

int storageTimeline::getNumOfFrames()
{
    // increment numOfFrames after, so return value before increment
    return numOfFrames;
}

