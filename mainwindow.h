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

    void on_redEdit_textEdited(const QString &arg1);

    void on_greenEdit_textEdited(const QString &arg1);

    void on_blueEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
