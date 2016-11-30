#include "frame.h"

Frame::Frame()
{
    tool = Globals::DRAW_TOOL;
    red = 0;
    green = 0;
    blue = 0;
    mouseClicked = false;

    this->setSceneRect(0,0,Globals::ANIMATION_WINDOW_SIZE_X,Globals::ANIMATION_WINDOW_SIZE_Y);
    tower = new QGraphicsRectItem( Globals::TOWER_POSITION_X, Globals::TOWER_POSITION_Y, Globals::TOWER_WIDTH, Globals::TOWER_HEIGHT);
    this->addItem(tower);
}

void Frame::setTool(int t)
{
    tool = t;
}

void Frame::setRed(int r)
{
    red = r;
}

void Frame::setGreen(int g)
{
    green = g;
}

void Frame::setBlue(int b)
{
    blue = b;
}

int Frame::getTowerContents()
{
    qDebug() << "hello";
    Pixel * temp;
    QList<QGraphicsItem *> list = items(Globals::TOWER_POSITION_X, Globals::TOWER_POSITION_Y, Globals::TOWER_WIDTH, Globals::TOWER_HEIGHT, Qt::IntersectsItemBoundingRect , Qt::DescendingOrder);

    QList<QGraphicsItem *>::iterator i;
    for (i = list.begin(); i != list.end(); ++i){
        temp = qgraphicsitem_cast<Pixel*>(i.operator *());
        //this is just a place holder to show proof of functionality.
        qDebug() << temp->mapFromItem(tower, QPointF(Globals::TOWER_POSITION_X,Globals::TOWER_POSITION_Y)) << temp->red << temp->green << temp->blue;
    }
    return 0;
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
        getTowerContents();
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
    QPointF pt = mouseEvent->scenePos();

    //check to see if the an object is selected.
    //Overwrite any pixel that is already there.
    //erasePixel(mouseEvent);

    //check to make sure the click is within the bounds of the scene



    //Draw new pixel
    Pixel * pixel = new Pixel(pt.x(),pt.y(),Globals::PIXEL_SIZE, red, green, blue, tower);
    this->addItem(pixel);
    //Add it to the object
//    baseObject->addToGroup(pixel);
}
