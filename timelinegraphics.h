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
public:
    TimelineGraphics();
    void loadTimeline();
    void addFramePixel(QGraphicsScene* scene, int x, int y);
    QWidget* timelineWidget();


private:
    QWidget* timeline;
    QHBoxLayout* layout;
    TimelineView* selectedView;
    void deleteView(TimelineView *view);
    storageTimeline* timelinelist;
    bool isPlaying;
    void playback(int start);

public slots:
    void addTimelineFrame();
    void addTimelineFrame(Frame *scene);
    void currentFrame(TimelineView *view);

    void deleteCurrentView();

    void resumePlayback();
    void restartPlayback();
    void stopPlayback();
};

#endif // TIMELINEGRAPHICS_H
