#include <QtGui/QApplication>
#include "minervawindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MinervaWindow w;
    w.show();
    return a.exec();
}
