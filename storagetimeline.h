#include "frame.h"
#include <QDebug>

class storageTimeline
{
private:
    int numOfFrames = 0; // track number of frames created
public:
    int getNumOfFrames();
    int currFrame; // ??
    QList<class Frame *> frames; //possibly needs to be <Frame *>
    storageTimeline();
    ~storageTimeline();
    // make wrapper function that calls Frame getTowerFunction
    void getFrameTower();
    // add frame to timeline
    // use global iterator for life of timeline to generate frame num
    void addFrame(double duration);
    // remove frame from timeline
    void removeFrame(int frameNum);
    void moveFrames(int startFrameNum, int endFrameNum, int newLocation);
};
