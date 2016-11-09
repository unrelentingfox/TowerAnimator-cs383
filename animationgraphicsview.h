#ifndef ANIMATIONGRAPHICSVIEW_H
#define ANIMATIONGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QPointF>
#include <QDebug>
#include "global.h"

//http://stackoverflow.com/questions/7830054/how-to-draw-a-point-on-mouseclick-on-a-qgraphicsscene

class AnimationGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    static const int DRAW = 1;
    static const int ERASE = 0;
    explicit AnimationGraphicsView(QWidget *parent = 0);

signals:

public slots:
    void setMouseInteraction(int);
    void mousePressEvent(QMouseEvent * e);
    // void mouseReleaseEvent(QMouseEvent * e);
    // void mouseDoubleClickEvent(QMouseEvent * e);
    // void mouseMoveEvent(QMouseEvent * e);
private slots:
    qreal roundToGrid(qreal x);
    int drawPixel(QMouseEvent * e);
    int erasePixel(QMouseEvent * e);
private:
    int mouseInteraction;
    QGraphicsScene * scene;
};

#endif // ANIMATIONGRAPHICSVIEW_H
