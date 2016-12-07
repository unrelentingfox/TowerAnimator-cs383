#include "write.h"
//#include "struct.h"
#include "frame.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QList>

writefile::writefile()
{

}
/*QList<Pixel *> Frame::trimPixelList(QList<QGraphicsItem *> list)
{
    Pixel * tempPixel;
    QList<Pixel *> pixelList;
    QList<QGraphicsItem *>::iterator i;
    for (i = list.begin(); i != list.end(); ++i){
        // cast each graphics item to a pixel so that the pixel functions can be used to retrieve data
        tempPixel = qgraphicsitem_cast<Pixel*>(i.operator *());
        if(tempPixel != 0){
            pixelList.append(tempPixel);
        }
        qDebug() << tempPixel->towerPos() << tempPixel->red() << tempPixel->green() << tempPixel->blue();
    }
    qDebug() << pixelList;
    return pixelList;
}*/
void writefile::write(QString nameoffile)
{
    Frame a;
    QList<Pixel *> pList = a.getTowerContents();
    qDebug() << pList;
    //QString filename = "out.txt";
    QString filename = nameoffile;
    QFile file(filename);
    //int height = pList.size() / 20;     //40 pixels/frame, 5 vars/pixel -> 200 vars/frame -> 10 lines/frame
    int wr[Globals::TOWER_SIZE_X*3][Globals::TOWER_SIZE_Y]; //array length needs to be a constant value so just use the size of the tower in Globals
    //x=4, y=10

    QList<Pixel *>::iterator i;
    Pixel * tPixel;
    for (i = pList.begin(); i != pList.end(); i++){
        tPixel = qgraphicsitem_cast<Pixel*>(i.operator *());
        qDebug() << tPixel->towerPos() << tPixel->red() << tPixel->green() << tPixel->blue() << pList.size();
    }

    //qDebug() << pList.indexOf(0);//->red();

    //populate the array with pixel data
    int pLcount = 0;
    for(int j = 0; j < Globals::TOWER_SIZE_Y; j++){
        for(int i = 0; i < Globals::TOWER_SIZE_X*3; i=i+3){
            //qDebug() << "i:" << i << " j:" << j;
            wr[i][j] = pList[0]->red();
            //qDebug() << "i:" << i << " j:" << j << " red:" << pList[0]->red();
            wr[i+1][j] = pList[0]->red();
            //qDebug() << i << " " << j << " " << pList[0]->red();
            wr[i+2][j] = pList[0]->red();
            //qDebug() << i << " " << j << " " << pList[0]->red();
            //pLcount++;
            //pList.pop_front();
            //qDebug() << "lul";
        }
    }

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // We're going to stream text to the file
        QTextStream stream( &file );
        for(int i = 0; i < Globals::TOWER_SIZE_Y; i++){
            for(int j = 0; j < Globals::TOWER_SIZE_X; j++){
                printf("wr[%d][%d] = %d\n", i, j, wr[i][j]);
                stream << wr[i][j] << " ";
            }
            stream << endl;
            if((i+1) % 10 == 0){
                stream << endl;
            }
        }
        file.close();
    }
}
