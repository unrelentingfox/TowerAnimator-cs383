#include "pixel.h"

Pixel::Pixel(int x, int y, int R, int G, int B)
{
    Pixel->x = x;
    Pixel->y = y;
    Pixel->R = R;
    Pixel->G = G;
    Pixel->B = B;
}

Pixel::~Pixel()
{
    delete Pixel;
}
