#ifndef MINERVAAPPLICATION_H
#define MINERVAAPPLICATION_H

#include <QApplication>
#include "minervasettings.h"

class MinervaApplication : public QApplication
{
Q_OBJECT
public:
    MinervaApplication(int&,char**&);
    MinervaSettings* getSettings();

signals:

public slots:
private:
    MinervaSettings *settings;
};

#endif // MINERVAAPPLICATION_H
