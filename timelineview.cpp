#include "timelineview.h"

TimelineView::TimelineView()
{

}

void TimelineView::mousePressEvent(QMouseEvent *e)
{
    emit iWasSelected(this->frame);
    //QGraphicsView::mousePressEvent(e);
}
