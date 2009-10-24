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
    void AddTrack();
    void AddFolder();
    void SetMP();
    void showProperties();
    void DeleteTrack();
    void addYoutube();

private:
    Ui::MainWindow *ui;
    Itdb_Track* GetTrack(int row,int col);
    void createContextMenu();
    void createActions();
    QString tmp;

    QAction *actionProperties;
    QAction *actionDelete;
    PropertiesDialog trackproperties;


};



#endif // MAINWINDOW_H
