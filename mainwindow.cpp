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
    connect(ui->moveButton, SIGNAL (released()), this, SLOT (moveButtonPress()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawButtonPress()
{
    ui->AnimationWidget->setTool(Globals::DRAW_TOOL);
}

void MainWindow::eraseButtonPress()
{
    ui->AnimationWidget->setTool(Globals::ERASE_TOOL);
}

void MainWindow::moveButtonPress()
{
    ui->AnimationWidget->setTool(Globals::MOVE_TOOL);
}

void MainWindow::on_redLineEdit_textEdited(const QString &arg1)
{
    ui->AnimationWidget->setRed(arg1.toInt());
}

void MainWindow::on_greenLineEdit_textEdited(const QString &arg1)
{
    ui->AnimationWidget->setGreen(arg1.toInt());

}

void MainWindow::on_blueLineEdit_textEdited(const QString &arg1)
{
    ui->AnimationWidget->setBlue(arg1.toInt());
}
