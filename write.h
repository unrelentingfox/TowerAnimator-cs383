#ifndef WRITE_H
#define WRITE_H
#include <QString>
#include "global.h"
#include "frame.h"

class writefile
{
    public:
        writefile();
        void write(QString, int**, int, double*);
        double* make2(int);
        int** populate(Frame *, int**, int);
        double* populate2(double, double*, int);
        int** make(int);
};

#endif // WRITE_H
