#include "bundleloader.h"
#include <QXmlStreamReader>
#include <QStringList>
#include <QDebug>
bool BundleLoader::isType(QString name){
    if( 
         name=="array" ||
         name=="data" ||
         name=="date" ||
         name=="dict" ||
         name=="real" ||
         name=="integer" ||
         name=="string" ||
         name=="true" ||
         name=="false"
      ){
        return true;
    }
    return false;
}
QList<QVariant> BundleLoader::readArray(QXmlStreamReader * xml){
    QList<QVariant> list;
    do{
        while(!isType(xml->name().toString())){
            xml->readNext();
            if(xml->atEnd()){
                break;
            }
        }
        if(xml->name()=="string"){
            list.append(xml->readElementText());
        }
    }while(!(xml->name()=="array" && xml->tokenType()==QXmlStreamReader::EndElement) && !xml->atEnd());
    return list;
}

BundleLoader::BundleLoader(QObject *parent) :
    QObject(parent)
{
}
void BundleLoader::load(QString& bndl, QLanguageFactory::LangData *data, QFormatScheme *format){
    QDir f(bndl);
    load(f,data,format);
}

void BundleLoader::load(QDir& bndl, QLanguageFactory::LangData *data, QFormatScheme *format){


    QXmlStreamReader xml;
    QString key;
    QVariant value;
    QString type;
    qDebug() << "Processing bundle in dir " <<bndl.absolutePath() ;
    QFile file(bndl.absolutePath()+QDir::separator()+"info.plist");
    if(!file.open(QIODevice::ReadOnly))
        return;
    xml.setDevice(&file);
    while (!xml.atEnd()) {
            xml.readNext();

            if(xml.name()=="key" ){
                key=xml.readElementText();
                //qDebug()<< "Processing "<<key;
                do
                    xml.readNext();
                while(!isType(xml.name().toString()));
                //qDebug()<<"Element:"<<xml.name() << "Value: "<< xml.text() << "Token: " << xml.tokenString();
                type=xml.name().toString();
                if(type=="string"){
                    value=xml.readElementText();
                }else if(type=="integer"){
                    value=xml.readElementText().toInt();
                }else if(type=="array"){
                    value=readArray(&xml);
                }
                qDebug()<<"Element: "<<key<<" Type: "<<type<< " Value " << value;
            }
      }
    if (xml.hasError()) {
        qDebug()<<"Failed to parse bundle's info.plist in " << bndl.absolutePath() << ". Err:"<< xml.errorString();
            return;
    }

        //TODO
    file.close();
}

