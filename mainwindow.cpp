#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
