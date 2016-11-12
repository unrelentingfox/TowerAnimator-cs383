#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QGraphicsScene>
#include <QHboxLayout>

#include "global.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void drawButtonPress();
    void eraseButtonPress();
    void moveButtonPress();

private:
    Ui::MainWindow *ui;
    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader;
    void addFramePixel(QGraphicsScene* scene, int y, int x);
    void addTimelineFrame(QHBoxLayout* layout );
};

#endif // MAINWINDOW_H
