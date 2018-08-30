//
// Created by dipak on 05.08.18.
//

#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setMainWindow();
}
void MainWindow::setMainWindow()
{
    //Creating new widget wdg to set layout manually
    wdg = new QWidget(this);
    QVBoxLayout *vbox = new QVBoxLayout(wdg);

    createMenu();

    //Creating Buttons
    createButtonBox();

    //Creating BPM sliders
    createBPMBox();

    //Creating volume sliders
    createVolumeBox();


    //vbox->addStretch(1);
    vbox->addWidget(volumeGroupBox);
    vbox->addWidget(BPMGroupBox);
    vbox->addWidget(buttonBox);
    setCentralWidget(wdg);
}
void MainWindow::createMenu()
{
    //Create menus
    QAction *quit = new QAction("&Quit", this);
    QMenu *file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit, &QAction::triggered,
        [=]() {
            QApplication::quit();
        });

    //Creating instances of ticker and timer here
    //Done so that the connection between ticker and timer is possible
    ticker = new Ticker(this);
    timer = new Timer(this);
    connect(timer, &Timer::timeout, ticker, &Ticker::playSound);
}
void MainWindow::createVolumeBox()
{
    volumeGroupBox = new QGroupBox(tr("Volume"), this);
    QHBoxLayout *layout = new QHBoxLayout();
    volSlider = new QSlider(Qt::Horizontal , this);
    volSlider->setRange(0,100);
    volSlider->setSliderPosition(60);
    volumeLabel = new QLabel("60", this);
    connect(volSlider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
            volumeLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(volSlider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
            ticker, static_cast<void (Ticker::*)(int)>(&Ticker::setVolumeLevel));
    layout->addWidget(volSlider);
    layout->addWidget(volumeLabel);
    volumeGroupBox->setLayout(layout);
}
void MainWindow::createBPMBox()
{
    BPMGroupBox = new QGroupBox(tr("Metronome BPM"), this);
    label = new QLabel("BPM", this);
    QHBoxLayout *hboxBPMSlider = new QHBoxLayout();
    BPMSlider = new QSlider(Qt::Horizontal , this);
    spinBox = new QSpinBox(this);
    spinBox->setRange(1, 200);
    BPMSlider->setRange(1,200);

    // Connect spinBox to set slider
    connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        [=] () {
        BPMSlider->setValue(spinBox->value());
    });

    // Connect Slider to set BPM to spinBox
    connect(BPMSlider, &QSlider::valueChanged,
        [=] () {
        spinBox->setValue(BPMSlider->value());
    });

    // Connect the BPM Slider values to the ticking value of timer class
    connect(BPMSlider, &QSlider::valueChanged,
            [=] () {
                timer->setTickingValue(BPMSlider->value());
            });
    BPMSlider->setSliderPosition(60);
    hboxBPMSlider->addWidget(BPMSlider);
    hboxBPMSlider->addWidget(spinBox);
    hboxBPMSlider->addWidget(label);
    BPMGroupBox->setLayout(hboxBPMSlider);

}
void MainWindow::createButtonBox()
{
    buttonBox = new QGroupBox(this);
    QHBoxLayout *hboxButtons = new QHBoxLayout();

    playBtn = new QPushButton("Play", this);
    stopBtn = new QPushButton("Stop", this);

    connect(playBtn, &QPushButton::clicked ,timer, &Timer::start);
    connect(stopBtn, &QPushButton::clicked ,timer, &Timer::stop);
    hboxButtons->addWidget(playBtn, 1, Qt::AlignRight);
    hboxButtons->addWidget(stopBtn, 0);
    buttonBox->setLayout(hboxButtons);
}

