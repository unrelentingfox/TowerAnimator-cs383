#include "storageobject.h"

class storageFrame
{
public:
    // include frame.h and add instance of class
    // create function that grabs pixels and locations from Frame class:
    // getPixels/getTower
    // update linked list for current frame
    double duration;
    int frameNum;
    QLinkedList<storageObject> objects;
    storageFrame(double duration, int currFrame);
    ~storageFrame();
    void addObject(QString objectName);
    void removeObject(QString objectName);

};
