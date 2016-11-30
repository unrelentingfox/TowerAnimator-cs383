#include "tool.h"

Tool::Tool()
{
    current = Globals::DRAW_TOOL;
}

Tool::setToolDraw()
{
    current = Globals::DRAW_TOOL;
}

Tool::setToolErase()
{
    current = Globals::ERASE_TOOL;
}

Tool::setToolMove()
{
    current = Globals::MOVE_TOOL;
}
