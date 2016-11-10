#ifndef ANIMATIONITEMGROUP_H
#define ANIMATIONITEMGROUP_H
#include <QGraphicsItem>


class AnimationObject : public QGraphicsItemGroup
{
public:
    AnimationItemGroup();
private:
    itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // ANIMATIONITEMGROUP_H
