#ifndef READ_H
#define READ_H
#include<QString>
#include <QObject>
#include <QTest>
#include "frame.h"
#include "pixel.h"


/**
 * @brief The readfile class used to read a tan file
 * @author Colton H
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
