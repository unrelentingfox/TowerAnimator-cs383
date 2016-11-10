#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
};

#endif // MAINWINDOW_H
