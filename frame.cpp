#include "frame.h"

Frame::Frame(double duration, int currFrame)
{
    Frame->duration = duration;
    Frame->frameNum = currFrame++;
}

Frame::~Frame()
{
    delete Frame;
}

void Frame::addObject(QString objectName)
{
    newObject = new Object(objectName);
    objects.append(newObject);
}

void Frame::removeObject(QString objectName)
{
    // iterate through list until object with objectName is found
    QLinkedList<Object>::iterator i = objects.begin();

    while(i != objects.end())
    {
        if(i->objectName == objectName){
            objects.erase(i);
            break;
        }
        i++;
    }
}
