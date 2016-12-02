#include "timelinegraphics.h"
#include "frame.h"
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsGridLayout>

TimelineGraphics::TimelineGraphics()
{
    timeline = new QWidget;
    layout = new QHBoxLayout;
    loadTimeline();
}

QWidget* TimelineGraphics::timelineWidget()
{
    return timeline;
}

void TimelineGraphics::loadTimeline()
{
    for(int i=0; i<1; i++) {
        addTimelineFrame();
    }

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
    QGraphicsView* view = new QGraphicsView;
       Frame* scene = new Frame;
         /* scene->addText("frame #");

          for(int x=0; x<4; x++) {
              for(int y=0; y<10; y++) {
                  addFramePixel(scene, x, y);
              }
          }*/
    view->setScene(scene);
    view->setMaximumWidth(100);
    emit connectNewFrame(scene);
    this->layout->addWidget(view);
}


