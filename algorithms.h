#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "global.h"
#include <QPointF>

class Algorithms
{
public:
    Algorithms();
    static QPointF roundToGrid(QPointF pt);
    static int roundToGrid(int x);
    static QPointF roundClickToGrid(QPointF pt);
    static int roundClickToGrid(int x);
};

#endif // ALGORITHMS_H
