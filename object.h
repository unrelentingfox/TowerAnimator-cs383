#ifndef OBJECT_H
#define OBJECT_H
#include <QGraphicsItemGroup>
#include <QDebug>
#include <pixel.h>

class Object : public QGraphicsItemGroup
{
public:
    Object(qreal x = 0, qreal y = 0);
    void addPixel(Pixel * pixel);
    void deletePixel();
private:
   QVariant itemChange(GraphicsItemChange change, const QVariant &value);
   int roundToGrid(int x);
};

#endif // OBJECT_H
