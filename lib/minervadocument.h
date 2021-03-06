#ifndef MINERVADOCUMENT_H
#define MINERVADOCUMENT_H

#include <QObject>
#include <QFile>
#include <QTabWidget>
#include "qcodeedit.h"
#include "qeditor.h"

class MinervaDocument : public QObject
{
Q_OBJECT
public:
    MinervaDocument(QTabWidget *dest, QFile *file=0);
    ~MinervaDocument();

    bool isModified();
    QString getName();
    QEditor* getEditor();
    

signals:
    void textChanged();
public slots:
    void save();
    void saveAs();
    void textModified();
private:
    QWidget *container;
    QCodeEdit *editor;
    QString *title;
    QFile *file;
    QTabWidget *widgetcontainer;
    bool modified;
    void setupEditor();
};

#endif // MINERVADOCUMENT_H
