#include "object.h"

Object::Object(qreal x, qreal y)
{
    this->setX(x);
    this->setY(y);
    setFlag(ItemIsMovable,true);
    setFlag(ItemIsSelectable,true);
    setFlag(ItemSendsScenePositionChanges,true);
    this->setAcceptHoverEvents(true);
    this->setAcceptDrops(true);
    qDebug() << "Object Created" << endl;
}

QVariant Object::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange) {
        // value is the new position.
        QPointF newPos = value.toPointF();
        newPos.setX(Algorithms::roundToGrid(newPos.x()));
        newPos.setY(Algorithms::roundToGrid(newPos.y()));
        return newPos;
    }
    return QGraphicsItem::itemChange(change, value);
}



