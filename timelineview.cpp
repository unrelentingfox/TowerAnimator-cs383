#include "timelineview.h"

TimelineView::TimelineView(Frame* scene)
{
    this->frame = scene;
    this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setScene(scene);
    this->setFixedSize(Globals::TOWER_WIDTH, Globals::TOWER_HEIGHT);
}

void TimelineView::mousePressEvent(QMouseEvent *e)
{
    (void)e;
    emit iWasSelected(this);
    //QGraphicsView::mousePressEvent(e);
}
