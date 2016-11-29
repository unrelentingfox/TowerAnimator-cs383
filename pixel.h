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
/**
 * @brief The Pixel class
 */
class Pixel : public QGraphicsRectItem
{
public:
      Pixel(int x, int y, int size, int r, int g, int b);

private:
};

#endif // PIXEL_H
