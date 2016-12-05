#include "pixel.h"

int Pixel::type()
{
    return UserType+1;
}

Pixel::Pixel(int x, int y, int size, QColor color, QGraphicsItem * parent)
{
//    this->setParentItem(parent);
    x = Algorithms::roundPixelToGrid(x);
    y = Algorithms::roundPixelToGrid(y);
    this->setRect(0,0,size,size);
    this->setBrush(QBrush(color));
    this->setPos(x,y);

    //output coords of new pixel for debugging
    qDebug() << x << ", " << y;
}

QColor Pixel::color()
{
    return pixelColor;
}

int Pixel::red()
{
    return pixelColor.red();
}

int Pixel::green()
{
    return pixelColor.green();
}

int Pixel::blue()
{
    return pixelColor.blue();
}
