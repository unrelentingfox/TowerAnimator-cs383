#ifndef PIXEL_H
#define PIXEL_H
#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsRectItem>
#include "global.h"
#include "algorithms.h"
#include "frame.h"
/**
 * @brief The Pixel class is a custom QGraphicsRectItem with added functionality to keep track of pixel information to be saved in a .tan file
 * @author Dustin Fox, Lydia Engerbretson, Hannah Pearson
 */
class Pixel : public QGraphicsRectItem
{
public:
    int type();
    Pixel(int x, int y, int size, QColor color, QGraphicsItem * parent=0);
    QPointF towerPos();
    QPointF framePos();
    QColor color();
    int red();
    int green();
    int blue();

private:
    static QPointF coordinateToGrid(QPointF pt);
    static QPointF gridToCoordinate(QPointF pt);
    QColor pixelColor;
};

#endif // PIXEL_H
