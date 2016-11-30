#include "animationview.h"
#define DEBUG

AnimationView::AnimationView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setAlignment(Qt::AlignCenter);
    this->setFixedSize(Globals::ANIMATION_WINDOW_SIZE_X+2, Globals::ANIMATION_WINDOW_SIZE_Y+2);
    tool = this->DRAW;
    frame = new Frame();
    this->setScene(frame);
    baseObject = new Object();
    frame->addItem(baseObject);
    mouseClicked = false;
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
 * @brief AnimationView::getTower, Returns a QList of all of the pixels that are within the tower rectangle.
 */
void AnimationView::getTower()
{
    //@todo create this function
}

/**
 * @brief AnimationView::saveFrame, Returns a QList of all of the pixels and objects that are in the current frame.
 */
void AnimationView::saveFrame()
{
    //@todo create this function
}

/**
 * @brief AnimationView::loadFrame, Loads in a FrameStorage object and creates the frame from that info.
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

    qreal left = int(rect.left()) - (int(rect.left()) % Globals::GRID_SIZE);
    qreal top = int(rect.top()) - (int(rect.top()) % Globals::GRID_SIZE);
    QVector<QPointF> points;
    for (qreal x = left; x < rect.right(); x += Globals::GRID_SIZE){
        for (qreal y = top; y < rect.bottom(); y += Globals::GRID_SIZE){
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
        update();
        QGraphicsView::mousePressEvent(e);
        break;
    default:
        break;
    }
}

void AnimationView::mouseReleaseEvent(QMouseEvent *e)
{
    mouseClicked = false;
    update();
    QGraphicsView::mousePressEvent(e);
}

/**
 * @brief AnimationView::mouseMoveEvent, Handles the left mouse button being held down, based on current selected mode.
 * @param e
 */
void AnimationView::mouseMoveEvent(QMouseEvent *e)
{
    if(mouseClicked){
        switch (tool){
        case AnimationView::ERASE:
            erasePixel(e);
            break;
        case AnimationView::DRAW:
            drawPixel(e);
            break;
        case AnimationView::MOVE:
            break;
        default:
            break;
        }
    }
    update();
    QGraphicsView::mouseMoveEvent(e);
}

/**
 * @brief AnimationView::drawPixel, Creates a pixel at the cursor location.
 */
int AnimationView::drawPixel(QMouseEvent * e)
{
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());

    //Overwrite any pixel that is already there.
    //erasePixel(e);

    //check to make sure the click is within the bounds of the scene



    //Draw new pixel
    Pixel * pixel = new Pixel(pt.x(),pt.y(),Globals::PIXEL_SIZE, red, green, blue);
    frame->addItem(pixel);
    //Add it to the object
    baseObject->addToGroup(pixel);

    return 1;
}

/**
 * @brief AnimationView::erasePixel, erases a pixel that is at the mouse position.
 * @param e
 * @return
 */
int AnimationView::erasePixel(QMouseEvent * e)
{
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());

    //Check for an object to delete.
    if(QGraphicsItem * item = frame->itemAt(pt, QTransform()))
    {
        frame->removeItem(item);
        return 1;
    }
    else
    {
        return 0;
    }
}
