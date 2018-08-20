#include <QApplication>
#include "Ticker.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QStyle* fusion = QStyleFactory::create("Fusion");
    QApplication app(argc, argv);
    QApplication::setStyle(fusion);

    MainWindow window;

    window.resize(400, 200);
    window.setWindowTitle("Metronome");
    window.show();


    return app.exec();
}
