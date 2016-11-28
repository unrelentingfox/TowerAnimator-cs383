#include "algorithms.h"

Algorithms::Algorithms()
{

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


    //Round the coordinate to a multiple of GRID_SIZE.
    remainder = coordinate % GRID_SIZE;
    if(remainder == 0)
        coordinate = coordinate;
    else if(remainder >= GRID_SIZE/2)
        coordinate = coordinate-remainder+GRID_SIZE;
    else
        coordinate = coordinate-remainder;

    return coordinate;
}

int Algorithms::roundPixelToGrid(int x)
{
    x = roundToGrid(x);
    //move the coordinate so it is centered at the mouse click.
    x = x-PIXEL_SIZE/2;
    return x;
}
