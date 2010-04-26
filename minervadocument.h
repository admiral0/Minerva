#ifndef MINERVADOCUMENT_H
#define MINERVADOCUMENT_H

#include <QObject>
#include <QFile>
#include <QTabWidget>
#include <Qsci/qsciscintilla.h>

class MinervaDocument : public QObject
{
Q_OBJECT
public:
    MinervaDocument(QTabWidget *dest, QFile *file=0);
    MinervaDocument(QWidget *dest, QFile *file=0);
    ~MinervaDocument();

    bool isModified();
    QString getName();

signals:
    void textChanged();
public slots:
    void save();
    void saveAs();
    void textModified();
private:
    QWidget *container;
    QsciScintilla *editor;
    QString *title;
    QFile *file;
    QTabWidget *widgetcontainer;
    bool modified;
};

#endif // MINERVADOCUMENT_H
