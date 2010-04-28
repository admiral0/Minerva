#include "minervadocument.h"
#include <QFileInfo>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QApplication>
#include <QFileDialog>
#include <QAction>

MinervaDocument::MinervaDocument(QTabWidget *dest, QFile *file){
    modified=false;
   editor= new QCodeEdit(dest);
   setupEditor();

    if(file==0){
        title=new QString(tr("Untitled"));
    }else{
        if(file->open(QIODevice::ReadOnly)){
            QFileInfo *fi=new QFileInfo(*file);
            title=new QString(fi->fileName());
            QApplication::setOverrideCursor(Qt::WaitCursor);
            editor->editor()->load(file->fileName());
            QApplication::restoreOverrideCursor();
            file->close();
	    this->file=file;
        }else{
            QMessageBox *warn;
            warn=new QMessageBox;
            warn->setWindowTitle(tr("Minerva"));
            warn->setText(tr("Cannot open %1").arg(file->fileName()));
            warn->setIcon(QMessageBox::Warning);
            warn->exec();
            return;
        }
    }

    dest->addTab(editor->editor(), *title);
    dest->setCurrentWidget(editor->editor());
    widgetcontainer=dest;
    //connect(editor,SIGNAL(textChanged()),this,SLOT(textModified()));
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
        QApplication::setOverrideCursor(Qt::WaitCursor);
        editor->editor()->save(file->fileName());
        QApplication::restoreOverrideCursor();

}
void MinervaDocument::saveAs(){
    QString newFile=QFileDialog::getSaveFileName();
    QFile file(newFile);
    if(file.open(QIODevice::WriteOnly)){
        this->file=&file;
        QFileInfo fi(file);
        title=new QString(fi.fileName());
        if(this->widgetcontainer!=0){
            widgetcontainer->setTabText(widgetcontainer->currentIndex(),*title);
        }
        QApplication::setOverrideCursor(Qt::WaitCursor);
        editor->editor()->save(file.fileName());
        QApplication::restoreOverrideCursor();
        file.close();
    }else{
        QMessageBox *warn;
        warn=new QMessageBox;
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
void MinervaDocument::setupEditor(){
    editor->addPanel("Line Mark Panel", QCodeEdit::West, true)->setShortcut(QKeySequence("F6"));

    editor->addPanel("Line Number Panel", QCodeEdit::West, true)->setShortcut(QKeySequence("F11"));

    editor->addPanel("Fold Panel", QCodeEdit::West, true)->setShortcut(QKeySequence("F9"));

    editor->addPanel("Line Change Panel", QCodeEdit::West, true);

    editor->addPanel("Status Panel", QCodeEdit::South, true);

    editor->addPanel("Search Replace Panel", QCodeEdit::South);
}
QEditor* MinervaDocument::getEditor(){
    return editor->editor();
}
