#include "pixel.h"

int Pixel::type()
{
    return UserType+1;
}

Pixel::Pixel(int x, int y, int size, QColor color, QGraphicsItem * parent)
{
    pixelColor = color;
    this->setParentItem(parent);
    x = Algorithms::roundToGrid(x);
    y = Algorithms::roundToGrid(y);
    this->setRect(0,0,size,size);
//    this->setPen(QPen(Qt::white));
    this->setBrush(QBrush(color));
    this->setPos(x,y);

    //output coords of new pixel for debugging
    //qDebug() << x << ", " << y;
}

QPointF Pixel::towerPos()
{
    return coordinateToGrid(this->mapToScene(-Globals::TOWER_POSITION_X,-Globals::TOWER_POSITION_Y));
}

QPointF Pixel::framePos()
{
    return coordinateToGrid(this->mapToScene(0,0));
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

QPointF Pixel::coordinateToGrid(QPointF pt)
{
    pt.setX((pt.x() - Globals::PIXEL_OFFSET) / Globals::GRID_SIZE);
    pt.setY((pt.y() - Globals::PIXEL_OFFSET) / Globals::GRID_SIZE);

    return pt;
}

QPointF Pixel::gridToCoordinate(QPointF pt){
    pt.setX((pt.x() + Globals::PIXEL_OFFSET) * Globals::GRID_SIZE);
    pt.setY((pt.y() + Globals::PIXEL_OFFSET) * Globals::GRID_SIZE);
    return pt;
}
