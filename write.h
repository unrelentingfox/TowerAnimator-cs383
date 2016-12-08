#ifndef WRITE_H
#define WRITE_H
#include <QString>
#include "global.h"
#include "frame.h"

class writefile
{
    public:
        writefile();
        void write(QString, Frame *);
};

#endif // WRITE_H
