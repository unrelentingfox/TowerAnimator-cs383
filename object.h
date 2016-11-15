#ifndef OBJECT_H
#define OBJECT_H

#include <QLinkedList>
#include <QString>
#include "pixel.h"

#endif // OBJECT_H

class Object
{
    // Q_OBJECT
public:
    QString objectName;
    QLinkedList<Pixel> pixels;
    Object(QString objectName);
    ~Object();
    // call Pixel constructor, add to linked list of pixels
    void addPixel(int x, int y, int R, int G, int B);
    // call Pixel destructor, remove from linked list of pixels
    void removePixel(int x, int y);
};

