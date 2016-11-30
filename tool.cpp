#include "tool.h"

Tool::Tool()
{
    current = Globals::DRAW_TOOL;
}

void Tool::setToolDraw()
{
    current = Globals::DRAW_TOOL;
}

void Tool::setToolErase()
{
    current = Globals::ERASE_TOOL;
}

void Tool::setToolMove()
{
    current = Globals::MOVE_TOOL;
}
