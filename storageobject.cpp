/*
#include "storageobject.h"

storageObject::storageObject(QString newObjectName)
{
    objectName = newObjectName;
}

storageObject::~storageObject()
{
    // delete storageObject
}

void storageObject::addPixel(int x, int y, int R, int G, int B)
{
    pixels.append(storagePixel(x, y, R, G, B));
}


void storageObject::removePixel(int x, int y)
// remove pixel with specified x,y coordinates
{
    // iterate through list until pixel with (x,y) is found
    QLinkedList<storagePixel>::iterator i = pixels.begin();

    while(i != pixels.end())
    {
        if((i->x_Coordinate == x) && (i->y_Coordinate == y)){
            pixels.erase(i);
            break;
        }
        i++;
    }
}
*/
