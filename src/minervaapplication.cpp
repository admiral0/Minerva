#include "minervaapplication.h"
//Initialize instance
MinervaApplication* MinervaApplication::app(0);
MinervaApplication::MinervaApplication(int &argc,char** &argv) :
    QApplication(argc,argv){
    app=this;
    setOrganizationName("admiral0");
    setApplicationName("Minerva");
    settings=new MinervaSettings();
    window=new MinervaWindow();
    window->show();
}
MinervaSettings* MinervaApplication::getSettings(){
        return settings;
}
MinervaApplication* MinervaApplication::instance(){
    return app;
}
