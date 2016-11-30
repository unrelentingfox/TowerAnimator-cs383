#ifndef TOOL_H
#define TOOL_H
#include "global.h"

class Tool
{
public:
    Tool();
    void setToolDraw();
    void setToolErase();
    void setToolMove();
private:
    int current;
};

#endif // TOOL_H
