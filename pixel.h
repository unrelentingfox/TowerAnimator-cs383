#ifndef PIXEL_H
#define PIXEL_H
#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsEllipseItem>
#include "global.h"
class Pixel
{
public:
    Pixel();
    void createPixel(qreal,qreal,int,int,int);
    qreal returnX();
    qreal returnY();
    int returnR();
    int returnG();
    int returnB();
    int setR(int);
    int setG(int);
    int setB(int);
    QGraphicsRectItem * rect;
    void createRect(QPointF,QBrush);
    void paintPixel(QBrush selected_color);

private:
    int x;
    int y;
    int r;
    int g;
    int b;
};

#endif // PIXEL_H
