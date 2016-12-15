#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QGraphicsScene>
#include <QHboxLayout>

#include "global.h"
#include "read.h"
#include "frame.h"
#include "timelineview.h"
#include "timelinegraphics.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void ScrollToSelected(TimelineView *view);
private slots:
    void drawButtonPress();
    void eraseButtonPress();
    void moveButtonPress();

    void on_actionNew_File_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionImport_triggered();

private:
    Ui::MainWindow *ui;
    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader;
    void addFramePixel(QGraphicsScene* scene, int y, int x);
    void addTimelineFrame(QHBoxLayout* layout );
    QString fileName;
    bool editedSinceLastSave = false;
    readfile* rf;
    TimelineGraphics* timeline;
};

#endif // MAINWINDOW_H
