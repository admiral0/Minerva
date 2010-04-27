#ifndef MINERVAWINDOW_H
#define MINERVAWINDOW_H

#include <QMainWindow>
#include <QList>
#include "minervadocument.h"
#include "qformatscheme.h"
#include "document/qdocument.h"
#include "qlinemarksinfocenter.h"
#include "qlanguagefactory.h"
class QFile;
namespace Ui {
    class MinervaWindow;
}

class MinervaWindow : public QMainWindow {
    Q_OBJECT
public:
    MinervaWindow(QWidget *parent = 0);
    ~MinervaWindow();

public slots:
    void newDocument();
    void openDocument();
    void saveDocument();
    void saveDocumentAs();
    void about();
    void closeDocument(int nr);
protected:
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);

private:
    QList<MinervaDocument*> *editors;
    Ui::MinervaWindow *ui;
    QFormatScheme *formats;
    QLanguageFactory *languages;


};

#endif // MINERVAWINDOW_H
