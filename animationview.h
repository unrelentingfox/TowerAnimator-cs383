#ifndef ANIMATIONVIEW_H
#define ANIMATIONVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QPointF>
#include <QDebug>

#include "global.h"
#include "pixel.h"
#include "object.h"
#include "frame.h"
#include "timelineview.h"


//http://stackoverflow.com/questions/7830054/how-to-draw-a-point-on-mouseclick-on-a-qgraphicsscene
/**
 * @brief The AnimationView class
 * Each instance is a frame in the timeline.
 */
class AnimationView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit AnimationView(QWidget *parent = 0);

signals:

public slots:
    void setTool(int);
    void setRed(int);
    void setGreen(int);
    void setBlue(int);
    void getTower();
    void saveFrame();
    void loadFrame(Frame *);
    void acceptFrameConnection(TimelineView *frameView);

private slots:
    void drawBackground(QPainter *painter, const QRectF &rect);
private:
    Frame * currentFrame;
};

#endif // ANIMATIONVIEW_H
