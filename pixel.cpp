#include "pixel.h"

Pixel::Pixel()
{

}
/**
 * @brief Pixel::createPixel
 * @param x
 * @param y
 * @param r
 * @param g
 * @param b
 * Creates a pixel with given (x,y) and rgb values.
 */
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
/**
 * @brief Pixel::createRect
 * @param pt
 * @param selected_color
 * Defines a pixel's QGraphicsRectItem().
 */
void Pixel::createRect(QPointF pt,QBrush selected_color)
{
    rect = new QGraphicsRectItem();
    rect->setRect(pt.x(),pt.y(), PIXEL_SIZE, PIXEL_SIZE);
    qDebug() << rect->pos();
    paintPixel(selected_color);
}
/**
 * @brief Pixel::paintPixel
 * @param selected_color
 * Paints a pixel's QGraphicsRectItem().
 */
void Pixel::paintPixel(QBrush selected_color)
{
    qDebug() << rect->pos();
    qDebug() << "Painting" << selected_color;
    rect->setBrush(QBrush(selected_color));
    qDebug() << "Painted";
}
