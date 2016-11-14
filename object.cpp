
#include "object.h"

Object(QString objectName);
~Object();
// call Pixel constructor, add to linked list of pixels
void addPixel(int x, int y, int R, int G, int B);
// call Pixel destructor, remove from linked list of pixels
void removePixel(Pixel pixel);

Object::Object(Qstring objectName)
{
    Object->objectName = objectName;
    // need to add more!
}

Object::~Object()
{
    delete Object;
}

void Object::addPixel(int x, int y, int R, int G, int B)
{
    newPixel = new Pixel(x, y, R, G, B);
    newPixel.append(pixels);
}


void Object::removePixel(int x, int y)
// remove pixel with specified x,y coordinates
{
    // iterate through list until pixel with (x,y) is found
    QLinkedList<Pixel>::iterator i = pixels.begin();

    while(i != pixels.end())
    {
        if((i->x == x) && (i->y == y)){
            pixels.erase(i);
            break;
        }
        i++;
    }
}
