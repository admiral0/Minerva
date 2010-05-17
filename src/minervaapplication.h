#ifndef MINERVAAPPLICATION_H
#define MINERVAAPPLICATION_H

#include <QApplication>
#include "minervasettings.h"
#include "minervawindow.h"

class MinervaApplication : public QApplication
{
Q_OBJECT
public:
    MinervaApplication(int&,char**&);
    MinervaSettings* getSettings();
    MinervaApplication* instance();
signals:

public slots:
private:
    MinervaSettings *settings;
    MinervaWindow *window;
    static MinervaApplication *app;
};
#endif // MINERVAAPPLICATION_H
