#include "minervatabwidget.h"
#include "minervawindow.h"
#include <QPushButton>
MinervaTabWidget::MinervaTabWidget(QWidget *parent):QTabWidget(parent)
{
    appSettings=new MinervaSettings();
    QPushButton *newDoc=new QPushButton("New");
    QPushButton *settings=new QPushButton("Settings");
    setCornerWidget(newDoc,Qt::TopLeftCorner);
    setCornerWidget(settings);
    connect(newDoc,SIGNAL(clicked()),MinervaWindow::instance(),SLOT(newDocument()));
}
//TODO settingstab tab
