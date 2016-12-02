// #include "storageobject.h"
#include <QLinkedList>
#include "frame.h"

// add and combine with frame class

class storageFrame
{
public:
    // include frame.h and add instance of class
    // create function that grabs pixels and locations from Frame class:
    // getPixels/getTower
    // update linked list for current frame
    // create instance of frame when create storage frame
    double duration;
    int frameNum;
    QLinkedList<storagePixel> pixels;
    Frame* frame;
    storageFrame(double duration, int currFrame);
    ~storageFrame();
    //void addObject(QString objectName);
    //void removeObject(QString objectName);

};
