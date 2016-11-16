#ifndef OBJECT_H
#define OBJECT_H
#include <QGraphicsItemGroup>

class Object : public QGraphicsItemGroup
{
public:
    Object(int x, int y, int size, int r, int g, int b);
};

#endif // OBJECT_H
