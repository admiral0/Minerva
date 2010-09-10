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


#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QtPlugin>

QT_BEGIN_NAMESPACE
class MinervaWindow;
class QWidget;
QT_END_NAMESPACE

class PluginInterface 
{
public:
    virtual ~PluginInterface();
    virtual void start(MinervaWindow *window);
    virtual void stop();
    virtual QWidget* configure();
    virtual QWidget* about();
};
QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(PluginInterface,
                    "org.admiral0.PluginInterface/1.0")
QT_END_NAMESPACE

#endif // PLUGININTERFACE_H
