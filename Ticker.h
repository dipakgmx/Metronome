//
// Created by dipak on 05.08.18.
//

#ifndef METRONOME_TICKER_H
#define METRONOME_TICKER_H
#include <QtMultimedia>
#include <QtWidgets>

class Ticker : public QObject
{
Q_OBJECT
public:
    explicit Ticker(QObject *parent = nullptr);

public slots:
    void playSound();
    void setVolumeLevel(int volLevelRequest);
    void reqToStressFirstBeat();

private:
    void playHigh();
    void playLow();
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    int counter;
    bool stressFirstBeat;
};


#endif //METRONOME_TICKER_H
