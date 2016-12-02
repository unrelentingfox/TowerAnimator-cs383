#ifndef FRAME_H
#define FRAME_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "frame.h"
#include "global.h"
#include "pixel.h"
#include <QDebug>

class Frame : public QGraphicsScene
{
    Q_OBJECT
signals:
    void iWasSelected(Frame*);
public:
    Frame(int frameNum=0, double frameDuration=0);
    virtual ~Frame() {};
    void setTool(int t);
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);

    //storage info
    double duration;
    int frameNumber;
    QList<class Pixel *> getTowerContents();
    void write();

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
