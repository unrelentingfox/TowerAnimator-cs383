
#include "timeline.h"
#include "frame.h"
#include "object.h"

Timeline::Timeline()
{

}

Timeline::~Timeline()
{
    //use with caution
    delete Timeline;
)

void Timeline::addFrame(double duration)
{
    newFrame = new Frame(duration, Timeline->currFrame);
    frames.append(newFrame);
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


