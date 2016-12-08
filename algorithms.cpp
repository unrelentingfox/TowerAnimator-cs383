#include "algorithms.h"

Algorithms::Algorithms()
{

}

QPointF Algorithms::roundToGrid(QPointF pt)
{
    pt.setX(roundToGrid(pt.x()));
    pt.setY(roundToGrid(pt.y()));
    return pt;
}

/**
 * @brief Algorithms::roundToGrid, Fixes coordinates so that all pixels are aligned to a grid.
 * @param x
 * @return
 */
int Algorithms::roundToGrid(int x)
{
    int coordinate = x;
    int remainder;

    //Round the coordinate to a multiple of Globals::GRID_SIZE.
    remainder = coordinate % Globals::GRID_SIZE;
    if(remainder == 0)
        coordinate = coordinate;
    else if(remainder >= Globals::GRID_SIZE/2)
        coordinate = coordinate-remainder+Globals::GRID_SIZE;
    else
        coordinate = coordinate-remainder;

    return coordinate + Globals::PIXEL_OFFSET;
}

QPointF Algorithms::roundClickToGrid(QPointF pt)
{
    pt.setX(roundClickToGrid(pt.x()));
    pt.setY(roundClickToGrid(pt.y()));
    return pt;
}

int Algorithms::roundClickToGrid(int x)
{
    x = x - Globals::MOUSE_OFFSET;
    x = roundToGrid(x);
    return x;
}
