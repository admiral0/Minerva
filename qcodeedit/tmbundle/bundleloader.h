#ifndef BUNDLELOADER_H
#define BUNDLELOADER_H

#include <QObject>
#include <QFile>
#include <QDir>

#include "../qlanguagedefinition.h"
#include "../qlanguagefactory.h"
class QXmlStreamReader;
class BundleLoader : public QObject
{
Q_OBJECT
public:
    explicit BundleLoader(QObject *parent = 0);
    static void load(QString& file, QLanguageFactory::LangData *data, QFormatScheme *format);
    static void load(QDir& file, QLanguageFactory::LangData *data, QFormatScheme *format);

signals:

public slots:
private:
    static bool isType(QString name);
    static QList<QVariant> readArray(QXmlStreamReader*);

};

#endif // BUNDLELOADER_H
