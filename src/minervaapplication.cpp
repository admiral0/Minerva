#include "minervaapplication.h"
#include "minervaconfig.h"
#include <QDir>
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
    loadPlugins();
    if(argc>1){
        for(int i=1;i<arguments().length();i++){
            window->openPath(&arguments().at(i));
        }
    }else{
        window->newDocument();
    }
}
MinervaSettings* MinervaApplication::getSettings(){
        return settings;
}
MinervaApplication* MinervaApplication::instance(){
    return app;
}
void MinervaApplication::loadPlugins()
{
  QString pluginpath(ROOTDIR);
  pluginpath=pluginpath+"/lib/minerva/plugins";
  QDir pluginsdir(pluginpath);
}
