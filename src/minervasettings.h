#ifndef MINERVASETTINGS_H
#define MINERVASETTINGS_H

#include <QObject>
#include <QSettings>

class MinervaSettings : public QObject
{
Q_OBJECT
public:
    explicit MinervaSettings(QObject *parent = 0);

signals:

public slots:

private:
    QSettings *settings;

};

#endif // MINERVASETTINGS_H
