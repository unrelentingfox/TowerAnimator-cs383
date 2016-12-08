#ifndef FRAME_H
#define FRAME_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMutableListIterator>
#include "frame.h"
#include "global.h"
#include "pixel.h"
#include <QDebug>

class Frame : public QGraphicsScene
{
    Q_OBJECT
public:
    Frame(int frameNum=0, double frameDuration=0);
    virtual ~Frame() {};
    void setTool(int t);

    //storage info
    double duration;
    int frameNumber;
    QList<class Pixel *> getPixels();
    QList<class Pixel *> getTowerContents();

    void addPixel(Pixel *pixel);
public slots:
    void colorChange(QColor);
private:
    QGraphicsRectItem * tower;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

    void drawPixel(QGraphicsSceneMouseEvent *mouseEvent);
    int erasePixel(QGraphicsSceneMouseEvent *mouseEvent);
    bool isInBounds(QPointF pt);

    QList<class Pixel *> trimPixelList(QList<QGraphicsItem *> list);

    bool mouseClicked;

    int tool;
    QColor drawColor;


};

#endif // FRAME_H
