//
// Created by dipak on 05.08.18.
//

#ifndef METRONOME_MAINWINDOW_H
#define METRONOME_MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QGroupBox>
#include "Timer.h"
#include "Ticker.h"


class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setMainWindow();
    void createMenu();
    void createVolumeBox();
    void createBPMBox();
    void createButtonBox();

    QGroupBox *volumeGroupBox;
    QGroupBox *BPMGroupBox;
    QGroupBox *buttonBox;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QWidget *wdg;
    QSlider *BPMSlider;
    QSlider *volSlider;
    QLabel *volumeLabel;
    QSpinBox *spinBox;
    QLabel *label;

    Ticker* ticker;
    Timer* timer;

};


#endif //METRONOME_MAINWINDOW_H
