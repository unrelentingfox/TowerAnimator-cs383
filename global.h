#ifndef GLOBAL_H
#define GLOBAL_H
#include <QPointF>

/**
 * @brief The Globals class Holds all of the crucual settings for the tower animator, including tower size which can be changed to accomidate larger or smaller towers or screens.
 * @author Dustin Fox
 */
class Globals
{
public:
    const static int MOVE_TOOL = 3;
    const static int DRAW_TOOL = 1;
    const static int ERASE_TOOL = 2;

    const static int TOWER_SIZE_X = 4;//How many windows? (must be a multiple of 2)
    const static int TOWER_SIZE_Y = 10;//How many windows? (must be a multiple of 2)
    const static int GRID_SIZE = 20;//How many pixels should the grid be? (must be a miltiple of 4)

    const static int MOUSE_OFFSET = 10; //mouse clicks happen

    const static int DEFAULT_DURATION = 1;

    // DO NOT CHANGE THE VARIABLES BELOW! They are set automatically based upon the variables above.
    const static int PIXEL_SIZE = GRID_SIZE/2; //Pixel size is always half of the grid size.
    const static int PIXEL_OFFSET = GRID_SIZE/4; //The offset is the distance from the edge of the grid that the pixel sits, since the pixel is half of the grid size, that distance is 1/4 of the grid size.
    const static int ANIMATION_WINDOW_SIZE_X = TOWER_SIZE_X*6*GRID_SIZE; //Width of the window is 7 times the size of the tower.
    const static int ANIMATION_WINDOW_SIZE_Y = TOWER_SIZE_Y*2*GRID_SIZE; //Height of the window is 3 times the height of the tower.
    const static int TOWER_POSITION_X = ANIMATION_WINDOW_SIZE_X/2-(TOWER_SIZE_X/2)*GRID_SIZE; //The position of the tower is the midpoint of the window minus 1/2 of the size of the tower.
    const static int TOWER_POSITION_Y = ANIMATION_WINDOW_SIZE_Y/2-(TOWER_SIZE_Y/2)*GRID_SIZE;
    const static int TOWER_WIDTH = TOWER_SIZE_X*GRID_SIZE; //Just converting the number of windows into pixels.
    const static int TOWER_HEIGHT = TOWER_SIZE_Y*GRID_SIZE;
    // DO NOT CHANGE THE VARIABLES ABOVE!

};
#endif // GLOBALVARIABLES_H
