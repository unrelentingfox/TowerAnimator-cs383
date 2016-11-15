#include "object.h"

class Frame
{
public:
    double duration;
    int frameNum;
    QLinkedList<storageObject> objects;
    Frame(double duration, int currFrame);
    ~Frame();
    void addObject(QString objectName);
    void removeObject(QString objectName);

};
