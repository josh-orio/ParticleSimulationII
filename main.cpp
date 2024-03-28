#include <QApplication>
#include <QtWidgets>
#include <QDebug>

//#include "vector.hpp"
//#include "particle.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMainWindow window;
    window.resize(640, 480);
    window.show();
    window.setWindowTitle(
            QApplication::translate("toplevel", "Particle Simulation II"));

    return QApplication::exec();
}