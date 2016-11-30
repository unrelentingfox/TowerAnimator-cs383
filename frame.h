#ifndef FRAME_H
#define FRAME_H
#include <QGraphicsScene>
#include "global.h"

class Frame : public QGraphicsScene
{
public:
    Frame();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
private:
    bool mouseClicked;
};

#endif // FRAME_H
