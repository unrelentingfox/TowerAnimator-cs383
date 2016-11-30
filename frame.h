#ifndef FRAME_H
#define FRAME_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "global.h"
#include "pixel.h"
#include <QDebug>

class Frame : public QGraphicsScene
{
public:
    Frame();
    void setTool(int t);
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);

    int getTowerContents();
private:
    QGraphicsRectItem * tower;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

    void drawPixel(QGraphicsSceneMouseEvent *mouseEvent);

    bool mouseClicked;

    int tool;
    int red;
    int green;
    int blue;


};

#endif // FRAME_H
