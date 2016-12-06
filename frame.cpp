#include "frame.h"
#include <QFile>

Frame::Frame(int frameNum, double frameDuration)
{
    duration = frameDuration;
    frameNumber = frameNum;
    tool = Globals::DRAW_TOOL;
    duration = 1;
    mouseClicked = false;

    this->setSceneRect(0,0,Globals::ANIMATION_WINDOW_SIZE_X,Globals::ANIMATION_WINDOW_SIZE_Y);
    tower = new QGraphicsRectItem( Globals::TOWER_POSITION_X, Globals::TOWER_POSITION_Y, Globals::TOWER_WIDTH, Globals::TOWER_HEIGHT);
    this->addItem(tower);
}

void Frame::setTool(int t)
{
    tool = t;
}

void Frame::colorChange(QColor* color)
{
    int* r, g, b;
    color->getRgb(r, g, b);
    setRed(r);
    setGreen(g);
    setBlue(b);
}

void Frame::setRed(int r)
{
    drawColor.setRed(r);
}

void Frame::setGreen(int g)
{
    drawColor.setGreen(g);
}

void Frame::setBlue(int b)
{
    drawColor.setBlue(b);
}

QList<Pixel *> Frame::getPixels()
{
    //get a list of the pixels that are in the scene
    QList<QGraphicsItem *> list = items(0,0, Globals::ANIMATION_WINDOW_SIZE_X, Globals::ANIMATION_WINDOW_SIZE_Y, Qt::IntersectsItemBoundingRect , Qt::DescendingOrder);

    return trimPixelList(list);
}

QList<class Pixel *> Frame::getTowerContents()
{
    //get a list of the pixels that are in the scene
    QList<QGraphicsItem *> list = items(Globals::TOWER_POSITION_X, Globals::TOWER_POSITION_Y, Globals::TOWER_WIDTH,Globals::TOWER_WIDTH,Qt::IntersectsItemBoundingRect , Qt::DescendingOrder);

    return trimPixelList(list);
}

void Frame::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if(mouseClicked){
        switch (tool){
        case Globals::ERASE_TOOL:
//            erasePixel(mouseEvent);
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

void Frame::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mouseClicked = true;

    switch (tool){
    case Globals::ERASE_TOOL:
        getPixels();
//        erasePixel(mouseEvent);
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

void Frame::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mouseClicked = false;
    update();
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void Frame::drawPixel(QGraphicsSceneMouseEvent *mouseEvent)
{
    //Get x and y position of mouse click.
    QPointF pt = Algorithms::roundClickToGrid(mouseEvent->scenePos());
    if(isInBounds(pt)){
        //check to see if the an object is selected.
        //Overwrite any pixel that is already there.
        //erasePixel(mouseEvent);

        //check to make sure the click is within the bounds of the scene

        //Draw new pixel
        Pixel * pixel = new Pixel(pt.x(),pt.y(),Globals::PIXEL_SIZE, drawColor);
        this->addItem(pixel);
        //Add it to the object
        //    baseObject->addToGroup(pixel);
    }
}

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

QList<Pixel *> Frame::trimPixelList(QList<QGraphicsItem *> list)
{
    Pixel * tempPixel;
    QList<Pixel *> pixelList;
    QList<QGraphicsItem *>::iterator i;
    for (i = list.begin(); i != list.end(); ++i){
        // cast each graphics item to a pixel so that the pixel functions can be used to retrieve data
        tempPixel = qgraphicsitem_cast<Pixel*>(i.operator *());
        if(tempPixel != 0){
            pixelList.append(tempPixel);
        }
        qDebug() << tempPixel->towerPos() << tempPixel->red() << tempPixel->green() << tempPixel->blue();
    }
    qDebug() << pixelList;
    return pixelList;
}
