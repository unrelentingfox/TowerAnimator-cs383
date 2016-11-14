#include "animationview.h"
#define DEBUG
//http://stackoverflow.com/questions/7830054/how-to-draw-a-point-on-mouseclick-on-a-qgraphicsscene

AnimationView::AnimationView(QWidget *parent) :
    QGraphicsView(parent)
{
    tool = this->DRAW;
    scene = new QGraphicsScene();
    this->setScene(scene);
}

void AnimationView::setTool(int x)
{
    tool = x;
}

void AnimationView::drawBackground(QPainter *painter, const QRectF &rect)
{
    QPen pen;
    painter->setPen(pen);

    qreal left = int(rect.left()) - (int(rect.left()) % GRID_SIZE);
    qreal top = int(rect.top()) - (int(rect.top()) % GRID_SIZE);
    QVector<QPointF> points;
    for (qreal x = left; x < rect.right(); x += GRID_SIZE){
        for (qreal y = top; y < rect.bottom(); y += GRID_SIZE){
            points.append(QPointF(x,y));
        }
    }
    painter->drawPoints(points.data(), points.size());
}

void AnimationView::mousePressEvent(QMouseEvent * e)
{
    mouseClicked = true;

    switch (tool){
    case AnimationView::ERASE:
        erasePixel(e);
        break;
    case AnimationView::DRAW:
        drawPixel(e);
        break;
    case AnimationView::MOVE:
        move(e);
        break;
    default:
        break;
    }
}

void AnimationView::mouseReleaseEvent()
{
    mouseClicked = false;
}

void AnimationView::mouseDoubleClickEvent(QMouseEvent *e)
{

}

void AnimationView::mouseMoveEvent(QMouseEvent *e)
{
    switch (tool){
    case AnimationView::ERASE:
        erasePixel(e);
        break;
    case AnimationView::DRAW:
        drawPixel(e);
        break;
    case AnimationView::MOVE:
        move(e);
        break;
    default:
        break;
    }
}

qreal AnimationView::roundToGrid(qreal x)
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

int AnimationView::drawPixel(QMouseEvent * e)
{

    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());
    pt.setX(roundToGrid(pt.x()));
    pt.setY(roundToGrid(pt.y()));
    // need to store these pixels in pixel class

    //Check if there is already an object there, if not, make one.
    if(!scene->itemAt(pt, QTransform()))
    {
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        rect->setRect(pt.x(),pt.y(), PIXEL_SIZE, PIXEL_SIZE);
        scene->addItem(rect);

        //output coords of new rect for debugging
        qDebug() << pt.x() << ", " << pt.y();

        return 1;
    }
    else
    {
         return 0;
    }
}

int AnimationView::erasePixel(QMouseEvent * e)
{
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());
    pt.setX(roundToGrid(pt.x()));
    pt.setY(roundToGrid(pt.y()));

    //Check for an object to delete.
    if(QGraphicsItem * item = scene->itemAt(pt, QTransform()))
    {
        scene->removeItem(item);
        return 1;
    }
    else
    {
        return 0;
    }
}

int AnimationView::move(QMouseEvent * e)
{
    return 1;
}
