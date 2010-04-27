#include <QtGui/QApplication>
#include "minervawindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("Minerva"));
    a.setGraphicsSystem("raster");
    MinervaWindow w;
    w.show();
    return a.exec();
}
