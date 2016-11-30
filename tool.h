#ifndef TOOL_H
#define TOOL_H
#include "global.h"

class Tool
{
public:
    Tool();
    setToolDraw();
    setToolErase();
    setToolMove();
private:
    int current;
};

#endif // TOOL_H
