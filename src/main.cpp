#include "minervaapplication.h"
#include "minervawindow.h"

int main(int argc, char *argv[])
{
    MinervaApplication a(argc, argv);
    a.setApplicationName(QObject::tr("Minerva"));
    a.setGraphicsSystem("raster");
    MinervaWindow w;
    w.show();
    if(argc > 1){
        for(int i=1;i<argc;i++){
            w.openPath(new QString(argv[i]));
        }
    }else{
        w.newDocument();
    }
    return a.exec();
}
