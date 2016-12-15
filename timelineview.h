#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include "frame.h"

#include <QObject>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsView>

class TimelineView : public QGraphicsView
{
    Q_OBJECT
signals:
    void iWasSelected(TimelineView*);

public:
    TimelineView(Frame *scene);
    Frame *frame;

private slots:
    void mousePressEvent(QMouseEvent *e);
};

#endif // TIMELINEVIEW_H
