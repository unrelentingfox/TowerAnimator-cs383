#include "pixel.h"

Pixel::Pixel(int x, int y, int R, int G, int B)
{
    x_Coordinate = x;
    y_Coordinate = y;
    red = R;
    green = G;
    blue = B;
}

Pixel::~Pixel()
{
    //delete Pixel
}
