#include "storageframe.h"

storageFrame::storageFrame(double duration, int currFrame)
{
    duration = duration;
    frame = new Frame();
    // get frame number from class, with method
    //frameNum = currFrame++;
}

storageFrame::~storageFrame()
{
    //delete Frame;
}

/*void storageFrame::addObject(QString objectName)
{
    objects.append(storageObject(objectName));
}*/

/*void storageFrame::removeObject(QString objectName)
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
}*/
