#include "minervaapplication.h"
#include "minervawindow.h"
#include "pluginloader.h"
#include "minervaconfig.h"

int main(int argc, char *argv[])
{
    MinervaApplication a(argc, argv);
    a.setApplicationName(QObject::tr("Minerva"));
    PluginLoader* ldr= PluginLoader::instance();
    ldr->loadPlugins(QString(ROOTDIR)+"/lib/minerva/plugins");
    ldr->startAll();
    return a.exec();
}
