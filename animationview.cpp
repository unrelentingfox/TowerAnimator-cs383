#include "animationview.h"
#define DEBUG

AnimationView::AnimationView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setAlignment(Qt::AlignCenter);
    this->setFixedSize(Globals::ANIMATION_WINDOW_SIZE_X+2, Globals::ANIMATION_WINDOW_SIZE_Y+2);
//    tool = this->DRAW;
   /* Frame * frame = new Frame(0, 0);
    this->setScene(frame);
    baseObject = new Object();
    frame->addItem(baseObject);*/
    mouseClicked = false;
}

void AnimationView::setTool(int x)
{
    frame->setTool(x);
}
void AnimationView::setRed(int r)
{
    frame->setRed(r);
}

void AnimationView::setGreen(int g)
{
    frame->setGreen(g);
}

void AnimationView::setBlue(int b)
{
    frame->setBlue(b);
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
    //set frame number and add frame to list? keyframe?
}

/**
 * @brief AnimationView::loadFrame, Loads in a FrameStorage object and creates the frame from that info.
 */
void AnimationView::loadFrame()
{

}

void AnimationView::displaySelected(Frame *scene)
{
    this->setScene(scene);
    frame = scene;
}

void AnimationView::acceptFrameConnection(Frame *frame)
{
    connect(frame, SIGNAL(iWasSelected(Frame*)), this, SLOT(displaySelected(Frame*)));
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

void AnimationView::mousePressEvent(QMouseEvent *e)
{
    //set changes here
    QGraphicsView::mousePressEvent(e);
}
