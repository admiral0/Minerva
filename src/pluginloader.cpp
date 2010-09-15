/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "pluginloader.h"
#include <QDir>
#include <QDebug>
#include <QPluginLoader>
#include <minervawindow.h>

PluginLoader* PluginLoader::self(0);
PluginLoader* PluginLoader::instance()
{
  if(self)
    return self;
  else
    return new PluginLoader;
}
PluginLoader::PluginLoader()
{
  plugins=new QList<PluginInterface*>;
}


PluginInterface* PluginLoader::getPlugin(QString name)
{

}
QStringList PluginLoader::getPlugins()
{

}
bool PluginLoader::loadPlugin(QString lib)
{
    QPluginLoader ldr(lib);
    QObject *obj= ldr.instance();
    PluginInterface *ifc=qobject_cast<PluginInterface *>(obj);
    if(!ldr.isLoaded()){
      qDebug()<<"Plugin" << lib << "not loaded:"<< ldr.errorString();
      return false;
    }
    plugins->append(ifc);
    return true;
}
bool PluginLoader::loadPlugins(QString dir)
{

  QDir pluginsdir(dir);
  QStringList pluginss=pluginsdir.entryList(QStringList() << QString("*.so"));
  qDebug()<<"Loading Plugins in dir"<<pluginsdir.absolutePath();
  foreach(QString plugin , pluginss){
    loadPlugin(pluginsdir.absoluteFilePath(plugin));
  }
}
void PluginLoader::startAll()
{
  int j=plugins->length();
  for(int i=0;i<j;i++){
    PluginInterface *ifc= plugins->at(i);
    ifc->start(MinervaWindow::instance());
  }
}


