#ifndef FRAME_H
#define FRAME_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "global.h"

class Frame : public QGraphicsScene
{
public:
    Frame();
private:
    QGraphicsRectItem * tower;
};

#endif // FRAME_H
