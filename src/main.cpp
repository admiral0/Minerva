#include "minervaapplication.h"
#include "minervawindow.h"

int main(int argc, char *argv[])
{
    MinervaApplication a(argc, argv);
    a.setApplicationName(QObject::tr("Minerva"));
    return a.exec();
}
