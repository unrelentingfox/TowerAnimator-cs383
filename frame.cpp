#include "frame.h"

Frame::Frame(double duration, int currFrame)
{
    duration = duration;
    frameNum = currFrame++;
}

Frame::~Frame()
{
    //delete Frame;
}

void Frame::addObject(QString objectName)
{
    objects.append(storageObject(objectName));
}

void Frame::removeObject(QString objectName)
{
    // iterate through list until object with objectName is found
    QLinkedList<storageObject>::iterator i = objects.begin();

    while(i != objects.end())
    {
        if(i->objectName == objectName){
            objects.erase(i);
            break;
        }
        i++;
    }
}
