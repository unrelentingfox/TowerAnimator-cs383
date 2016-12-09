#include "animationview.h"
#define DEBUG

AnimationView::AnimationView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setAlignment(Qt::AlignCenter);
    this->setFixedSize(Globals::ANIMATION_WINDOW_SIZE_X+2, Globals::ANIMATION_WINDOW_SIZE_Y+2);
    currentFrame = 0;
}

Frame *AnimationView::getCurrentFrame()
{
    return currentFrame;
}

void AnimationView::setTool(int x)
{
    if(currentFrame != 0)
        currentFrame->setTool(x);
}

void AnimationView::colorChange(const QColor &color)
{

    currentColor.setRed(color.red());
    currentColor.setGreen(color.green());
    currentColor.setBlue(color.blue());
    //qDebug() << "color changed to: " << color;
    emit setFrameColor(currentColor);
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
void AnimationView::loadFrame(Frame* frame)
{
    this->setScene(frame);
    currentFrame = frame;
}

void AnimationView::displaySelected(TimelineView *view)
{
    this->setScene(view->frame);
    currentFrame = view->frame;
    emit setFrameColor(currentColor);
}

void AnimationView::acceptFrameConnection(TimelineView *view)
{
    connect(view, SIGNAL(iWasSelected(TimelineView*)), this, SLOT(displaySelected(TimelineView*)));
    connect(this, SIGNAL(setFrameColor(QColor)), view->frame, SLOT(colorChange(QColor)));
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
    QGraphicsView::drawBackground(painter, rect);
}

