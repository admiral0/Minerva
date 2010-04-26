#include "minervadocument.h"
#include <QFileInfo>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QFileDialog>

MinervaDocument::MinervaDocument(QTabWidget *dest, QFile *file){
    modified=false;
    this->editor= new QsciScintilla;
    QWidget *page;
    page=new QWidget;
    if(file==0){
        title=new QString(tr("Untitled"));
    }else{
        if(file->open(QIODevice::ReadOnly)){
            QFileInfo *fi=new QFileInfo(*file);
            title=new QString(fi->fileName());
            QTextStream istr(file);
            QApplication::setOverrideCursor(Qt::WaitCursor);
            editor->setText(istr.readAll());
            QApplication::restoreOverrideCursor();
            file->close();
        }else{
            QMessageBox *warn;
            warn->setWindowTitle(tr("Minerva"));
            warn->setText(tr("Cannot open %1").arg(file->fileName()));
            warn->setIcon(QMessageBox::Warning);
            warn->exec();
            return;
        }
    }

    dest->addTab(page,*title);
    QHBoxLayout *layout;
    layout=new QHBoxLayout();
    layout->addWidget(editor);
    page->setLayout(layout);
    dest->setCurrentWidget(page);
    widgetcontainer=dest;
    connect(editor,SIGNAL(textChanged()),this,SLOT(textModified()));
}
MinervaDocument::MinervaDocument(QWidget *dest, QFile *file){
    modified=false;
    container=0;
    this->editor= new QsciScintilla;
    if(file==0){
        *title=tr("Untitled");
    }else{
        if(file->open(QIODevice::ReadOnly)){
            QFileInfo *fi=new QFileInfo(*file);
            title=new QString(fi->fileName());
            QTextStream istr(file);
            QApplication::setOverrideCursor(Qt::WaitCursor);
            editor->setText(istr.readAll());
            QApplication::restoreOverrideCursor();
            this->file=file;
            file->close();
        }else{
            QMessageBox *warn;
            warn->setWindowTitle(tr("Minerva"));
            warn->setText(tr("Cannot open %1").arg(file->fileName()));
            warn->setIcon(QMessageBox::Warning);
            warn->exec();
            return;
        }
    }
    QHBoxLayout *layout;
    layout=new QHBoxLayout();
    layout->addWidget(editor);
    dest->setLayout(layout);
    connect(editor,SIGNAL(textChanged()),this,SLOT(textModified()));
}
MinervaDocument::~MinervaDocument(){
    delete editor;
    delete container;
    delete file;
    delete title;
}
void MinervaDocument::textModified(){
    emit textChanged();
    modified=true;
}

void MinervaDocument::save(){
    if(this->title==tr("Untitled")){
        saveAs();
        return;
    }
    if(file->open(QIODevice::WriteOnly)){
        QTextStream out(file);
        QApplication::setOverrideCursor(Qt::WaitCursor);
        out << editor->text();
        QApplication::restoreOverrideCursor();
    }else{
        QMessageBox *warn;
        warn->setWindowTitle(tr("Minerva"));
        warn->setText(tr("Cannot save %1").arg(file->fileName()));
        warn->setIcon(QMessageBox::Warning);
        warn->exec();
        return;
    }

}
void MinervaDocument::saveAs(){
    QString newFile=QFileDialog::getSaveFileName();
    QFile file(newFile);
    if(file.open(QIODevice::WriteOnly)){
        this->file=&file;
        QFileInfo fi(file);
        title=&(fi.fileName());
        if(this->widgetcontainer!=0){
            widgetcontainer->setTabText(widgetcontainer->currentIndex(),*title);
        }
        QTextStream out(&file);
        QApplication::setOverrideCursor(Qt::WaitCursor);
        out << editor->text();
        QApplication::restoreOverrideCursor();
        file.close();
    }else{
        QMessageBox *warn;
        warn->setWindowTitle(tr("Minerva"));
        warn->setText(tr("Cannot save %1").arg(file.fileName()));
        warn->setIcon(QMessageBox::Warning);
        warn->exec();
        return;
    }
}

bool MinervaDocument::isModified(){
    return modified;
}

QString MinervaDocument::getName(){
    return *(this->title);
}
