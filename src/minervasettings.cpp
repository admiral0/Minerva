#include "minervasettings.h"

MinervaSettings::MinervaSettings(QObject *parent) :
    QObject(parent)
{
    settings=new QSettings("admiral0","Minerva");
}
//TODO sessions
