#ifndef WRITE_H
#define WRITE_H
#include <QString>
#include "global.h"
#include "frame.h"
#include <QHBoxLayout>
#include "timelineview.h"
#include "storagetimeline.h"
#include "frame.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QTime>

class writefile
{
public:
        writefile();
        void write(QString filename, QHBoxLayout * frames);
        double* make2(int);
        int** populate(Frame *, int**, int);
        double* populate2(double, double*, int);
        int** make(int);

private:
        int countFrames(QHBoxLayout * frames);
        void streamFrame(Frame* frame, QTextStream *stream);
        void streamTimeStamp(int duration, QTextStream *stream);
};

#endif // WRITE_H
