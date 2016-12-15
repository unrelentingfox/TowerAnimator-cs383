#include "timelineview.h"

TimelineView::TimelineView()
{

}

void TimelineView::mousePressEvent(QMouseEvent *e)
{
    (void)e;
    emit iWasSelected(this);
    //QGraphicsView::mousePressEvent(e);
}
