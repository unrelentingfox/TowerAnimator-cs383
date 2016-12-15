#include "timelinegraphics.h"
#include "frame.h"
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsGridLayout>
#include <iostream>

/**
 * @brief TimelineGraphics::TimelineGraphics
 * Initialize the timeline widget
 */
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

/**
 * @brief TimelineGraphics::timelineWidget
 * Fetch the timeline widget
 * @return
 */
QWidget* TimelineGraphics::timelineWidget()
{
    return timeline;
}

/**
 * @brief TimelineGraphics::addTimelineFrame
 * Overloaded function. generates an empty frame and
 * passes it to the same function that accepts a frame
 * to be added. This frame will duplicate the duration of the
 * currently selected frame.
 */
void TimelineGraphics::addTimelineFrame()
{
    if(!selectedView){
        addTimelineFrame(new Frame(0,100));
    }
    else {
        addTimelineFrame(new Frame(0,selectedView->frame->duration));
    }
}

/**
 * @brief TimelineGraphics::addTimelineFrame
 * Takes a frame initialized a TimelineView. Adds this to the
 * layout of the timeline widget after the currently selected frame.
 * @param scene
 */
void TimelineGraphics::addTimelineFrame(Frame* scene)
{
    //create a view containing the frame as its scene
    TimelineView* view = new TimelineView(scene);

    //make connections
    emit connectNewFrame(view); //connects frame to animationview
    connect(view, SIGNAL (iWasSelected(TimelineView*)), this, SLOT (currentFrame(TimelineView*)));

    //add to layout inserting after currently selected frame
    int index = 0;
    if (selectedView) {
        index = layout->indexOf(this->selectedView);
    }
    //qDebug() << index;
    layout->insertWidget(index+1, view);


    //add to storage class
    timelinelist->addFrame(scene);

    //set focus
    emit view->iWasSelected(view);
}

/**
 * @brief TimelineGraphics::currentFrame
 * Selects the new frame. unhighlights the old frame.
 * Highlights the new one.
 * @param view
 */
void TimelineGraphics::currentFrame(TimelineView* view)
{
    if(selectedView) {
        selectedView->setBackgroundBrush(Qt::white);
    }
    this->selectedView = view;
    selectedView->setBackgroundBrush(Qt::gray);
    emit scrollToSelected(selectedView);
    emit displayDuration(selectedView->frame->duration);
}

/**
 * @brief TimelineGraphics::deleteView
 * deletes a view from the storage class and removes it from the widget layout.
 * @param view
 */
void TimelineGraphics::deleteView(TimelineView* view)
{
    //remove the layout
    layout->removeWidget(view);
    timelinelist->removeFrame(layout->indexOf(view));
    //clean up
    delete view->frame;
    delete view;
    selectedView = NULL;
}

/**
 * @brief TimelineGraphics::deleteCurrentView
 * Determines the current selected view and deletes it.
 * selects a new frame for and displays it in the animation view.
 * @return
 */
int TimelineGraphics::deleteCurrentView()
{
    // get index of view to be deleted
    int index = layout->indexOf(selectedView);
    //qDebug() << index;

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
    return 0;
}

/**
 * @brief TimelineGraphics::playback
 * Begins playback at index start.
 * @param start
 * @return
 */
int TimelineGraphics::playback(int start)
{
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

/**
 * @brief TimelineGraphics::restartPlayback
 * Calls playback at index 0.
 */
void TimelineGraphics::restartPlayback()
{
    playback(0);
}

/**
 * @brief TimelineGraphics::resumePlayback
 * Calls playback at index of selected frame.
 */
void TimelineGraphics::resumePlayback()
{
    playback(layout->indexOf(selectedView));
}

/**
 * @brief TimelineGraphics::stopPlayback
 */
void TimelineGraphics::stopPlayback()
{
    isPlaying = false;
}

/**
 * @brief TimelineGraphics::gotoCurrentFrame
 */
void TimelineGraphics::gotoCurrentFrame()
{
    emit selectedView->iWasSelected(selectedView);
}

/**
 * @brief TimelineGraphics::DurationChanged
 * This slot recieves the signal valuChanged from the editor
 * @param newDuration
 */
void TimelineGraphics::DurationChanged(int newDuration)
{
    selectedView->frame->duration = newDuration;
}
