#include "frame.h"

Frame::Frame()
{
    mouseClicked = false;
}

/**
 * @brief Frame::mousePressEvent, Handles left clicks based on current selected mode.
 * @param e
 * @author Dustin Fox
 */
void Frame::mousePressEvent(QGraphicsSceneMouseEvent * e)
{
    mouseClicked = true;

    switch ( tool){
    case Frame::ERASE:
        erasePixel(e);
        break;
    case Frame::DRAW:
        drawPixel(e);
        break;
    case Frame::MOVE:
        update();
        QGraphicsView::mousePressEvent(e);
        break;
    default:
        break;
    }
}

void Frame::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    mouseClicked = false;
    update();
    QGraphicsView::mousePressEvent(e);
}

/**
 * @brief Frame::mouseMoveEvent, Handles the left mouse button being held down, based on current selected mode.
 * @param e
 */
void Frame::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{

    if(mouseClicked){
        switch (tool){
        case Frame::ERASE:
            erasePixel(e);
            break;
        case Frame::DRAW:
            drawPixel(e);
            break;
        case Frame::MOVE:
            break;
        default:
            break;
        }
    }
    update();
    QGraphicsView::mouseMoveEvent(e);
}

/**
 * @brief Frame::drawPixel, Creates a pixel at the cursor location.
 */
int Frame::drawPixel(QGraphicsSceneMouseEvent * e)
{
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());

    //Overwrite any pixel that is already there.
    //erasePixel(e);

    //Draw new pixel
    Pixel * pixel = new Pixel(pt.x(),pt.y(),PIXEL_SIZE, red, green, blue);
    scene->addItem(pixel);
    //Add it to the object
    baseObject->addToGroup(pixel);


    //output coords of new pixel for debugging
    qDebug() << pt.x() << ", " << pt.y();

    return 1;
}

/**
 * @brief Frame::erasePixel, erases a pixel that is at the mouse position.
 * @param e
 * @return
 */
int Frame::erasePixel(QGraphicsSceneMouseEvent * e)
{
    //Get x and y position of mouse click.
    QPointF pt = mapToScene(e->pos());

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
