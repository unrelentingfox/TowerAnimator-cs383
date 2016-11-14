//(220,190) (265,325)
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
void AnimationView::setRed(int r)
{
    red=r;
}

void AnimationView::setGreen(int g)
{
    green=g;
}

void AnimationView::setBlue(int b)
{
    blue=b;
}
/**
 * @brief AnimationView::drawBackground
 * @param painter
 * @param rect
 * Draws the background of the AnimationView frame.
 */
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
/**
 * @brief AnimationView::mousePressEvent
 * @param e
 * Handles left clicks based on current selected mode.
 */
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
/**
 * @brief AnimationView::mouseMoveEvent
 * @param e
 * Handles the left mouse button being held down, based on current selected mode.
 */
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
/**
 * @brief AnimationView::roundToGrid
 * @param x
 * @return
 * Fixes coordinates so that all pixels are aligned to a grid.
 */
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
/**
  Creates a pixel at the cursor location.
 */
int AnimationView::drawPixel(QMouseEvent * e)
{
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());
    pt.setX(roundToGrid(pt.x()));
    pt.setY(roundToGrid(pt.y()));

    //Check if there is already an object there, if not, make one.

    QBrush selected_color(QColor(red,green,blue));
    Pixel* p=new Pixel;
    p->createPixel(pt.x(),pt.y(),red,green,blue);
    if(!scene->itemAt(pt, QTransform()))
    {

        p->createRect(pt,selected_color);
        scene->addItem(p->rect);
        current_frame.addPixel(*p);


        //output coords of new rect for debugging
        qDebug() << pt.x() << ", " << pt.y();
        qDebug() << "Current number of Pixels in pixel_list: " << current_frame.pixel_list.size();
        return 1;
    }
    else
    {
        current_frame.addPixel(*p);
         return 0;
    }
}
/**
 * Erases a pixel from the screen,calls a deleteSearch to remove its associated pixel.
 */
int AnimationView::erasePixel(QMouseEvent * e)
{
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());
    pt.setX(roundToGrid(pt.x()));
    pt.setY(roundToGrid(pt.y()));

    //Check for an object to delete.
    if(QGraphicsItem * item = scene->itemAt(pt, QTransform()))
    {
        /**
         * Creates a new pixel to search the pixel_list with,deletes it after it is found.
         */
        QBrush selected_color(QColor(red,green,blue));
        Pixel* p=new Pixel;
        p->createPixel(pt.x(),pt.y(),red,green,blue);
        current_frame.deleteSearch(*p);
        scene->removeItem(item);
        delete p;

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
