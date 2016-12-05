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
 * @brief The Pixel class
 */
class Pixel : public QGraphicsRectItem
{
public:
    int type();
    Pixel(int x, int y, int size, QColor color, QGraphicsItem * parent=0);
    QColor color();
    int red();
    int green();
    int blue();

private:
    QColor pixelColor;
};

#endif // PIXEL_H
