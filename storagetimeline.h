#include "storageframe.h"

class storageTimeline
{
public:
    int currFrame; // ??
    QLinkedList<storageFrame> frames;
    storageTimeline();
    ~storageTimeline();
    // add frame to timeline
    void addFrame(double duration);
    // remove frame from timeline
    void removeFrame(int frameNum);

};
