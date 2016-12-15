#ifndef TIMELINEGRAPHICS_H
#define TIMELINEGRAPHICS_H

#include "frame.h"
#include "timelineview.h"
#include "storagetimeline.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QTest>

class TimelineGraphics : public QObject
{
    Q_OBJECT
signals:
    void connectNewFrame(TimelineView*);
    void scrollToSelected(TimelineView*);
    void displayDuration(int);
public:
    TimelineGraphics();
    QWidget* timelineWidget();
    QHBoxLayout* layout;
    bool isPlaying;

private:
    QWidget* timeline;
    TimelineView* selectedView;
    void deleteView(TimelineView *view);
    storageTimeline* timelinelist;
    int playback(int start);

public slots:
    void addTimelineFrame();
    void addTimelineFrame(Frame *scene);
    void currentFrame(TimelineView *view);
    int deleteCurrentView();
    void resumePlayback();
    void restartPlayback();
    void stopPlayback();
    void gotoCurrentFrame();
    void DurationChanged(int newDuration);
};

#endif // TIMELINEGRAPHICS_H
