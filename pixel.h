#ifndef PIXEL_H
#define PIXEL_H

#endif // PIXEL_H

class Pixel
{
 //   Q_OBJECT
public:
    int x; // x location
    int y; // y location
    int R; // red value
    int G; // green value
    int B; // blue value

    Pixel(int x, int y, int R, int G, int B); // Constructor
    ~Pixel(); // Destructor
};
