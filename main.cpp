#include <QApplication>
#include <QDebug>
#include "Ticker.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow window;

    window.resize(400, 200);
    //window.setWindowTitle("Metronome");
    window.show();


    return app.exec();
}
