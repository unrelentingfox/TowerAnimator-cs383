#include "pixel.h"

int Pixel::type()
{
    return UserType+1;
}

Pixel::Pixel(int x, int y, int size, int r, int g, int b, QGraphicsItem * parent)
{
    red = r;
    green = g;
    blue = b;

    this->setParentItem(parent);
    x = Algorithms::roundPixelToGrid(x);
    y = Algorithms::roundPixelToGrid(y);
    this->setRect(0,0,size,size);
    this->setBrush(QBrush(QColor(r,g,b,255)));
    this->setPos(x,y);

    //output coords of new pixel for debugging
    qDebug() << x << ", " << y;
}
