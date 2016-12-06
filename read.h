#ifndef READ_H
#define READ_H
#include<QString>
#include <QObject>
#include <QTest>
#include "frame.h"
#include "pixel.h"

class readfile : public QObject
{
    Q_OBJECT
signals:
    void loadFrame(Frame*);
public:
    virtual ~readfile() {};
    readfile();
    int read(QString);
};

#endif // READ_H
