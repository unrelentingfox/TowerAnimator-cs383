#include "storageobject.h"

class storageFrame
{
public:
    double duration;
    int frameNum;
    QLinkedList<storageObject> objects;
    storageFrame(double duration, int currFrame);
    ~storageFrame();
    void addObject(QString objectName);
    void removeObject(QString objectName);

};
