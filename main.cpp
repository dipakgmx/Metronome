#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Check if media files actually exist
    if (  (!QFile(":/MediaFiles/high.mp3").exists())
        ||(!QFile(":/MediaFiles/high.mp3").exists()))
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Media files missing!");
        msgBox.exec();
        return 1;
    }
    QStyle* fusion = QStyleFactory::create("Fusion");
    QApplication::setStyle(fusion);
    MainWindow* window = new MainWindow();
    window->resize(400, 200);
    window->setWindowTitle("Metronome");
    window->show();
    return QApplication::exec();
}
