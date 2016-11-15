#include "frame.h"

class Timeline
{
public:
    int currFrame; // ??
    QLinkedList<Frame> frames;
    Timeline();
    ~Timeline();
    // add frame to timeline
    void addFrame(double duration);
    // remove frame from timeline
    void removeFrame(int frameNum);

};
