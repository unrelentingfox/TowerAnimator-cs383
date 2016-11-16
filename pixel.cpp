#include "pixel.h"

Pixel::Pixel(int x, int y, int size, int r, int g, int b)
{

    x_Coordinate = x;
    y_Coordinate = y;
    red = r;
    green = g;
    blue = b;
    this->setRect(x,y,size,size);
    this->setBrush(QBrush(QColor(r,g,b,255)));
}

Pixel::~Pixel()
{
delete this;

}
