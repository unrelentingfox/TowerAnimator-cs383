#include "pixel.h"

Pixel::Pixel()
{

}
void Pixel::createPixel(qreal x, qreal y, int r, int g, int b)
{
    this->x=x;
    this->y=y;
    this->r=r;
    this->g=g;
    this->b=b;
}
qreal Pixel::returnX()
{
   return this->x;
}

qreal Pixel::returnY()
{
    return this->y;
}

int Pixel::returnR()
{
    return this->r;
}
int Pixel::returnG()
{
    return this->g;
}
int Pixel::returnB()
{
    return this->b;
}

int Pixel::setR(int newR)
{
    r=newR;
}

int Pixel::setG(int newG)
{
    g=newG;
}

int Pixel::setB(int newB)
{
    b=newB;
}

void Pixel::createRect(QPointF pt,QBrush selected_color)
{
    rect = new QGraphicsRectItem();
    rect->setRect(pt.x(),pt.y(), PIXEL_SIZE, PIXEL_SIZE);
    paintPixel(selected_color);
}

void Pixel::paintPixel(QBrush selected_color)
{
    rect->setBrush(QBrush(selected_color));
    qDebug() << "wtwadfasdf";
}
