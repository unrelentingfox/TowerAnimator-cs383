#include "frame.h"
#include <QFile>

Frame::Frame(int frameNum, double frameDuration)
{
    duration = frameDuration;
    frameNumber = frameNum;
    tool = Globals::DRAW_TOOL;
    red = 0;
    green = 0;
    blue = 0;
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

QList<class Pixel *> Frame::getTowerContents()
{
    Pixel * tempPixel;
    Pixel * tempStorage;
    QList<Pixel *> pixelList;

    //get a list of the items that are within the tower
    QList<QGraphicsItem *> list = items(Globals::TOWER_POSITION_X, Globals::TOWER_POSITION_Y, Globals::TOWER_WIDTH, Globals::TOWER_HEIGHT, Qt::IntersectsItemBoundingRect , Qt::DescendingOrder);


    QList<QGraphicsItem *>::iterator i;
    for (i = list.begin(); i != list.end(); ++i){
        tempPixel = qgraphicsitem_cast<Pixel*>(i.operator *());
        //this is just a place holder to show proof of functionality.
        //need to convert this information into a list of storagepixel or something so it is easily accessable without having to cast.
        qDebug() << tempPixel->mapFromItem(tower, QPointF(Globals::TOWER_POSITION_X,Globals::TOWER_POSITION_Y)) << tempPixel->red << tempPixel->green << tempPixel->blue;
    }
    return pixelList;
}

void Frame::write()
{
    QList<Pixel> pList;// = getTowerContents();
    QString filename = "out.txt";
    QFile file(filename);
//    int height = pList.size() / 20;     //40 pixels/frame, 5 vars/pixel -> 200 vars/frame -> 10 lines/frame
    int wr[Globals::TOWER_SIZE_X][Globals::TOWER_SIZE_Y]; //array length needs to be a constant value so just use the size of the tower in Globals
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // We're going to streaming text to the file
        QTextStream stream( &file );
        for(int i = 0; i < Globals::TOWER_SIZE_Y; i++){
            for(int j = 0; j < Globals::TOWER_SIZE_X; j++){
                stream << wr[i][j] << " ";
            }
            stream << endl;
            if((i+1) % 10 == 0){
                stream << endl;
            }
        }
        file.close();
    }
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

    emit iWasSelected(this);

    switch (tool){
    case Globals::ERASE_TOOL:
        //getTowerContents();
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
