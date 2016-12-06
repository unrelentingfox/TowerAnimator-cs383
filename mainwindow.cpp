#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timelineGraphics.h"
#include "read.h"
#include "write.h"
#include <QGraphicsGridLayout>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QColorDialog* colorDialog = new QColorDialog(QColorDialog::NoButtons);
    colorDialog->setOption(QColorDialog::NoButtons, true);
    ui->colorSelector->addWidget(colorDialog);
    connect(colorDialog, SIGNAL(currentColorChanged(QColor*)), ui->AnimationWidget, SLOT(colorChange(QColor*)));

    TimelineGraphics* timeline = new TimelineGraphics;
    ui->timelineArea->setWidget(timeline->timelineWidget());
    // make timeline instance

    //connect draw and erase buttons to the tool variable in AnimationView
    connect(ui->drawButton, SIGNAL (released()), this, SLOT (drawButtonPress()));
    connect(ui->eraseButton, SIGNAL (released()), this, SLOT (eraseButtonPress()));
    connect(ui->moveButton, SIGNAL (released()), this, SLOT (moveButtonPress()));
    connect(ui->AddFrame, SIGNAL(released()), timeline, SLOT (addTimelineFrame()));
    connect(timeline, SIGNAL( testSignal(Frame*)), ui->AnimationWidget, SLOT(loadFrame(Frame*)));
    connect(timeline, SIGNAL(connectNewFrame(TimelineView*)), ui->AnimationWidget, SLOT(acceptFrameConnection(TimelineView*)));
    connect(ui->delteFrame, SIGNAL(released()), timeline, SLOT(deleteCurrentView()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawButtonPress()
{
    ui->AnimationWidget->setTool(Globals::DRAW_TOOL);
    editedSinceLastSave = true;
    //instead, call animation view instance, call mouse press event??
}

void MainWindow::eraseButtonPress()
{
    ui->AnimationWidget->setTool(Globals::ERASE_TOOL);
    editedSinceLastSave = true;
}

void MainWindow::moveButtonPress()
{
    ui->AnimationWidget->setTool(Globals::MOVE_TOOL);
    editedSinceLastSave = true;
}

void MainWindow::colorButtonPress()
{/*
    //QWidget *p;
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid()){
        printf("HI");
    }

*/}

void MainWindow::on_redLineEdit_textEdited(const QString &arg1)
{
    ui->AnimationWidget->setRed(arg1.toInt());
    editedSinceLastSave = true;
}

void MainWindow::on_greenLineEdit_textEdited(const QString &arg1)
{
    ui->AnimationWidget->setGreen(arg1.toInt());
    editedSinceLastSave = true;

}

void MainWindow::on_blueLineEdit_textEdited(const QString &arg1)
{
    ui->AnimationWidget->setBlue(arg1.toInt());
    editedSinceLastSave = true;
}

void MainWindow::on_actionNew_File_triggered()
{
    //if the file is edited
        if (editedSinceLastSave == true)
        {
            QMessageBox::StandardButton Save;
            Save = QMessageBox::question(this, "",
                                               "This file has unsaved changes. "
                                               "Are you sure you want to discard changes?",
                                                QMessageBox::Yes|QMessageBox::No);
            if(Save == QMessageBox::Yes)
            {
                //call timeline deconstructor
                //call timeline constructor (create new timeline)
                editedSinceLastSave = false;
            }
            else if (Save == QMessageBox::No)
            {
                // do nothing
            }
        }
        else
        {
            // do nothing
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (editedSinceLastSave == false)
       {
           // do nothing
       }
       else
       {
           // get the file name and location of where it will be saved
           fileName = QFileDialog::getOpenFileName(this,
           tr("Open File"), "/home/", tr("Tan Files (*.tan *.tan2 *.ani)"));
           // all changes have been saved
           editedSinceLastSave = false;
   }
}

void MainWindow::on_actionSave_As_triggered()
{
    // get the file name and location of where it will be saved
    fileName = QFileDialog::getOpenFileName(this,
    tr("Open File"), "/home/", tr("Tan Files (*.tan *.tan2)"));
    // all changes have been saved
    editedSinceLastSave = false;
}

void MainWindow::on_actionImport_triggered()
{
    // get the file name and location import file
    fileName = QFileDialog::getOpenFileName(this,
    tr("Open File"), "/home/", tr("Tan Files (*.tan *.tan2)"));
    readfile f;
    f.read(fileName);
}

/**
 * @brief MainWindow::on_actionExport_triggered
 *        Asks user for .tan file name, and calls write, which saves the data in a .tan format
 * @author Alex Wezensky
 */
void MainWindow::on_actionExport_triggered()
{
    //save and name the new exported tan file
    fileName = QFileDialog::getSaveFileName(this, tr("Export File"), "/home/", tr("Tan Files (*.tan *.tan2)"));
    writefile w;
    w.write(fileName);
}

void MainWindow::on_keyFrameButton_clicked()
{
    // call storage timeline add frame
}

/**
 * @brief MainWindow::on_actionColor_triggered
 *        Adds "color" option in File menu, sends color info in the same way
 *        that it is sent by editing the values individually.
 * @author Alex Wezensky
 */
void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    ui->AnimationWidget->setRed(color.red());
    ui->AnimationWidget->setGreen(color.green());
    ui->AnimationWidget->setBlue(color.blue());
    editedSinceLastSave = true;
}
