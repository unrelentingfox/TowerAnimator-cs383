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

/**
 * @brief the Frame class is a custom QGraphicsScene that holds frame information and operations for adding pixels
 * to and removing pixels from the frame. It also contains important
 * functions that track and change values corresponding to the state of the
 * mouse and the currently selected tool, which can be draw, erase, or move.
 * Essentially, the Frame class defines how the user interacts with Frame objects
 * as well defining the Frame object itself.
 */
class Frame : public QGraphicsScene
{
    Q_OBJECT
public:
    Frame(int frameNum=0, int frameDuration=0);
    virtual ~Frame() {};
    double getDuration();
    void setTool(int t);

    //storage info
    int duration;
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
