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
    QAction *quit = new QAction("&Quit", this);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    ticker = new Ticker(this);
    timer = new Timer(this);
    connect(timer, &Timer::timeout, ticker, &Ticker::playSound);
}
void MainWindow::createVolumeBox()
{
    volumeGroupBox = new QGroupBox(tr("Volume"));
    QHBoxLayout *layout = new QHBoxLayout;
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
    BPMGroupBox = new QGroupBox(tr("Metronome BPM"));
    label = new QLabel("BPM", this);
    QHBoxLayout *hboxBPMSlider = new QHBoxLayout();
    BPMSlider = new QSlider(Qt::Horizontal , this);
    spinBox = new QSpinBox(this);
    spinBox->setRange(0, 200);
    BPMSlider->setRange(0,200);
    connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            BPMSlider, &QSlider::setValue);
    connect(BPMSlider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
            spinBox, &QSpinBox::setValue);
    connect(BPMSlider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
            timer, &Timer::setTickingValue);
    hboxBPMSlider->addWidget(BPMSlider);
    hboxBPMSlider->addWidget(spinBox);
    hboxBPMSlider->addWidget(label);
    BPMGroupBox->setLayout(hboxBPMSlider);

}
void MainWindow::createButtonBox()
{
    buttonBox = new QGroupBox();
    QHBoxLayout *hboxButtons = new QHBoxLayout();

    playBtn = new QPushButton("Play", this);
    stopBtn = new QPushButton("Stop", this);

    connect(playBtn, &QPushButton::clicked ,timer, &Timer::start);
    connect(stopBtn, &QPushButton::clicked ,timer, &Timer::stop);
    hboxButtons->addWidget(playBtn, 1, Qt::AlignRight);
    hboxButtons->addWidget(stopBtn, 0);
    buttonBox->setLayout(hboxButtons);
}
