#include "bundleloader.h"
#include <QDomDocument>

BundleLoader::BundleLoader(QObject *parent) :
    QObject(parent)
{
}
void BundleLoader::load(QString& file, QLanguageFactory::LangData& data, QFormatScheme& format){
    QFile f(file);
    load(f,data,format);
}

void BundleLoader::load(QFile& file, QLanguageFactory::LangData& data, QFormatScheme& format){
    QDomDocument dom;
    if(!file.open(QIODevice::ReadOnly))
        return;
    if(!dom.setContent(&file)){
        return;
    }

}
