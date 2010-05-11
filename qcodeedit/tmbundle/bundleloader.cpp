#include "bundleloader.h"
#include <QDomDocument>
#include <QStringList>
#include <QDebug>

BundleLoader::BundleLoader(QObject *parent) :
    QObject(parent)
{
}
void BundleLoader::load(QString& bndl, QLanguageFactory::LangData *data, QFormatScheme *format){
    QDir f(bndl);
    load(f,data,format);
}

void BundleLoader::load(QDir& bndl, QLanguageFactory::LangData *data, QFormatScheme *format){
    QDomDocument dom;
    qDebug() << "Processing bundle in dir " <<bndl.absolutePath() ;
    QFile file(bndl.absolutePath()+QDir::separator()+"info.plist");
    if(!file.open(QIODevice::ReadOnly))
        return;
    if(!dom.setContent(&file)){
        return;
    }
        //TODO
    file.close();
}
