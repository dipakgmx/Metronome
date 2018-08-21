#include <QApplication>
#include "Ticker.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    //Check if media files actually exist
    if (  (!QFile((QFileInfo(".").absolutePath() + "/MediaFiles/high.mp3")).exists())
        ||(!QFile((QFileInfo(".").absolutePath() + "/MediaFiles/low.mp3" )).exists())){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Media files missing!");
        msgBox.exec();
        return 1;
    }
    QStyle* fusion = QStyleFactory::create("Fusion");
    QApplication::setStyle(fusion);
    MainWindow window;
    window.resize(400, 200);
    window.setWindowTitle("Metronome");
    window.show();


    return QApplication::exec();
}
