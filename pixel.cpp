#include "pixel.h"

Pixel::Pixel(int x, int y, int size, int r, int g, int b)
{
    x = Algorithms::roundPixelToGrid(x);
    y = Algorithms::roundPixelToGrid(y);
    this->setRect(x,y,size,size);
    this->setBrush(QBrush(QColor(r,g,b,255)));
}
