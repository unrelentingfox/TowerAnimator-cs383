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
/**
 * @brief The Pixel class
 */
class Pixel : public QGraphicsRectItem
{
public:
    Pixel(int x, int y, int size, int r, int g, int b);

private:
    int x_Coordinate; // x location
    int y_Coordinate; // y location
    int red; // red value
    int green; // green value
    int blue; // blue value
    int size;
};

#endif // PIXEL_H
