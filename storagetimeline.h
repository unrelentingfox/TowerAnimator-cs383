#include "frame.h"

class storageTimeline
{
private:
    int numOfFrames; // track number of frames created
    int getNumOfFrames();
public:
    int currFrame; // ??
    QList<class Frame *> frames; //possibly needs to be <Frame *>
    storageTimeline();
    ~storageTimeline();
    // make wrapper function that calls Frame getTowerFunction
    // add frame to timeline
    // use global iterator for life of timeline to generate frame num
    void addFrame(double duration);
    // remove frame from timeline
    void removeFrame(int frameNum);
    void moveFrames(int startFrameNum, int endFrameNum, int newLocation);
};
