#ifndef PIXEL_H
#define PIXEL_H

#include <QObject>
#include <QWidget>

class Pixel
{
public:
    Pixel();
    void createPixel(qreal,qreal,int,int,int);
    qreal returnX();
    qreal returnY();
    int returnR();
    int returnG();
    int returnB();
    int setR(int);
    int setG(int);
    int setB(int);
private:
    int x;
    int y;
    int r;
    int g;
    int b;
};

#endif // PIXEL_H
