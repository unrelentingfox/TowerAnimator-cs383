#include "frame.h"

Frame::Frame()
{

}
/**
 * @brief Frame::addPixel
 * @param newPixel
 * Adds a pixel to the vector pixel_list.
 */
void Frame::addPixel(Pixel newPixel)
{

    if(pixel_list.isEmpty()==true)
    {
        qDebug() << "adding 1";
        Frame::pixel_list.append(newPixel);
    }
    else
    {
        bool is_present=Frame::searchVector(newPixel);
        if(is_present==false)
            Frame::pixel_list.append(newPixel);

    }
}
/**
 * @brief Frame::searchVector
 * @param newPixel
 * @return
 * Iterates through the vector,calling a compare function between newPixel and currentPixel,the latter of which is the returned by the iterator.
 * If they match, set the colors of currentPixel to whatever is currently selected by the user.
 */
bool Frame::searchVector(Pixel newPixel)
{
    QMutableVectorIterator<Pixel> iterator(pixel_list);
    bool compare;
    iterator.toFront();
    while(iterator.hasNext()==true)
    {
        qDebug() << "Searching";

        Pixel currentPixel=iterator.next();
        compare=Frame::comparePixels(newPixel,currentPixel);
        if (compare==true)
        {
            currentPixel.setR(newPixel.returnR());
            currentPixel.setG(newPixel.returnG());
            currentPixel.setB(newPixel.returnB());
            qDebug() << "set new colors";
            currentPixel.paintPixel(QColor(newPixel.returnR(),newPixel.returnG(),newPixel.returnB()));
            return true;

        }


        qDebug() << "Not found in Vector";
    }
    if(compare==false)
        return false;
}
/**
 * @brief Frame::deleteSearch
 * @param newPixel
 * Deletes a pixel from pixel_list
 */
void Frame::deleteSearch(Pixel newPixel)
{
QMutableVectorIterator<Pixel> iterator(pixel_list);
bool compare;
iterator.toFront();
while(iterator.hasNext()==true)
{
    qDebug() << "Searching";

    Pixel currentPixel=iterator.next();
    compare=Frame::comparePixels(newPixel,currentPixel);
    if(compare==true)
    {
        iterator.remove();
    }
}
}
/**
 * @brief Frame::comparePixels
 * @param newPixel
 * @param currentPixel
 * @return
 * Compares the x and y coordinates of two pixels passed to it.
 */
bool Frame::comparePixels(Pixel newPixel,Pixel currentPixel)
{
    qreal newx=newPixel.returnX();
    qreal newy=newPixel.returnY();
    qreal currentx=currentPixel.returnX();
    qreal currenty=currentPixel.returnY();
    qDebug() << "Comparing";
    if(newx==currentx && newy==currenty)
    {
        qDebug() << "Found in vector";
        return true;
    }
    else
    {
        return false;
    }
}
