#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "global.h"
#include <QPointF>

/**
 * @brief the Algorithms class contains functions for
 * converting a point representing the location of the mouse
 * into a limited range of values corresponding to
 * the specified grid
 * @author Dustin Fox
 */
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
