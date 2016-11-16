#include <QLinkedList>
#include<QMutableLinkedListIterator>
#include <QString>
#include "pixel.h"

class storageObject
{
public:
    QString objectName;
    QLinkedList<Pixel*> pixels;
    storageObject(QString newObjectName);
    ~storageObject();
    // call Pixel constructor, add to linked list of pixels
    void addPixel(int x, int y,int size, int R, int G, int B);
    // call Pixel destructor, remove from linked list of pixels
    void removePixel(int x, int y);
};

