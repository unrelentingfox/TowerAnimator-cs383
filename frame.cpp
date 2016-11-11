#include "frame.h"

Frame::Frame()
{

}

void Frame::addPixel(Pixel newPixel)
{
    if(pixel_list.isEmpty()==true)
        Frame::pixel_list.append(newPixel);
    else
    {
        Frame::searchVector(newPixel);
    }
}
void Frame::searchVector(Pixel newPixel)
{
    QMutableVectorIterator<Pixel> iterator(pixel_list);

    iterator.toFront();
    while(iterator.hasNext()==true)
    {
        Pixel p=iterator.next();
        bool compare=Frame::comparePixels(newPixel,p);
        if (compare==false)
            break;
        qDebug() << "test";
    }

}
bool Frame::comparePixels(Pixel newPixel,Pixel currentPixel)
{
    qreal newx=newPixel.returnX();
    qreal newy=newPixel.returnY();
    qreal currentx=currentPixel.returnX();
    qreal currenty=currentPixel.returnY();
    if(newx==currentx && newy==currenty)
    {
        currentPixel.setR(newPixel.returnR());
        currentPixel.setG(newPixel.returnG());
        currentPixel.setB(newPixel.returnB());
        return true;
    }
    else
    {
        Frame::pixel_list.append(newPixel);
        return false;
    }
}
