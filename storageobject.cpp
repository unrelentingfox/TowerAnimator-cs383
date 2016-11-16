
#include "storageobject.h"

storageObject::storageObject(QString newObjectName)
{
    objectName = newObjectName;
}

storageObject::~storageObject()
{
    // delete storageObject
}

void storageObject::addPixel(int x, int y,int size, int R, int G, int B)
{
    pixels.append(new Pixel(x, y,size, R, G, B));
}


void storageObject::removePixel(int x_coord, int y_coord)
// remove pixel with specified x,y coordinates
{
    // iterate through list until pixel with (x,y) is found
    QLinkedList<Pixel>::iterator i = pixels.begin();

    while(i != pixels.end())
    {
        if((i->x == x_coord) && (i->y== y_coord)){
            pixels.erase(i);
            break;
        }
        i++;
    }
}
