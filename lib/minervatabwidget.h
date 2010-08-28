#ifndef MINERVATABWIDGET_H
#define MINERVATABWIDGET_H

#include <QTabWidget>
#include "minervasettings.h"

class MinervaTabWidget : public QTabWidget
{
public:
    MinervaTabWidget(QWidget * parent);
private:
    MinervaSettings *appSettings;
};

#endif // MINERVATABWIDGET_H
