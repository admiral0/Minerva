#include "minervatabwidget.h"
#include <QPushButton>
MinervaTabWidget::MinervaTabWidget(QWidget *parent):QTabWidget(parent)
{
    appSettings=new MinervaSettings();
    QPushButton *newDoc=new QPushButton("New");
    QPushButton *settings=new QPushButton("Settings");
    setCornerWidget(newDoc,Qt::TopLeftCorner);
    setCornerWidget(settings);
}
//TODO settingstab and newDoc tab
