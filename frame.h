#ifndef FRAME_H
#define FRAME_H
#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QVector>
#include "pixel.h"
#include <QMutableVectorIterator>
class Frame
{
public:
    Frame();
    QVector<Pixel> pixel_list;
    void addPixel(Pixel);
    void searchVector(Pixel);
    bool comparePixels(Pixel,Pixel);


};

#endif // FRAME_H
