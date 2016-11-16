#include "timelinegraphics.h"
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsGridLayout>

TimelineGraphics::TimelineGraphics()
{
    timeline = new QWidget;
    loadTimeline();
}

QWidget* TimelineGraphics::timelineWidget()
{
    return timeline;
}

void TimelineGraphics::loadTimeline() {
    layout = new QHBoxLayout;
    for(int i=0; i<50; i++) {
        addTimelineFrame(layout);
    }

    timeline->setLayout(layout);
    timeline->setMaximumHeight(500);
}

void TimelineGraphics::addFramePixel(QGraphicsScene* scene, int x, int y)
{
   QGraphicsRectItem* item1 = new QGraphicsRectItem(x*15,y*15+20,10,10);
   item1->setBrush(QBrush(Qt::red));
   scene->addItem(item1);
}

void TimelineGraphics::addTimelineFrame(QHBoxLayout* layout )
{
    QGraphicsView* view = new QGraphicsView;
       QGraphicsScene* scene = new QGraphicsScene;
          scene->addText("frame #");

          for(int x=0; x<4; x++) {
              for(int y=0; y<10; y++) {
                  addFramePixel(scene, x, y);
              }
          }
    view->setScene(scene);
    view->setMaximumWidth(100);
    layout->addWidget(view);
}
