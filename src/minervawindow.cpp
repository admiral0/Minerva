#include "minervawindow.h"
#include "ui_minervawindow.h"
#include <QtGui>

MinervaWindow::MinervaWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MinervaWindow){
    ui->setupUi(this);
    setCentralWidget(ui->documentTabs);
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(newDocument()));
    connect(ui->action_Open,SIGNAL(triggered()),this,SLOT(openDocument()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->action_Save,SIGNAL(triggered()),this,SLOT(saveDocument()));
    connect(ui->actionSave_As,SIGNAL(triggered()),this,SLOT(saveDocumentAs()));
    connect(ui->actionAbout_Minerva,SIGNAL(triggered()),this,SLOT(about()));
    connect(ui->documentTabs,SIGNAL(tabCloseRequested(int)),this,SLOT(closeDocument(int)));
    formats = new QFormatScheme("qxs/formats.qxf", this);
    QDocument::setDefaultFormatScheme(formats);
    QLineMarksInfoCenter::instance()->loadMarkTypes("qxs/marks.qxm");
    languages = new QLanguageFactory(formats, this);
    languages->addDefinitionPath("qxs");
    editors=new QList<MinervaDocument*>();
    newDocument();


}
MinervaWindow::~MinervaWindow(){
    delete ui;
}


void MinervaWindow::newDocument(){
    MinervaDocument *doc=new MinervaDocument(ui->documentTabs);
    editors->append(doc);
}
void MinervaWindow::openDocument(){
    QString path = QFileDialog::getOpenFileName(this);
    MinervaDocument *doc=new MinervaDocument(ui->documentTabs,new QFile(path));
    languages->setLanguage(doc->getEditor(),path);
    editors->append(doc);
}
void MinervaWindow::saveDocument(){
    editors->at(ui->documentTabs->currentIndex())->save();
}

void MinervaWindow::saveDocumentAs(){
    editors->at(ui->documentTabs->currentIndex())->saveAs();
}
void MinervaWindow::about(){
       QMessageBox::about(this, tr("About Minerva"),
                tr("<b>Minerva</b> is a basic (for now) text editor<br>"
                   "developed using the Qt Framework by Nokia.<br>"
                   "Code is licensed under GPLv3.<br>"
                   "Copyright (c) 2010 Radu Andries"));
}

void MinervaWindow::closeDocument(int nr){
    MinervaDocument *d=editors->at(nr);
    if(d->isModified()){
        QMessageBox msg;
        msg.setWindowTitle(tr("Save Document"));
        msg.setText(tr("Do you want to save %1?").arg(d->getName()));
        msg.setIcon(QMessageBox::Question);
        msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        int r=msg.exec();
        if(r==QMessageBox::Yes)
            d->save();
        else if(r==QMessageBox::Cancel)
            return;

    }
    d=editors->takeAt(nr);
    ui->documentTabs->removeTab(nr);
    //delete d;
}

void MinervaWindow::closeEvent(QCloseEvent *event){
    bool accept=true;
    int size=editors->size();
    for(int i=0;i<size;i++){
        MinervaDocument *d;
        d=editors->at(i);
        if(d->isModified() && accept){
            QMessageBox msg;
            msg.setWindowTitle(tr("Save Document"));
            msg.setText(tr("Do you want to save %1?").arg(d->getName()));
            msg.setIcon(QMessageBox::Question);
            msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
            int r=msg.exec();
            if(r==QMessageBox::Yes)
                d->save();
            else if(r==QMessageBox::Cancel)
                accept=false;
            if(accept){
                editors->takeAt(i);
            }
        }
    }
    if(accept){
        event->accept();
    }else{
        event->ignore();
    }
}
void MinervaWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
