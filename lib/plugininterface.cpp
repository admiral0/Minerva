#include "plugininterface.h"
#include <QWidget>

PluginInterface::PluginInterface()
{

}
void PluginInterface::start(MinervaWindow* window)
{

}
void PluginInterface::stop()
{

}
PluginInterface::~PluginInterface()
{

}
QWidget * PluginInterface::about()
{
  return new QWidget();
}
QWidget * PluginInterface::configure()
{
  return new QWidget();
}

