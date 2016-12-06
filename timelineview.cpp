#include "timelineview.h"

TimelineView::TimelineView()
{

}

void TimelineView::mousePressEvent(QMouseEvent *e)
{
    emit iWasSelected(this);
    //QGraphicsView::mousePressEvent(e);
}
