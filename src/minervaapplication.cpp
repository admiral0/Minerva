#include "minervaapplication.h"

MinervaApplication::MinervaApplication(int &argc,char** &argv) :
    QApplication(argc,argv){
    setOrganizationName("admiral0");
    setApplicationName("Minerva");
    setApplicationVersion("0.1-dev");
    settings=new MinervaSettings();
}

MinervaSettings* MinervaApplication::getSettings(){
        return settings;
}
