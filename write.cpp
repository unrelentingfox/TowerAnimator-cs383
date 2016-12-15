#include "write.h"
#include "timelineview.h"
#include "storagetimeline.h"
#include "frame.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QList>

writefile::writefile()
{

}

/**
 * @brief writefile::make
 * @param noframes
 * @return wr[][]
 * Returns a 2 dimensional array with the correct dimensions based on the number of frames
 * @author Alex Wezensky
 */
int** writefile::make(int noframes){
    int** wr = new int*[Globals::TOWER_SIZE_X*3];
    for(int i = 0; i < Globals::TOWER_SIZE_X*3; i++){
        wr[i] = new int[Globals::TOWER_SIZE_Y*noframes];
        for(int j = 0; j < Globals::TOWER_SIZE_Y*noframes; j++){
            wr[i][j] = 0;
        }
    }
    return wr;
}
/**
 * @brief writefile::populate
 * @param frame
 * @param wr
 * @param framenumber
 * @return wr[][]
 * Populates the array made in the previous function with the RGB values of the frames at their locations.
 * Called once for each frame, places the next frame's RGB values in the next 10 rows of the array.
 * @author Alex Wezensky
 */
int** writefile::populate(Frame * frame, int** wr, int framenumber){
    QList<Pixel *> pList = frame->getTowerContents();
    //qDebug() << pList;

    QList<Pixel *>::iterator i;
    Pixel * tPixel;
    int j = 0;
    //populate the array with pixel data
    for (i = pList.begin(); i != pList.end(); i++){
        tPixel = qgraphicsitem_cast<Pixel*>(i.operator *());
        //qDebug() << tPixel->towerPos() << tPixel->red() << tPixel->green() << tPixel->blue() << pList.size();
        QPointF p = tPixel->towerPos();
        int x = p.x();
        int y = p.y();
        y = framenumber*10 + y;
        //qDebug() << x << y;
        wr[x*3][y] = tPixel->red();
        //qDebug() << wr[x*3][y] << tPixel->red();
        wr[(x*3)+1][y] = tPixel->green();
        wr[(x*3)+2][y] = tPixel->blue();
        //QString myString = QString::QPointF(tPixel->towerPos());
        //QStringList myStringList = myString.split(')').first().split(',');
        //qDebug() << myStringList.first() << myStringList.last();
    }
    //qDebug() << wr;
    for(int i = 0; i < Globals::TOWER_SIZE_X*3; i++)
        for(int j = 0; j < Globals::TOWER_SIZE_Y*2; j++)
    //        qDebug() << wr[i][j] << " i " << i << " j " << j;
    return wr;
}
/**
 * @brief writefile::write
 * @param nameoffile
 * @param write
 * @param noframes
 * Writes the contents of the array filled in the last function to the file with the name given by the user.
 * @author Alex Wezensky
 */
void writefile::write(QString nameoffile, int** write, int noframes)
{
    //QList<Pixel *> pList = frame->getTowerContents();
    //qDebug() << pList;
    QString filename = nameoffile;
    QFile file(filename);
    //int wr[Globals::TOWER_SIZE_X*3][Globals::TOWER_SIZE_Y] = {0}; //x=4, y=10
    int** wr = write;
    for(int i = 0; i < Globals::TOWER_SIZE_X*3; i++)
        for(int j = 0; j < Globals::TOWER_SIZE_Y*2; j++)
    //        qDebug() << wr[i][j];

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // We're going to stream text to the file
        QTextStream stream( &file );
        stream << "0.3\n"
               << "255 191 0 0 0 0 0 0 255\n"
               << "0 0 0 128 128 128 255 0 0 255 95 0 255 191 0 223 255 0 127 255 0 31 255 0 0 255 63 0 255 159 0 255 255 0 159 255 0 63 255 31 0 255 127 0 255 223 0 255 255 0 191 255 0 95\n"
               << "255 255 255 211 211 211 127 0 0 127 47 0 127 95 0 111 127 0 63 127 0 15 127 0 0 127 31 0 127 79 0 127 127 0 79 127 0 31 127 15 0 127 63 0 127 111 0 127 127 0 95 127 0 47\n"
               << noframes << " " << Globals::TOWER_SIZE_Y << " " << Globals::TOWER_SIZE_X << endl
               << "00:00.000\n";
        for(int j = 0; j < Globals::TOWER_SIZE_Y*noframes; j++){
            for(int i = 0; i < Globals::TOWER_SIZE_X*3; i=i+3){
                //printf("wr[%d][%d] = %d\n", i, j, wr[i][j]);
                stream << wr[i][j] << " ";
                //printf("wr[%d][%d] = %d\n", i+1, j, wr[i+1][j]);
                stream << wr[i+1][j] << " ";
                //printf("wr[%d][%d] = %d\n", i+2, j, wr[i+2][j]);
                stream << wr[i+2][j] << " ";
            }
            stream << endl;

            if((j+1) % 10 == 0)
                stream << endl;

        }
        file.close();
    }
}
