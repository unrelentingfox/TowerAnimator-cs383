#include "animationgraphicsview.h"

//http://stackoverflow.com/questions/7830054/how-to-draw-a-point-on-mouseclick-on-a-qgraphicsscene

AnimationGraphicsView::AnimationGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    mouseInteraction = this->DRAW;
    scene = new QGraphicsScene();
    this->setScene(scene);
}

void AnimationGraphicsView::setMouseInteraction(int x)
{
    mouseInteraction = x;
}

void AnimationGraphicsView::mousePressEvent(QMouseEvent * e)
{
    switch (mouseInteraction){
    case AnimationGraphicsView::ERASE:
        erasePixel(e);
        break;
    case AnimationGraphicsView::DRAW:
        drawPixel(e);
        break;
    default:
        break;
    }
}

qreal AnimationGraphicsView::roundToGrid(qreal x)
{
    int coordinate = x;
    int remainder;

    //Round the coordinate to a multiple of GRID_SIZE.
    remainder = coordinate % GRID_SIZE;
    if(remainder == 0)
        coordinate = coordinate;
    else if(remainder >= GRID_SIZE/2)
        coordinate = coordinate-remainder+GRID_SIZE;
    else
        coordinate = coordinate-remainder;

    //move the coordinate so it is centered at the mouse click.
    coordinate = coordinate-PIXEL_SIZE/2;

    return coordinate;
}

int AnimationGraphicsView::drawPixel(QMouseEvent * e)
{
    qreal x;
    qreal y;
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());
    x = roundToGrid(pt.x());
    y = roundToGrid(pt.y());
    //Check if there is already an object there, if not, make one.
    if(!scene->itemAt(x,y, QTransform::QTransform()))
    {
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        rect->setRect(x,y, PIXEL_SIZE,PIXEL_SIZE);
        scene->addItem(rect);
        qDebug() << x << ", " << y;
        return 1;
    }
    else
    {
        return 0;
    }
}

int AnimationGraphicsView::erasePixel(QMouseEvent * e)
{
    qreal x;
    qreal y;
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());
    x = roundToGrid(pt.x());
    y = roundToGrid(pt.y());
    //Check if there is already an object there, if not, make one.
    if(QGraphicsItem * item = scene->itemAt(x,y, QTransform::QTransform()))
    {
        scene->removeItem(item);
        return 1;
    }
    else
    {
        return 0;
    }
}
