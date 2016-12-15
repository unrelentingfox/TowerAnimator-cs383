#include "algorithms.h"

/**
 * @brief Algorithms::Algorithms() is the Algorithms class constructor
 */
Algorithms::Algorithms()
{

}

/**
 * @brief Algorithms::roundToGrid converts any QPointF within
 * the drawing window to a QPointF on a specified grid by rounding
 * to the nearest grid point,
 * which is defined in Globals.h to be a multiple of Globals::GRID_SIZE
 * @param QPointF pt which is the actual point within the drawing window
 * @return QPointF which is the corresponding point on the grid
 */
QPointF Algorithms::roundToGrid(QPointF pt)
{
    pt.setX(roundToGrid(pt.x()));
    pt.setY(roundToGrid(pt.y()));
    return pt;
}

/**
 * @brief Algorithms::roundToGrid fixes coordinates so that all pixels are aligned to a grid.
 * The points in the grid are determined by rounding to the nearest point
 * which is defined in Globals.h to be a multiple of Globals::GRID_SIZE
 * @param int x which is the actual coordinate
 * @return int which is the corresponding coordinate on the grid
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

/**
 * @brief Algorithms::roundToGrid converts any QPointF within
 * the drawing window to a QPointF on a specified grid by rounding
 * to the nearest grid point,
 * which is defined in Globals.h to be a multiple of Globals::GRID_SIZE
 * @param QPointF pt which is the actual QPointF within the drawing window
 * @return QPointF which is the corresponding point on the grid
 */
QPointF Algorithms::roundClickToGrid(QPointF pt)
{
    pt.setX(roundClickToGrid(pt.x()));
    pt.setY(roundClickToGrid(pt.y()));
    return pt;
}

/**
 * @brief Algorithms::roundToGrid fixes coordinates so that all pixels are aligned to a grid.
 * The points in the grid are determined by rounding to the nearest point
 * which is defined in Globals.h to be a multiple of Globals::GRID_SIZE
 * @param int x which is the actual coordinate
 * @return int which is the corresponding coordinate on the grid
 */
int Algorithms::roundClickToGrid(int x)
{
    x = x - Globals::MOUSE_OFFSET;
    x = roundToGrid(x);
    return x;
}
