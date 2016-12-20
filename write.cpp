#include "write.h"

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
 * @brief writefile::make2
 * @param noframes
 * @return fdur
 * Returns an array with the correct dimensions for storing the time stamps based on the number of frames
 * @author Alex Wezensky
 */
double* writefile::make2(int noframes){
    double* fdur = new double[noframes];
    //qDebug() << noframes;
    for(int i = 0; i < noframes; i++){
        fdur[i] = 0;
    }
    return fdur;
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
    // compiler said this was unused. removed. int j = 0;
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
    //for(int i = 0; i < Globals::TOWER_SIZE_X*3; i++)
    //    for(int j = 0; j < Globals::TOWER_SIZE_Y*2; j++)
    //        qDebug() << wr[i][j] << " i " << i << " j " << j;
    return wr;
}

/**
 * @brief writefile::populate2
 * @param duration
 * @param fdur
 * @param framenumber
 * @return fdur
 * Populates the array made in the previous function with the durations of the frames.
 * Called once for each frame.
 * @author Alex Wezensky
 */
double *writefile::populate2(double duration, double * fdur, int framenumber){
    fdur[framenumber] = duration;
    qDebug() << framenumber;
    return fdur;
}

/**
 * @brief writefile::write
 * @param nameoffile
 * @param write
 * @param noframes
 * Writes the contents of the array filled in the last function to the file with the name given by the user.
 * Also inserts the time stamps in their proper places after converting them to the proper format.
 * @author Alex Wezensky
 */
void writefile::write(QString filename, QHBoxLayout * frames){
    QFile file(filename);
    Frame * frame;
    QTime duration;

    int numberOfFrames = this->countFrames(frames);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream( &file );

        //Add the default header info for .tan file
        stream << "0.3\n"
               << "255 191 0 0 0 0 0 0 255\n"
               << "0 0 0 128 128 128 255 0 0 255 95 0 255 191 0 223 255 0 127 255 0 31 255 0 0 255 63 0 255 159 0 255 255 0 159 255 0 63 255 31 0 255 127 0 255 223 0 255 255 0 191 255 0 95\n"
               << "255 255 255 211 211 211 127 0 0 127 47 0 127 95 0 111 127 0 63 127 0 15 127 0 0 127 31 0 127 79 0 127 127 0 79 127 0 31 127 15 0 127 63 0 127 111 0 127 127 0 95 127 0 47\n"
               << numberOfFrames << " " << Globals::TOWER_SIZE_Y << " " << Globals::TOWER_SIZE_X << endl
               << "00:00.000\n";

            for(int i = 0; i < numberOfFrames; i++){
                //get current frame
                frame = dynamic_cast<TimelineView *>(frames->itemAt(i)->widget())->frame;

                //print frame
                streamFrame(frame, &stream);

                //Print the timestamp after all frames except the last one (to follow .tan format)
                if((i+1) < numberOfFrames){
                    duration = duration.addMSecs(frame->getDuration());
                    stream << "test" << endl;
                }
            }
            stream << endl;

        }
        file.close();
}


void writefile::streamFrame(Frame *frame, QTextStream *stream)
{
    //Create an array to represent the frame
    int tower[Globals::TOWER_SIZE_X][Globals::TOWER_SIZE_Y][3] = {0,0,0};
    //initialize all the iterators for the above array
    int x = 0;
    int y = 0;
    int rgb = 0; // 0 = red, 1 = green, 2 = blue
    const int RGB_MAX = 3;

    //Populate the array with the pixels
    QList<Pixel *> pixels = frame->getPixels();
    for(int i = 0; i < pixels.length(); i++){
        x = pixels[i]->towerPos().x();
        y = pixels[i]->towerPos().y();
        tower[x][y][0] = pixels[i]->red();
        tower[x][y][1] = pixels[i]->green();
        tower[x][y][2] = pixels[i]->blue();
    }

    //Print the array
    for(y = 0; y < Globals::TOWER_SIZE_Y; y++){
        for(x = 0; x < Globals::TOWER_SIZE_X; x++){
            for(rgb = 0; rgb < RGB_MAX; rgb++){
                *stream << tower[x][y][rgb]<< " ";
            }
        }
        *stream << "\n";
    }
}

int writefile::countFrames(QHBoxLayout *frames)
{
    int frameCount = 0;
    for(int i = 0; frames->itemAt(i) != 0; i++)
        frameCount++;

    return (frameCount + 1);
}
