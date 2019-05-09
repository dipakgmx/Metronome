#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setMainWindow();
    void createMenu();
    void createVolumeBox();
    void createBPMBox();
    void createButtonBox();
    void createCheckBox();

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
    QCheckBox *firstBeatBox;

    Ticker* ticker;
    Timer* timer;
};

#endif // MAINWINDOW_H
