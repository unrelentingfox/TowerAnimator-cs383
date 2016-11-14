#include <QLinkedList>
#include <QString>
#include "frame.h"
#include "object.h"

class Timeline : public QLinkedList
{
   // Q_OBJECT

public:
    int currFrame; // ??
    QLinkedList<Frame> frames;
    Timeline();
    ~Timeline();
    // add frame to timeline
    void addFrame(double duration);
    // remove frame from timeline
    void removeFrame(int frameNum);

};
