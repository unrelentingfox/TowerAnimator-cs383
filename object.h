#ifndef OBJECT_H
#define OBJECT_H
#include <QGraphicsItemGroup>
#include <QDebug>
#include <pixel.h>

/**
 * @brief The Object class is a custom QGraphicsItemGroup that is used to group pixels together and allow them to be moved as one item
 * @author Dustin Fox
 */
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
