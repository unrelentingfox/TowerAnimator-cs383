#include "timelinegraphics.h"
#include "frame.h"
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsGridLayout>
#include <iostream>

TimelineGraphics::TimelineGraphics()
{
    timeline = new QWidget;
    layout = new QHBoxLayout;
    timelinelist = new storageTimeline;
    layout->setAlignment(Qt::AlignLeft);
    timeline->setLayout(this->layout);
    timeline->setMaximumHeight(Globals::TOWER_HEIGHT + Globals::PIXEL_SIZE*2);
    selectedView = NULL;
    isPlaying = false;
}

QWidget* TimelineGraphics::timelineWidget()
{
    return timeline;
}

void TimelineGraphics::addFramePixel(QGraphicsScene* scene, int x, int y)
{
   QGraphicsRectItem* item1 = new QGraphicsRectItem(x*15,y*15+20,10,10);
   item1->setBrush(QBrush(Qt::red));
   scene->addItem(item1);
}

void TimelineGraphics::addTimelineFrame()
{
    addTimelineFrame(new Frame(0,1));
}

void TimelineGraphics::addTimelineFrame(Frame* scene)
{
    TimelineView* view = new TimelineView;
    //Frame* scene = new Frame(timelinelist->getNumOfFrames());

    //initialize the view
    view->frame = scene;
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setScene(scene);
    //view->setMaximumWidth(80);
    view->setFixedSize(Globals::TOWER_WIDTH, Globals::TOWER_HEIGHT);
    // view->setMaximumHeight(200);
    //view->scale(0.5, 0.5);

    //make connections
    emit connectNewFrame(view); //connects frame to animationview
    connect(view, SIGNAL (iWasSelected(TimelineView*)), this, SLOT (currentFrame(TimelineView*)));

    //make the new frame the selected frame


    //add to layout inserting after currently selected frame
    int index = 0;
    if (selectedView) {
        index = layout->indexOf(this->selectedView);
    }
    qDebug() << index;
    layout->insertWidget(index+1, view);


    //add to storage class
    timelinelist->addFrame(scene);

    //set focus
    emit view->iWasSelected(view);
}

void TimelineGraphics::currentFrame(TimelineView* view)
{
    if(selectedView) {
        selectedView->setBackgroundBrush(Qt::white);
    }
    this->selectedView = view;
    selectedView->setBackgroundBrush(Qt::gray);
    emit scrollToSelected(selectedView);
}

void TimelineGraphics::deleteView(TimelineView* view)
{
    //remove the layout
    layout->removeWidget(view);
    timelinelist->removeFrame(layout->indexOf(view));
    //timelinelist->removeFrame(view->frame->frameNumber);
    delete view->frame;
    delete view;
    selectedView = NULL;
}

int TimelineGraphics::deleteCurrentView()
{
    // get index of view to be deleted
    if(!selectedView)
        return 0;
    TimelineView* view = this->selectedView;
    if(!view)
        return 0;
    int index = layout->indexOf(view);
    qDebug() << index;

    //delete the view
    deleteView(this->selectedView);

    //select a new frame based on index of last frame

    QLayoutItem* item = layout->itemAt(index);
    if(item)
    {
        TimelineView* view2 = dynamic_cast<TimelineView *>(item->widget());
        emit view2->iWasSelected(view2);
    }
    else {
        item = layout->itemAt(index-1);
        if(item) {
            TimelineView* view2 = dynamic_cast<TimelineView *>(item->widget());
            emit view2->iWasSelected(view2);
        } else {
            addTimelineFrame();
        }
    }
    return 1;
}

int TimelineGraphics::playback(int start)
{
//    if(isPlaying) {
//        isPlaying = false;
//        return 0;
//    }
    isPlaying = true;
    QLayoutItem* item;
    TimelineView* view;
    for(int i = start; (item = layout->itemAt(i)); i++) {
        view = dynamic_cast<TimelineView *>(item->widget());
        emit view->iWasSelected(view);
        QTest::qWait(view->frame->duration);
        if(!isPlaying)
            return 0;
    }
    return 0;
}

void TimelineGraphics::restartPlayback()
{
    playback(0);
}

void TimelineGraphics::resumePlayback()
{
    playback(layout->indexOf(selectedView));
}

void TimelineGraphics::stopPlayback()
{
    isPlaying = false;
}

void TimelineGraphics::gotoCurrentFrame()
{
    emit selectedView->iWasSelected(selectedView);
}
