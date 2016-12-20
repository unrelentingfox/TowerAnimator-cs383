#include "frame.h"
#include <QFile>

/**
 * @brief Frame::Frame is the Frame class constructor
 * @param int frameNum is the frame number
 * @param int frameDuration is the duration of the frame
 */
Frame::Frame(int frameNum, int frameDuration)
{
    duration = 1;
    duration = frameDuration;
    frameNumber = frameNum;
    tool = Globals::DRAW_TOOL;

    mouseClicked = false;

    this->setSceneRect(0,0,Globals::ANIMATION_WINDOW_SIZE_X,Globals::ANIMATION_WINDOW_SIZE_Y);
    tower = new QGraphicsRectItem( Globals::TOWER_POSITION_X, Globals::TOWER_POSITION_Y, Globals::TOWER_WIDTH, Globals::TOWER_HEIGHT);
    this->addItem(tower);
}

double Frame::getDuration()
{
    return duration;
}

/**
 * @brief Frame::setTool changes which tool has been selected.
 * Possible values for tool are set in global.h file and include:
 * MOVE_TOOL = 3;
 * DRAW_TOOL = 1;
 * ERASE_TOOL = 2;
 * @param int t
 * @return void
 */
void Frame::setTool(int t)
{
    tool = t;
}

/**
 * @brief Frame::colorChange changes the color of the drawing tool
 * @param Qcolor color
 * @return void
 */
void Frame::colorChange(QColor color)
{
    drawColor.setRed(color.red());
    drawColor.setGreen(color.green());
    drawColor.setBlue(color.blue());
}

/**
 * @brief Frame::getPixels() returns a list of the pixels that are
 * in a frame
 * @param none
 * @return Qlist<Pixel *> is a list of pointers to pixels
 */
QList<Pixel *> Frame::getPixels()
{
    QList<QGraphicsItem *> list = items(0,0, Globals::ANIMATION_WINDOW_SIZE_X, Globals::ANIMATION_WINDOW_SIZE_Y, Qt::IntersectsItemBoundingRect , Qt::DescendingOrder);

    return trimPixelList(list);
}

/**
 * @brief Frame::getTowerContents() returns a list of the pixels that
 * are in the tower
 * @param none
 * @return Qlist<class Pixel *> is Qlist of pointers to Pixel class objects
 */
QList<class Pixel *> Frame::getTowerContents()
{
    //get a list of the pixels that are in the scene
    QList<QGraphicsItem *> list = items(Globals::TOWER_POSITION_X, Globals::TOWER_POSITION_Y, Globals::TOWER_WIDTH,Globals::TOWER_HEIGHT,Qt::IntersectsItemBoundingRect , Qt::DescendingOrder);

    return trimPixelList(list);
}

/**
 * @brief Frame::mouseMoveEvent determines what happens when the mouse
 * has been clicked and is moved within the frame window, depending on the current value
 * of tool.
 * Possible values for tool are set in global.h file and include:
 * MOVE_TOOL = 3;
 * DRAW_TOOL = 1;
 * ERASE_TOOL = 2;
 * The resulting action will either be to draw pixels or erase pixels,
 * since the move pixels functionality has not been implemented due
 * to time constraints.
 * Note that if the mouse is moved but has not been clicked, this function
 * will not do anything because it checks the value of mouseClicked first,
 * and that value is set by the Frame::mousePressEvent and Frame::mouseReleaseEvent functions.
 * @param QGraphicsSceneMouseEvent *mouseEvent
 * @return void
 */
void Frame::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if(mouseClicked){
        switch (tool){
        case Globals::ERASE_TOOL:
            erasePixel(mouseEvent);
            break;
        case Globals::DRAW_TOOL:
            drawPixel(mouseEvent);
            break;
        case Globals::MOVE_TOOL:
            break;
        default:
            break;
        }
    }
    update();
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

/**
 * @brief Frame::mousePressEvent determines what happens when the mouse
 * is clicked within the frame window, depending on the current value
 * of tool.
 * Possible values for tool are set in global.h file and include:
 * MOVE_TOOL = 3;
 * DRAW_TOOL = 1;
 * ERASE_TOOL = 2;
 * The resulting action will either be to draw pixels or erase pixels,
 * since the move pixels functionality has not been implemented due
 * to time constraints.
 * This function sets the value of mouseClicked to be true, which
 * means that if the mouse is then moved then the user will be able
 * to continue drawing without clicking on pixels individually one by one.
 * @param QGraphicsSceneMouseEvent *mouseEvent
 * @return void
 */
