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

void AnimationView::setBlue(int b)
{
    blue=b;
}

/**
 * @brief AnimationView::getTower, Returns a QList of all of the pixels that are within the tower rectangle.
 */
void AnimationView::getTower()
{
    //@todo create this function
}

/**
 * @brief AnimationView::saveFrame, Returns a QList of all of the pixels and objects that are in the current scene.
 */
void AnimationView::saveFrame()
{
    //@todo create this function
}

/**
 * @brief AnimationView::loadFrame, Loads in a FrameStorage object and creates the scene from that info.
 */
void AnimationView::loadFrame()
{

}

/**
 * @brief AnimationView::drawBackground, Draws the background of the AnimationView frame.
 * @param painter
 * @param rect
 * @author Dustin Fox
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
 * @brief AnimationView::mousePressEvent, Handles left clicks based on current selected mode.
 * @param e
 * @author Dustin Fox
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

<<<<<<< HEAD
=======
/**
 * @brief AnimationView::mouseMoveEvent, Handles the left mouse button being held down, based on current selected mode.
 * @param e
 */
>>>>>>> Fixed some comments and added in place holders for saveFrame, loadFrame, and getTower functions.
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

<<<<<<< HEAD
=======
/**
 * @brief AnimationView::roundToGrid, Fixes coordinates so that all pixels are aligned to a grid.
 * @param x
 * @return
 */
>>>>>>> Fixed some comments and added in place holders for saveFrame, loadFrame, and getTower functions.
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
 * @brief AnimationView::drawPixel, Creates a pixel at the cursor location.
 */
int AnimationView::drawPixel(QMouseEvent * e)
{

    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());
    pt.setX(roundToGrid(pt.x()));
    pt.setY(roundToGrid(pt.y()));
    // need to store these pixels in pixel class

    //Overwrite any pixel that is already there.
    erasePixel(e);
    //Draw new pixel
    Pixel * pixel = new Pixel(pt.x(),pt.y(),PIXEL_SIZE, red, green, blue);
    scene->addItem(pixel);

    //output coords of new pixel for debugging
    qDebug() << pt.x() << ", " << pt.y();

    return 1;
}

<<<<<<< HEAD
=======
/**
 * @brief AnimationView::erasePixel, erases a pixel that is at the mouse position.
 * @param e
 * @return
 */
>>>>>>> Fixed some comments and added in place holders for saveFrame, loadFrame, and getTower functions.
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
