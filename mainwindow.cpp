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
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rf = new readfile;
    QColorDialog* colorDialog = new QColorDialog(QColorDialog::NoButtons);
    colorDialog->setOption(QColorDialog::NoButtons);
    colorDialog->setOption(QColorDialog::DontUseNativeDialog);

    ui->colorSelector->addWidget(colorDialog);
    connect(colorDialog, SIGNAL(currentColorChanged(const QColor &)), ui->AnimationWidget, SLOT(colorChange(const QColor &)));

    // make timeline instance
    timeline = new TimelineGraphics;
    ui->timelineArea->setWidget(timeline->timelineWidget());

    //set ui colors and size restraints
    ui->timelineArea->setMinimumHeight(Globals::TOWER_HEIGHT + Globals::PIXEL_SIZE*2);

    //connect ui main buttons
    connect(ui->drawButton, SIGNAL (released()), this, SLOT (drawButtonPress()));
    connect(ui->eraseButton, SIGNAL (released()), this, SLOT (eraseButtonPress()));
    connect(ui->moveButton, SIGNAL (released()), this, SLOT (moveButtonPress()));
    connect(ui->AddFrame, SIGNAL(released()), timeline, SLOT (addTimelineFrame()));
    connect(ui->delteFrame, SIGNAL(released()), timeline, SLOT(deleteCurrentView()));
    connect(ui->restart, SIGNAL(released()), timeline, SLOT(restartPlayback()));
    connect(ui->resume, SIGNAL(released()), timeline, SLOT(resumePlayback()));
    connect(ui->stop, SIGNAL(released()), timeline, SLOT(stopPlayback()));
    connect(timeline, SIGNAL(scrollToSelected(TimelineView*)), this, SLOT(ScrollToSelected(TimelineView*)));
    connect(ui->gotoCurrentFrame, SIGNAL(released()), timeline, SLOT(gotoCurrentFrame()));

    //signals for frame duration
    connect(ui->FrameDuration, SIGNAL(valueChanged(int)), timeline, SLOT(DurationChanged(int)));
    connect(timeline, SIGNAL(displayDuration(int)), ui->FrameDuration, SLOT(setValue(int)));

    connect(timeline, SIGNAL(connectNewFrame(TimelineView*)), ui->AnimationWidget, SLOT(acceptFrameConnection(TimelineView*)));

    connect(rf, SIGNAL(loadFrame(Frame*)), timeline, SLOT(addTimelineFrame(Frame*)));

    //add first frame
    timeline->addTimelineFrame();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ScrollToSelected(TimelineView* view)
{
    qDebug() << "signaled";
    if(!rf->loading && !timeline->isPlaying)
        QTest::qWait(2);
    ui->timelineArea->ensureVisible(view->pos().x(), 50);
    ui->timelineArea->ensureVisible(view->pos().x()+200, 50);


    //ui->timelineArea->ensureVisible(100000000, 0, 0, 0);
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

/**
 * @brief MainWindow::on_actionSave_As_triggered
 *        Asks user for .tan file name, and calls write, which saves the data in a .tan format
 * @author Alex Wezensky
 */
void MainWindow::on_actionSave_As_triggered()
{
    //save and name the new exported tan file
    fileName = QFileDialog::getSaveFileName(this, tr("Export File"), "/home/", tr("Tan Files (*.tan *.tan2)"));
    writefile w;
    int noframes = 1;
    w.write(fileName,timeline->layout);


// The code below did not work.//

//    /*if(ui->AnimationWidget->getCurrentFrame() != 0){
//        w.write(fileName, ui->AnimationWidget->getCurrentFrame());
//    }*/
//    int noframes = 0;
//    int** wr;
//    int** filled;
//    double * fdur;
//    double * fdurfilled;
//    //if(timeline->layout->itemAt(i) != 0){
//    for(int i = 0; timeline->layout->itemAt(i) != 0; i++)
//        noframes++;
//    wr = w.make(noframes);

//    TimelineView * var;

//    fdur = w.make2(noframes);
//    //qDebug() << duration;

//    /*for(int i = 0; i < Globals::TOWER_SIZE_X*3; i++)
//        for(int j = 0; j < Globals::TOWER_SIZE_Y*noframes; j++)
//            qDebug() << wr[i][j];*/
//    for(int i = 0; timeline->layout->itemAt(i) != 0; i++){
//        QLayoutItem* item = timeline->layout->itemAt(i);
//        var = dynamic_cast<TimelineView *> (item->widget());
//        //qDebug() << "Hi" << item << var;
//        emit var->iWasSelected(var);
//        if(ui->AnimationWidget->getCurrentFrame() != 0){
//            //w.write(fileName, ui->AnimationWidget->getCurrentFrame());
//            double duration = var->frame->duration;
//            filled = w.populate(ui->AnimationWidget->getCurrentFrame(), wr, i);
//            fdurfilled = w.populate2(duration, fdur, i);
//        }
//    }

//    w.write(fileName, filled, noframes, fdurfilled);
}

void MainWindow::on_actionImport_triggered()
{
    // get the file name and location import file
    fileName = QFileDialog::getOpenFileName(this,
    tr("Open File"), "/home/", tr("Tan Files (*.tan *.tan2)"));
    //readfile f;
    rf->read(fileName);
}
