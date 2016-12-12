#include "storagetimeline.h"


/**
 * @brief storageTimeline::storageTimeline is the timeline constructor
 * and creates a new empty frame and adds it to the frames list
 */
storageTimeline::storageTimeline()
{
   // add initial frame with default duration
    class Frame * newFrame;
    newFrame = new Frame(getNumOfFrames(), 0);
    frames.append(newFrame);
    numOfFrames = 1;
}

/**
 * @brief storageTimeline::~storageTimeline is the timeline destructor
 */
storageTimeline::~storageTimeline()
{
   // timeline destructor
}

/**
 * @brief storageTimeline::addFrame adds a frame to the timeline
 * It is an overloaded function.
 * This version takes the frame duration as an argument
 * and sets the frame number frameNum to the value retrieved
 * using the private function getNumOfFrames, which
 * represents the total number of frames created since
 * the timeline was initialized.
 * @param double duration which specifies how long a frame should be displayed
 * @return void
 */
void storageTimeline::addFrame(double duration)
{
    class Frame * newFrame;
    newFrame = new Frame(getNumOfFrames(), duration);
    frames.append(newFrame);
    numOfFrames++;
}

/**
 * @brief storageTimeline::addFrame adds a frame to the timeline
 * It is an overloaded function
 * @param Frame* frame which is a pointer to an instance of the frame class
 * @return void
 */
void storageTimeline::addFrame(Frame* frame)
{
    frames.append(frame);
    numOfFrames++;
}

/**
 * @brief storageTimeline::removeFrame takes a frame number as a parameter
 * and removes the corresponding frame from the list of frames in timeline
 * @param int frameNum specifies which frame will be removed
 * @return void
 */
void storageTimeline::removeFrame(int frameNum)
{
    frames.removeAt(frameNum);
    numOfFrames--;
}


/**
 * @brief storageTimeline::moveFrames has not yet been fully implemented
 * but would be if we had time.
 * It can be used to move one frame or multiple contiguous frames
 * @param int startFrameNum specifies which is the first frame to be moved
 * @param int endFrameNum specifies which is the last frame to be moved. If
 * it is the same as startFrameNum, only one frame will be moved
 * @param int newLocation specifies the frame number after which the frames
 * that are moved will be inserted
 * @return void
 */
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

/**
 * @brief storateTimeline::getNumOfFrames retrieves the number of frames that have
 * been created since the timeline was initialized
 * @return numOfFrames which is a private attribute of the storageTimeline class
 */
int storageTimeline::getNumOfFrames()
{
    // increment numOfFrames after, so return value before increment
    return numOfFrames;
}

