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
    loadTimeline();
}

QWidget* TimelineGraphics::timelineWidget()
{
    return timeline;
}

void TimelineGraphics::loadTimeline()
{
    timeline->setLayout(this->layout);
    timeline->setMaximumHeight(500);
}

void TimelineGraphics::addFramePixel(QGraphicsScene* scene, int x, int y)
{
   QGraphicsRectItem* item1 = new QGraphicsRectItem(x*15,y*15+20,10,10);
   item1->setBrush(QBrush(Qt::red));
   scene->addItem(item1);
}

void TimelineGraphics::addTimelineFrame()
{
    TimelineView* view = new TimelineView;
    Frame* scene = new Frame;

    //initialize the view
    view->frame = scene;
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setScene(scene);
    //view->setMaximumWidth(80);
    view->setFixedSize(80, 200);
   // view->setMaximumHeight(200);
    //view->scale(0.5, 0.5);

    //make connections
    emit connectNewFrame(view); //connects frame to animationview
    connect(view, SIGNAL (iWasSelected(TimelineView*)), this, SLOT (currentFrame(TimelineView*)));

    //make the new frame the selected frame
    emit view->iWasSelected(view);

    //add to layout
    this->layout->addWidget(view);

    //add to storage class
    timelinelist->addFrame(scene);
}

void TimelineGraphics::currentFrame(TimelineView* view)
{
    this->selectedView = view;
}

void TimelineGraphics::deleteView(TimelineView* view)
{
    //remove the layout
    layout->removeWidget(view);
    timelinelist->removeFrame(view->frame);
    delete view;
}

void TimelineGraphics::deleteCurrentView()
{
    // get index of view to be deleted
    TimelineView* view = this->selectedView;
    int index = layout->indexOf(view);
    std::cout << index;

    //delete the view
    deleteView(this->selectedView);

    //select a new frame based on index of last frame
    QLayoutItem* item = layout->itemAt(index);
    TimelineView* view2 = item->widget();
    //frameLayout = item->layout();
    emit view2->iWasSelected(view2);
}

