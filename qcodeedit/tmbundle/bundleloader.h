#ifndef BUNDLELOADER_H
#define BUNDLELOADER_H

#include <QObject>
#include <QFile>

#include "../qlanguagedefinition.h"
#include "../qlanguagefactory.h"

class BundleLoader : public QObject
{
Q_OBJECT
public:
    explicit BundleLoader(QObject *parent = 0);
    static void load(QString& file, QLanguageFactory::LangData& data, QFormatScheme& format);
    static void load(QFile& file, QLanguageFactory::LangData& data, QFormatScheme& format);

signals:

public slots:

};

#endif // BUNDLELOADER_H
