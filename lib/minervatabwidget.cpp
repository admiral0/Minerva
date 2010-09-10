#include "minervatabwidget.h"
#include "minervawindow.h"
#include "minervaconfig.h"
#include <QToolButton>
MinervaTabWidget::MinervaTabWidget(QWidget *parent):QTabWidget(parent)
{
    qDebug("Creating Tab Widget");
    appSettings=new MinervaSettings();
    QToolButton *newDoc=new QToolButton();
    QToolButton *settings=new QToolButton();
    newDoc->setIcon(QIcon(QString(ROOTDIR)+"/share/minerva/icons/new.png"));
    settings->setIcon(QIcon(QString(ROOTDIR)+"/share/minerva/icons/configure.png"));
    setCornerWidget(newDoc,Qt::TopLeftCorner);
    setCornerWidget(settings);
    connect(newDoc,SIGNAL(clicked()),MinervaWindow::instance(),SLOT(newDocument()));
}
//TODO settingstab tab
