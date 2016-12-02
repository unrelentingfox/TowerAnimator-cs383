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

void storageTimeline::removeFrame(int frameNum)
{
    // Use i.operator *()->
    // iterate through list until correct frame number is found
//    QList<class Frame>::iterator i.operator*() = frames.begin();

//    while(i.operator*() != frames.end())
//    {
//        if(i.operator*()->frameNumber == frameNum){
//            frames.erase(i);
//            break;
//        }
//        i++;
//    }

/*    QMutableListIterator<int> iterator(frames);
    while(iterator.hasNext())
    {
        int val = iterator.next();
        if(val==frameNum)
        {
            iterator.remove();
        }
    }
*/
}

void storageTimeline::moveFrames(int startFrameNum, int endFrameNum, int newLocation)
{

}

int storageTimeline::getNumOfFrames()
{
    // increment numOfFrames after, so return value before increment
    return numOfFrames++;
}
