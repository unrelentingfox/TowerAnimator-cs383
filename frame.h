#ifndef FRAME_H
#define FRAME_H
#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QVector>
#include "pixel.h"
#include <QMutableVectorIterator>
/**
 * @brief The Frame class
 * A collection of pixels and operations on them. AKA object class
 */
class Frame
{
public:
    Frame();
    QVector<Pixel> pixel_list;
    void addPixel(Pixel);
    bool searchVector(Pixel);
    bool comparePixels(Pixel,Pixel);
    void deleteSearch(Pixel);

};

#endif // FRAME_H
