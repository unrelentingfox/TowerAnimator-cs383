#ifndef TIMELINEGRAPHICS_H
#define TIMELINEGRAPHICS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QGraphicsScene>

class TimelineGraphics
{
public:
    TimelineGraphics();
    void loadTimeline();
    void addFramePixel(QGraphicsScene* scene, int x, int y);
    QWidget* timelineWidget();

private:
    QWidget* timeline;
    QHBoxLayout* layout;
    void addTimelineFrame(QHBoxLayout* layout );

};

#endif // TIMELINEGRAPHICS_H
