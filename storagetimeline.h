#include "frame.h"

/**
 * @brief storageTimeline is a class that holds an instance of a timeline.
 * It contains methods to add and remove frames from the timeline.
 * It also contains a method to move a frame or frames which is not
 * being used yet due to time limitations.
 * It contains an attribute that tracks the number of frames that have been
 * created since the timeline was initialized.
 * It also contains a Qlist of frame pointers representing the frames in the
 * timeline.
 * @author Lydia Engerbretson, Hannah Pearson
 */
class storageTimeline
{
private:
    int numOfFrames; // track number of frames created
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
    void addFrame(Frame *frame);
    int getNumOfFrames();
};
