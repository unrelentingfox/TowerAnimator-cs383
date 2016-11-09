#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect draw and erase buttons to the mouseInteracion variable in AnimationGraphicsView
    connect(ui->drawButton, SIGNAL (released()), this, SLOT (drawButtonPress()));
    connect(ui->eraseButton, SIGNAL (released()), this, SLOT (eraseButtonPress()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawButtonPress()
{
    ui->AnimationView->setMouseInteraction(AnimationGraphicsView::DRAW);
}

void MainWindow::eraseButtonPress()
{
    ui->AnimationView->setMouseInteraction(AnimationGraphicsView::ERASE);
}
