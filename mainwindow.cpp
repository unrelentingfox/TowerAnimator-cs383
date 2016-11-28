#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timelineGraphics.h"
#include <QGraphicsGridLayout>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TimelineGraphics timeline;
//    ui->scrollArea->setWidget(timeline.timelineWidget());


    //connect draw and erase buttons to the tool variable in AnimationView
    connect(ui->drawButton, SIGNAL (released()), this, SLOT (drawButtonPress()));
    connect(ui->eraseButton, SIGNAL (released()), this, SLOT (eraseButtonPress()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawButtonPress()
{
    ui->AnimationWidget->setTool(AnimationView::DRAW);
}

void MainWindow::eraseButtonPress()
{
    ui->AnimationWidget->setTool(AnimationView::ERASE);
}

void MainWindow::moveButtonPress()
{
    ui->AnimationWidget->setTool(AnimationView::MOVE);
}



