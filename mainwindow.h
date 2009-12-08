#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMessageBox>
#include <QPicture>
#include <QFileDialog>
#include <QString>
#include "ipod.h"
#include "videodialog.h"
#include "propertiesdialog.h"
#include "youtube.h"
#include "transferQueue.h"

//#include <audioproperties.h>
//#include <tag.h>
//#include <fileref.h>
//#include <mp4v2/mp4v2.h>
//#include <mpegfile.h>
//#include <attachedpictureframe.h>
//#include <id3v2tag.h>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void initTable();

private slots:
    void reload();
    void about();
    void actionVideoAdd();
    void addFile();
    void addFolder();
    void setMP();
    void showProperties();
    void deleteTrack();
    void addYoutube();
    void searchTracks();
    void searchDone(QString);
    void appendTree(QTreeWidgetItem*);

private:
    Ui::MainWindow *ui;
    Itdb_Track* getTrack(QTreeWidgetItem *);
    void createContextMenu();
    void createActions();
    void createToolbars();
    QString tmp;
    QAction *actionProperties;
    QAction *actionDelete;
    QToolBar *fileToolbar;
    QToolBar *musicToolbar;
    QToolBar *videoToolbar;
    QToolBar *searchToolbar;
    QLineEdit *searchBox;
    PropertiesDialog* propertyDialog;
//    Youtube *yt;
};



#endif // MAINWINDOW_H
