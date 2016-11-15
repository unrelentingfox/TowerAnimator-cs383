#ifndef FRAME_H
#define FRAME_H

#endif // FRAME_H

#include "object.h"
#include <QLinkedList>
#include <QString>

class Frame
{
    // Q_OBJECT
public:
    double duration;
    int frameNum;
    QLinkedList<Object> objects;
    Frame(double duration, int currFrame);
    ~Frame();
    void addObject(QString objectName);
    void removeObject(QString objectName);

};
