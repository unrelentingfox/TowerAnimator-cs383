#ifndef READ_H
#define READ_H
#include<QString>
#include <QObject>
#include <QTest>
#include "frame.h"
#include "pixel.h"

/**
 * @brief The readfile class contains the member loadFrame() which is used to connect
 * the frames created by readfile() to the slots in the timeline.
 */
class readfile : public QObject
{
    Q_OBJECT
signals:
    void loadFrame(Frame*);
public:
    virtual ~readfile() {};
    readfile();
    int read(QString);
    bool loading;
};

#endif // READ_H
