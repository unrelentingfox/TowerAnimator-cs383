#ifndef WRITE_H
#define WRITE_H
#include <QString>
#include "global.h"
#include "frame.h"

class writefile
{
    public:
        writefile();
        void write(QString, int**, int);
        int** populate(Frame *, int**, int);
        int** make(int);
};

#endif // WRITE_H
