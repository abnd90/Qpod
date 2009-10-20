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

enum TypeOfView{LIST,ALBUM,ARTIST,PLAYLIST};

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
    void initwin(void);

private slots:
    void reload();
    void about();
    void action_video_select();
    void Add_Video(const QString&);
    void AddTrack();
    void AddFolder();
    void SetMP();
    void showProperties();
private:
    Ui::MainWindow *ui;
    Itdb_Track* GetTrack(int row,int col);

    void createContextMenu();
    void createActions();

    TypeOfView view;
    QAction *actionProperties;
    PropertiesDialog trackproperties;


};



#endif // MAINWINDOW_H
