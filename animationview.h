#ifndef ANIMATIONVIEW_H
#define ANIMATIONVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QPointF>
#include <QDebug>
#include <QColor>
#include <QDebug>

#include "global.h"
#include "pixel.h"
#include "object.h"
#include "frame.h"
#include "timelineview.h"

/**
 * @brief The AnimationView class which is a custom QGraphicsView
 * @author Dustin Fox
 */
class AnimationView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit AnimationView(QWidget *parent = 0);
    Frame * getCurrentFrame();

signals:
    void setFrameColor(QColor);

public slots:
    void setTool(int);
    void getTower();
    void saveFrame();
    void loadFrame(Frame*);
    void displaySelected(TimelineView *);
    void acceptFrameConnection(TimelineView *framView);    
    void colorChange(const QColor &);

private slots:
    void drawBackground(QPainter *painter, const QRectF &rect);
private:
    Frame * currentFrame;
    QColor currentColor;
};

#endif // ANIMATIONVIEW_H