void Frame::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mouseClicked = true;

    switch (tool){
    case Globals::ERASE_TOOL:
        erasePixel(mouseEvent);
        break;
    case Globals::DRAW_TOOL:
        drawPixel(mouseEvent);
        break;
    case Globals::MOVE_TOOL:
        update();
        QGraphicsScene::mousePressEvent(mouseEvent);
        break;
    default:
        break;
    }
}

/**
 * @brief Frame::mouseReleaseEvent updates the value of mouseClicked
 * to be false when the mouse is released
 * @param QGraphicsSceneMouseEvent *mouseEvent
 * @return void
 */
void Frame::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mouseClicked = false;
    update();
    QGraphicsScene::mousePressEvent(mouseEvent);
}

/**
 * @brief Frame::drawPixel adds new pixels to the frame using the selected color,
 * drawColor, at the approximate location determined by rounding the
 * mouse coordinates to the nearest point
 * @param QGraphicsSceneMouseEvent *mouseEvent
 * @return void
 */
void Frame::drawPixel(QGraphicsSceneMouseEvent *mouseEvent)
{
    //Get x and y position of mouse click.
    QPointF pt = Algorithms::roundClickToGrid(mouseEvent->scenePos());
    if(isInBounds(pt)){
        //check to see if the an object is selected.
        //Overwrite any pixel that is already there.
        erasePixel(mouseEvent);

        //check to make sure the click is within the bounds of the scene

        //Draw new pixel
        Pixel * pixel = new Pixel(pt.x(),pt.y(),Globals::PIXEL_SIZE, drawColor);
        this->addItem(pixel);
        //Add it to the object
        //    baseObject->addToGroup(pixel);
    }
}

/**
 * @brief Frame::erasePixel removes a pixel item from the frame, at an
 * approximate location determined by taking the coordinates of the mouse
 * pointer and rounding down
 * @param QGraphicsSceneMouseEvent *mouseEvent
 * @return int which indicates whether a pixel was removed (1) or not (0)
 */
int Frame::erasePixel(QGraphicsSceneMouseEvent *mouseEvent)
{
    //Get x and y position of mouse click.
    QPointF pt = Algorithms::roundClickToGrid(mouseEvent->scenePos());
    QGraphicsItem * item = this->itemAt(pt, QTransform());
    if(item != 0 && item != tower)
    {
        this->removeItem(item);
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Frame::addPixel adds a pixel item
 * @param Pixel *pixel
 * @return void
 */
void Frame::addPixel(Pixel *pixel)
{
    this->addItem(pixel);
}

/**
 * @brief Frame::isInBounds checks whether a point is within the drawing
 * window or not, which determines whether or not there are pixels that can
 * be validly written to
 * @param QPointF pt
 * @return bool which corresponds to true, the pixel is in bounds, (1) or false,
 * the pixel is not in bounds, (0)
 */
bool Frame::isInBounds(QPointF pt)
{
    bool inBounds = true;

    if(pt.x() > Globals::ANIMATION_WINDOW_SIZE_X-Globals::PIXEL_OFFSET)
        inBounds = false;
    else if(pt.x() < Globals::PIXEL_OFFSET)
        inBounds = false;
    if(pt.y() > Globals::ANIMATION_WINDOW_SIZE_Y-Globals::PIXEL_OFFSET)
        inBounds = false;
    else if(pt.y() < Globals::PIXEL_OFFSET)
        inBounds = false;

    return inBounds;

}

/**
 * @brief Frame::trimPixelList casts QGraphicsItems to Pixels so that
 * the pixel functions can be used to retrieve data
 * @param Qlist<QGraphicsItem *> list which is a Qlist of pointers
 * to QGraphicsItems
 * @return Qlist<Pixel*> which is a Qlist of pointers to Pixels
 */
QList<Pixel *> Frame::trimPixelList(QList<QGraphicsItem *> list)
{
    Pixel * tempPixel;
    QList<Pixel *> pixelList;
    QList<QGraphicsItem *>::iterator i;
    for (i = list.begin(); i != list.end(); ++i){
        // cast each graphics item to a pixel so that the pixel functions can be used to retrieve data
        tempPixel = qgraphicsitem_cast<Pixel*>(i.operator *());
        if(tempPixel != tower){
            pixelList.append(tempPixel);
        }
//        qDebug() << tempPixel->towerPos() << tempPixel->red() << tempPixel->green() << tempPixel->blue();
    }
//    qDebug() << pixelList;
    return pixelList;
}
