#include "frame.h"

Frame::Frame()
{
    this->setSceneRect(0,0,Globals::ANIMATION_WINDOW_SIZE_X,Globals::ANIMATION_WINDOW_SIZE_Y);
    tower = new QGraphicsRectItem( Globals::TOWER_POSITION_X, Globals::TOWER_POSITION_Y, Globals::TOWER_WIDTH, Globals::TOWER_HEIGHT);
    this->addItem(tower);
}
